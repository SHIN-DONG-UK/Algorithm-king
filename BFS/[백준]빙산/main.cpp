#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
int MAP[76][76];
int SAVE[76][76];
int visited[76][76];
int ans;

void input();
void process();
void simulation();
void bfs(Point sp);
void output();

int main()
{
	input();
	process();
	cout << ans << '\n';
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void process()
{
	simulation();
}

void simulation()
{
	//output();

	int year = 0;
	while (1)
	{
		// Step 1. 줄어들 수명 체크하기
		// warning. 한 번에 반영해야 함 -> SAVE 배열에 기록
		memset(SAVE, 0, sizeof(SAVE));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (MAP[i][j] == 0) continue;

				int nx, ny;
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					ny = i + dy[d];
					nx = j + dx[d];
					if (MAP[ny][nx] == 0) cnt++;
				}
				SAVE[i][j] = cnt;

			}
		}

		// Step 2. 수명 줄이기
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (SAVE[i][j] > 0)
				{
					MAP[i][j] -= SAVE[i][j];
					if (MAP[i][j] < 0) MAP[i][j] = 0;
				}
			}
		}

		// Step 3-1. 배터리가 두 덩어리 이상으로 분리되었는지 검사
		memset(visited, 0, sizeof(visited));
		int flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (MAP[i][j] > 0)
				{
					flag = 1;
					bfs({ i,j });
					break;
				}

			}
			if (flag == 1)
				break;
		}

		flag = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (MAP[i][j] > 0 && visited[i][j] == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 1) break;
		}

		year++;

		if (flag == 1)
		{
			ans = year;
			break;
		}
		else
		{
			// Step 3-2. 두 덩어리로 분리되지 않았지만 모든 셀의 수명이 다했는지 검사
			int flag = 1;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (MAP[i][j] != 0)
					{
						flag = 0;
						break;
					}
				}
				if (flag == 0) break;
			}
			if (flag == 1)
			{
				ans = 0;
				break;
			}
		}



	}


}

void bfs(Point sp)
{
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!q.empty())
	{
		cp = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (MAP[np.y][np.x] == 0)
				continue;
			if (visited[np.y][np.x] == 1)
				continue;
			visited[np.y][np.x] = 1;
			q.push(np);
		}
	}
}
void output()
{
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << MAP[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}