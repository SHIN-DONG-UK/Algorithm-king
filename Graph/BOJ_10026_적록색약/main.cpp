#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point
{
	int y;
	int x;
};

int N;
char MAP[100][100];
int visited[100][100];
int ans;
int ans2;

void process();
void bfs(Point st, int flag);

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}

	process();
	cout << ans << ' ' << ans2 << '\n';

}

void process()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != 0) continue;
			bfs({ i, j }, 0);
			ans++;
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] != 0) continue;
			bfs({ i, j }, 1);
			ans2++;
		}
	}

}

void bfs(Point st, int flag)
{

	queue<Point> q;
	q.push(st);
	visited[st.y][st.x] = 1;

	while (!q.empty())
	{
		Point now = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int ny = now.y + dy[d];
			int nx = now.x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (visited[ny][nx] == 1) continue;
			if (flag == 1)
			{
				if (MAP[st.y][st.x] == 'R' || MAP[st.y][st.x] == 'G')
				{
					if (MAP[ny][nx] == 'B') continue;
				}
				else
				{
					if (MAP[ny][nx] == 'R' || MAP[ny][nx] == 'G') continue;
				}

			}
			else
			{
				if (MAP[ny][nx] != MAP[st.y][st.x]) continue;
			}

			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

}