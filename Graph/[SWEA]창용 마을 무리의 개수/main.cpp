#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, M;
vector<int> v[101];
int visited[101];
int group = 1;

void init();
void input();
void process();
void bfs(int st);

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		process();

		cout << "#" << tc << " " << group-1 << '\n';
	}
}

void init()
{
	for (int i = 0; i < 101; i++)
	{
		v[i].clear();
	}
	memset(visited, 0, sizeof(visited));
	group = 1;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

void process()
{
	for (int st = 1; st <= N; st++)
	{
		if (visited[st] == 0)
		{
			bfs(st);
			group++;
		}
	}
}

void bfs(int st)
{
	queue<int> q;
	q.push(st);
	visited[st] = group;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++)
		{
			int p = v[now][i];
			if (visited[p] > 0) continue;
			visited[p] = group;
			q.push(p);
		}
	}
}