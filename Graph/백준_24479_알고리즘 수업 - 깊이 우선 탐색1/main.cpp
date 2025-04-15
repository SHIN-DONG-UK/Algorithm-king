#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> graph[100001];
int visited[100001];
int cnt;

void input();
void dfs(int now);

int main() {
	input();

	visited[R] = 1;
	cnt++;
	dfs(R);

	for (int i = 1; i <= N; i++)
	{
		cout << visited[i] << '\n';
	}

	return 0;
}

void input() {
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	// 노드는 오름차순으로 방문한다
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
}


void dfs(int now) {
	for (int i = 0; i < graph[now].size(); i++)
	{
		int next = graph[now][i];
		if (visited[next] > 0) continue;

		cnt++;
		visited[next] = cnt;

		dfs(next);
	}
}