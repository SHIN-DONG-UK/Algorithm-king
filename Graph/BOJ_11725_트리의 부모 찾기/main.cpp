#define MAX_NUM 100000
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> alist;
int par[MAX_NUM + 1];
bool visited[MAX_NUM + 1];

void bfs();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	alist.resize(N + 1);

	int from, to;
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to;
		alist[from].push_back(to);
		alist[to].push_back(from);
	}

	bfs();

	for (int i = 2; i <= N; i++)
		cout << par[i] << '\n';

	return 0;
}

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	int cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int& next : alist[cur]) {
			if (visited[next]) continue;
			visited[next] = 1;
			q.push(next);

			par[next] = cur;
		}
	}
}