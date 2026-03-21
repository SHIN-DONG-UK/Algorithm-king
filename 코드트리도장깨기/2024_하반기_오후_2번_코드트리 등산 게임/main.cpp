#define MAX_H 1000000
#define MAX_N 550000

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Obj {
	int val;
	int h;
};

int arr[MAX_N + 1]; int len;
Obj dp[MAX_N + 1];
int ori[MAX_H];
Obj seg[MAX_H * 4];
map<int, vector<Obj>> treeMap;

Obj query(int index, int s, int e, int ts, int te);
Obj update(int index, int s, int e, int key, Obj value);

void big_bang(int n);
void add(int h);
void remove();
int simulation(int m);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;
	while (Q--) {
		int cmd;
		cin >> cmd;
		if (cmd == 100) {
			int n;
			cin >> n;
			big_bang(n);
			len = n;
		}
		else if (cmd == 200) {
			int h;
			cin >> h;
			add(h);
		}
		else if (cmd == 300) {
			remove();
		}
		else if (cmd == 400) {
			int m;
			cin >> m;
			int rst = simulation(m);
			cout << rst << '\n';
		}
		else {
			cout << "Error!\n";
		}
	}
	return 0;
}

// idx = Segment Tree 상 위치
// s, e = ori 상 범위
Obj query(int index, int s, int e, int ts, int te){
	// 완벽하게 안에 들어오면 더 들어가지 않고 리턴
	if (ts <= s && e <= te) {
		return seg[index];
	}

	// 범위를 완벽히 벗어나면 더 이상 내려가지 않고 리턴
	if (te < s || e < ts) {
		return {0, 0};
	}

	int mid = (s + e) / 2;
	Obj left = query(index * 2, s, mid, ts, te);
	Obj right = query(index * 2 + 1, mid + 1, e, ts, te);

	if (left.val == right.val) {
		return left.h > right.h ? left : right;
	}
	return left.val > right.val ? left : right;
}

Obj update(int index, int s, int e, int key, Obj value) {
	if (s == key && e == key) {
		ori[key] = value.val;
		seg[index] = value;
		return seg[index];
	}

	// key값이 현재 범위에 없으면, 더 이상 내려가지 않고 리턴
	if (key < s || e < key) {
		return seg[index];
	}

	int mid = (s + e) / 2;
	Obj left = update(index * 2, s, mid, key, value);
	Obj right = update(index * 2 + 1, mid + 1, e, key, value);

	if (left.val == right.val) {
		seg[index] = left.h > right.h ? left : right;
	}
	else {
		seg[index] = left.val > right.val ? left : right;
	}
	return seg[index];
}

void big_bang(int n) {
	int h;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		arr[i] = h;
		Obj q = query(1, 1, MAX_H, 1, h - 1);
		dp[i] = { q.val + 1, h };
		treeMap[h].push_back(dp[i]);
		update(1, 1, MAX_H, h, dp[i]);
	}
}

void add(int h) {
	arr[++len] = h;
	Obj q = query(1, 1, MAX_H, 1, h - 1);
	dp[len] = { q.val + 1, h };
	treeMap[h].push_back(dp[len]);
	update(1, 1, MAX_H, h, dp[len]);
}

void remove() {
	int last_mountain_height = arr[len];
	// for debug
	arr[len--] = 0;
	// 현재값을 stack에서 빼고 이전값을 얻는다.
	treeMap[last_mountain_height].pop_back();

	if (treeMap[last_mountain_height].size() > 0) {
		// 이전 높이 값으로 되돌리기
		update(1, 1, MAX_H, last_mountain_height, treeMap[last_mountain_height].back());
	}
	else {
		// 아예 사라졌으면, seg에 0으로 업데이트하여 이후의 값에 영향없도록 하기
		update(1, 1, MAX_H, last_mountain_height, {0,0});
	}
}

int simulation(int m) {
	Obj q = query(1, 1, MAX_H, 1, MAX_H);
	long long rst = (dp[m].val + q.val - 1) * 1000000LL + q.h;
	return rst;
}