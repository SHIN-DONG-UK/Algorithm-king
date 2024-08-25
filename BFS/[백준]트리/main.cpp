#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> tree[50];
int visited[50];
int deleted;
int ans;

void input();
void bfs(int cur);
void process();

int main(void) 
{
	input();
	process();

	cout << ans << '\n';
	return 0;
}

void input()
{
	cin >> N;
	for (int child = 0; child < N; child++)
	{
		int parent;
		cin >> parent;
		if (parent == -1) continue;
		tree[parent].push_back(child);
	}
	cin >> deleted;
}

void process()
{
	bfs(deleted);

	for (int parent = 0; parent < N; parent++)
	{
		if (visited[parent] == 1) continue;

		int cnt = 0;
		for (int child = 0; child < tree[parent].size(); child++)
		{
			int node = tree[parent][child];
			if (visited[node] == 0) cnt++;
		}
		if (cnt == 0) ans++;
		
	}
}

void bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	visited[cur] = 1;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < tree[now].size(); i++)
		{
			int next = tree[now][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			q.push(next);
		}
	}
}