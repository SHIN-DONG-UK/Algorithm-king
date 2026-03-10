#define MAX_N 20000
#include <iostream>
using namespace std;

struct Anth {
	int x;
	bool isRemoved;
};

Anth arr[MAX_N + 1];
int lastIdx;

void init();
void build(int p);
void remove(int q);
int recon(int r);

bool check(int bound, int r);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;
	int cmd;
	while (Q--) {
		cin >> cmd;
		if (cmd == 100) {
			init();
		}
		else if (cmd == 200) {
			int p;
			cin >> p;
			build(p);
		}
		else if (cmd == 300) {
			int q;
			cin >> q;
			remove(q);
		}
		else if (cmd == 400) {
			int r;
			cin >> r;
			int rst = recon(r);
			cout << rst << '\n';
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

void init() {
	cin >> lastIdx;
	for (int i = 1; i <= lastIdx; i++) {
		cin >> arr[i].x;
		arr[i].isRemoved = false;
	}
}

void build(int p) {
	arr[++lastIdx].x = p;
	arr[lastIdx].isRemoved = false;
}

void remove(int q) {
	arr[q].isRemoved = true;
}

int recon(int r) {
	int rst = -1;

	int left = 0;
	int right = arr[lastIdx].x;

	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid, r)) {
			right = mid - 1;
			rst = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return rst;
}

bool check(int bound, int r) {
	int start = 0;
	for (int i = 1; i <= lastIdx; i++) {
		if (!arr[i].isRemoved) {
			start = arr[i].x;
			break;
		}
	}

	// 처음 1마리 투입
	r--;
	for (int i = 1; i <= lastIdx; i++) {
		if (arr[i].isRemoved) continue;

		if (arr[i].x - start > bound) {
			start = arr[i].x;
			r--;
			if (r < 0) {
				return false;
			}
		}
	}

	return true;
}