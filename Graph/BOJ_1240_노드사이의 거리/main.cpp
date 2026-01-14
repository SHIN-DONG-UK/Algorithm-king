#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<pair<int, int>> adjList[1001];
vector<pair<int, int>> querys;
bool visited[1001];

void init();
void solve();
int bfs(int start_node, int target_node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> M;
	int from, to, d;
	for (int i = 0; i < N - 1; i++) {
		cin >> from >> to >> d;
		adjList[from].push_back({ to, d });
		adjList[to].push_back({ from, d });
	}
	
	pair<int, int> p;
	for (int i = 0; i < M; i++) {
		cin >> p.first >> p.second;
		querys.push_back(p);
	}
}

void solve() {
	for (auto& p : querys) {
		memset(visited, 0, sizeof(visited));
		cout << bfs(p.first, p.second) << '\n';
	}
}

int bfs(int start_node, int target_node) {
	queue<pair<int, int>> Q;
	Q.push({ start_node, 0 });
	visited[start_node] = true;

	pair<int, int> now;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();

		int nxt_dist = 0;
		for (auto& nxt : adjList[now.first]) {
			if (visited[nxt.first]) continue;
			visited[nxt.first] = true;
			nxt_dist = now.second + nxt.second;
			Q.push({nxt.first, nxt_dist});

			if (nxt.first == target_node) {
				return nxt_dist;
			}
		}
	}
}