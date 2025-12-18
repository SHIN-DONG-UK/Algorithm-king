#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> aList[100'005];
int subtree_num[100'005];
bool visited[100'005];

void init();
void solve();

int dfs(int now);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> R >> Q;

	int from, to;
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;
		aList[from].push_back(to);
		aList[to].push_back(from);
	}

	visited[R] = true;
	dfs(R);
}

void solve() {
	int num;
	for (int i = 0; i < Q; i++) {
		cin >> num;
		cout << subtree_num[num] << '\n';
	}
}

int dfs(int now) {
	bool flag = false;

	int sum = 0;
	for (auto& num : aList[now]) {
		if (visited[num]) continue;

		flag = true;
		visited[num] = true;
		sum += dfs(num);
	}

	if (!flag) { // 리프 노드
		subtree_num[now] = 1;
		return 1;
	}
	else {
		subtree_num[now] = sum + 1;
		return sum + 1;
	}
}