#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
	int lev;
	int prev;
	int idx;
};

char convert_idx_to_com[4] = { 'D', 'S', 'L', 'R' };

int T;
int A, B;
Node visited[10000];
vector<int> ans_v;
int num_list[4];

void Init();
void Input();
int DoCommand(int num, int idx);
void Bfs();
int ShiftL(int num);
int ShiftR(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		Init();

		Input();

		Bfs();

		int cur = B;
		ans_v.push_back(visited[cur].idx);
		cur = visited[cur].prev;

		while (cur != A) {
			ans_v.push_back(visited[cur].idx);
			cur = visited[cur].prev;
		}

		for (int i = ans_v.size() - 1; i >= 0; i--)
			cout << convert_idx_to_com[ans_v[i]];
		cout << '\n';

	}
}

void Input() {
	cin >> A >> B;
}

void Init() {
	memset(visited, 0, sizeof(visited));
	ans_v.clear();
}

int DoCommand(int num, int idx) {
	int rst = num;

	if (idx == 0) {
		rst *= 2;
		return rst % 10000;
	}
	else if (idx == 1) {
		rst -= 1;
		return rst == -1 ? 9999 : rst;
	}
	else if (idx == 2) {
		return ShiftL(num);
	}
	else {
		return ShiftR(num);
	}
}

void Bfs() {
	queue<int> q;
	q.push(A);
	visited[A].prev = A;
	visited[A].lev = 1;

	int cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			next = DoCommand(cur, i);
			if (visited[next].lev > 0)
				continue;
			visited[next].prev = cur;
			visited[next].lev = visited[cur].lev + 1;
			visited[next].idx = i;
			q.push(next);

			if (next == B)
				return;
		}
	}
}

int ShiftL(int num) {
	int rst = num;
	// shift
	for (int i = 0; i < 3; i++) {
		num_list[2 - i] = rst % 10;
		rst /= 10;
	}
	num_list[3] = rst % 10;
	// sum
	rst = num_list[0] * 10 + num_list[1];
	for (int i = 1; i <= 2; i++) {
		rst = rst * 10 + num_list[i + 1];
	}
	return rst;
}

int ShiftR(int num) {
	int rst = num;
	// shift
	num_list[0] = rst % 10;
	rst /= 10;
	for (int i = 0; i < 3; i++) {
		num_list[3 - i] = rst % 10;
		rst /= 10;
	}
	// sum
	rst = num_list[0] * 10 + num_list[1];
	for (int i = 1; i <= 2; i++) {
		rst = rst * 10 + num_list[i + 1];
	}
	return rst;
}