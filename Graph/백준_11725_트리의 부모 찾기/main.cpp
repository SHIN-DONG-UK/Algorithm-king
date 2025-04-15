#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<int> graph[100001];
int visited[100001];

void input();
void bfs();

int main() {
	input();
	bfs();
	for (int i = 2; i <= N; i++)
	{
		cout << visited[i] << '\n';
	}
}

void input() {
	cin >> N;
	int from, to;
	for (int i = 0; i < N-1; i++)
	{
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
			if (visited[next] > 0) continue;
			visited[next] = now;
			q.push(next);
		}
	}
}