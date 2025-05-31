#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<vector<int>> graph;
int visited[100001];
int order;

void dfs(int now);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> M >> R;
	graph.resize(N + 1);
	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	visited[R] = 1;
	order = 2;
	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << visited[i] << '\n';
	}
	return 0;
}

void dfs(int now) {
	for (int& next : graph[now]) {
		if (visited[next] > 0) continue;
		visited[next] = order++;
		dfs(next);
	}
}