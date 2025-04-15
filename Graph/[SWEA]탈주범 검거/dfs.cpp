#include <iostream>
#include <cstring>
using namespace std;

struct Point
{
	int y;
	int x;
};

// 상우하좌
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int valid_dir[8][4] =
{  //상우하좌
	{0,0,0,0}, // 0
	{1,1,1,1}, // 1
	{1,0,1,0}, // 2
	{0,1,0,1}, // 3
	{1,1,0,0}, // 4
	{0,1,1,0}, // 5
	{0,0,1,1}, // 6
	{1,0,0,1}  // 7
};

int N, M, R, C, L;
int MAP[50][50];
int visited[50][50];
int ans;

void init();
void input();
void process();
void dfs(Point cp, int time);
void print();

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
}

void init()
{
	ans = 0;
}

void input()
{
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = 1e9;
		}
	}
}

void process()
{
	visited[R][C] = 1;
	dfs({ R,C }, 1);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] >= 1 && visited[i][j] <= L) ans++;
		}
	}
	//print();
}
void dfs(Point cp, int time)
{
	if (time == L)
		return;

	Point np;
	for (int d = 0; d < 4; d++)
	{
		int type = MAP[cp.y][cp.x];
		if (valid_dir[type][d] == 0) 
			continue;

		np = { cp.y + dy[d], cp.x + dx[d] };
		if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) 
			continue;
		type = MAP[np.y][np.x];
		if (valid_dir[type][(d - 2 + 4) % 4] == 0) 
			continue;
		if (MAP[np.y][np.x] == 0) 
			continue;
		if (visited[np.y][np.x] <= visited[cp.y][cp.x] + 1) 
			continue;
		visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
		dfs(np, time + 1);
	}
	
}

void print()
{
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}