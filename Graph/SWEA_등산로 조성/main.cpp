#include <iostream>
using namespace std;

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, K;
int MAP[8][8];
int visited[8][8];
Point highest[5];
int len_highest;
int ans;

void init();
void input();
void process();
void dfs(Point cp, int pre, int cnt, int flag);
void get_max();
void print(Point cp);

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		process();

		cout << "#" << tc << " " << ans << '\n';
	}
	return 0;
}

void init()
{
	ans = 0;
	len_highest = 0;
}

void input()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
		}
	}
	get_max();
}

void process()
{
	for (int i = 0; i < len_highest; i++)
	{
		visited[highest[i].y][highest[i].x] = 1;
		dfs(highest[i], MAP[highest[i].y][highest[i].x], 1, 0);
		visited[highest[i].y][highest[i].x] = 0;
	}
}

void get_max()
{
	int max_val = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] > max_val) max_val = MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (MAP[i][j] == max_val)
			{
				highest[len_highest] = { i,j };
				len_highest++;
			}
		}
	}
}

void dfs(Point cp, int pre, int cnt, int flag)
{
	if (cnt > ans) ans = cnt;
	//print(cp);

	for (int d = 0; d < 4; d++)
	{
		int ny = cp.y + dy[d];
		int nx = cp.x + dx[d];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (visited[ny][nx] == 1) continue;
		if (flag == 0)
		{
			for (int k = 1; k <= K; k++)
			{
				if (MAP[ny][nx] - k >= pre) continue;
				visited[ny][nx] = 1;
				dfs({ ny,nx }, MAP[ny][nx] - k, cnt + 1, 1);
				visited[ny][nx] = 0;
			}
			
		}
		if (MAP[ny][nx] >= pre) continue;
		visited[ny][nx] = 1;
		dfs({ ny,nx }, MAP[ny][nx], cnt + 1, flag);
		visited[ny][nx] = 0;

	}
}

void print(Point cp)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i == cp.y && j == cp.x) cout << "@ ";
			else cout << MAP[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}