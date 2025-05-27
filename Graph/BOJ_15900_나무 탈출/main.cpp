#include <iostream>
#include <vector>
using namespace std;

int N, cnt;
vector<int> graph[500001];
int visited[500001];

void input();
void dfs(int now, int lev);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	visited[1] = -1;
	dfs(1, 0);
	for (int i = 2; i <= N; i++) {
		if (graph[i].size() != 1) continue;
		cnt += visited[i];
	}

	if (cnt % 2 == 1) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}

void input() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void dfs(int now, int lev) {
	for (int& node : graph[now]) {
		if (visited[node] != 0) continue;
		visited[node] = lev + 1;
		dfs(node, lev + 1);
	}
}