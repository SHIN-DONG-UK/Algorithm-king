#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<int> graph[10001];
int visited[10001];
int ans[10001];
int max_val;

void input();
void simulation();
int bfs(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	simulation();
	for (int i = 1; i <= N; i++)
	{
		if (ans[i] == max_val) cout << i << ' ';
	}
	cout << '\n';
}

void input() {
	cin >> N >> M;
	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> to >> from;
		graph[from].push_back(to);
	}
}

void simulation() {
	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));

		ans[i] = bfs(i);
		if (ans[i] > max_val) max_val = ans[i];
	}
}

int bfs(int start) {
	int count = 0;

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	int now, next;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			next = graph[now][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			q.push(next);

			count++;
		}
	}
	return count;
}