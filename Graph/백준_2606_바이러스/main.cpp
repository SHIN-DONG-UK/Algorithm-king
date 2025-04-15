#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[101];
int visited[101];
int ans;

void input();
void bfs();

int main() {
	input();
	bfs();
	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	int now, next;
	while (!q.empty()) {
		now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			next = graph[now][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			ans++;
			q.push(next);
		}
	}
}