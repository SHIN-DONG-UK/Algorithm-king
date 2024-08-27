
#include <iostream>
#include <vector>
using namespace std;


struct Point
{
	int y;
	int x;
};

// 우 상 좌 하
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };


int N, M;
int MAP[1002][1002];
vector<int> ans;

void init();
void input();
void process();
void output();
// 입력방향 to 반사방향
int get_direction(int dir);

int main()
{
	input();
	init();
	process();
	output();
}

void init()
{
	int num = 1;
	for (int i = 1; i <= N; i++)
	{
		MAP[i][0] = num;
		num++;
	}
	for (int i = 1; i <= M; i++)
	{
		MAP[N+1][i] = num;
		num++;
	}
	for (int i = N; i >= 1; i--)
	{
		MAP[i][M+1] = num;
		num++;
	}
	for (int i = M; i >= 1; i--)
	{
		MAP[0][i] = num;
		num++;
	}
}

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void process()
{
	// 왼쪽라인
	int dir = 0;
	Point cp;
	for (int i = 1; i <= N; i++)
	{
		dir = 0;
		cp = { i, 1 };
		while (1)
		{
			if (cp.y < 1 || cp.y >= N+1 || cp.x < 1 || cp.x >= M+1)
			{
				ans.push_back(MAP[cp.y][cp.x]);
				break;
			}
			if (MAP[cp.y][cp.x] == 1) dir = get_direction(dir);
			cp.y += dy[dir];
			cp.x += dx[dir];
		}
		
	}
	
	// 아래쪽라인
	for (int i = 1; i <= M; i++)
	{
		dir = 1;
		cp = { N, i };
		while (1)
		{
			if (cp.y < 1 || cp.y >= N + 1 || cp.x < 1 || cp.x >= M + 1)
			{
				ans.push_back(MAP[cp.y][cp.x]);
				break;
			}
			if (MAP[cp.y][cp.x] == 1) dir = get_direction(dir);
			cp.y += dy[dir];
			cp.x += dx[dir];
		}
	}
	
	// 오른쪽 라인
	for (int i = N; i >= 1; i--)
	{
		dir = 2;
		cp = { i, M };
		while (1)
		{
			if (cp.y < 1 || cp.y >= N + 1 || cp.x < 1 || cp.x >= M + 1)
			{
				ans.push_back(MAP[cp.y][cp.x]);
				break;
			}
			if (MAP[cp.y][cp.x] == 1) dir = get_direction(dir);
			cp.y += dy[dir];
			cp.x += dx[dir];
		}
	}
	// 위쪽 라인
	for (int i = M; i >= 1; i--)
	{
		dir = 3;
		cp = { 1, i };
		while (1)
		{
			if (cp.y < 1 || cp.y >= N + 1 || cp.x < 1 || cp.x >= M + 1)
			{
				ans.push_back(MAP[cp.y][cp.x]);
				break;
			}
			if (MAP[cp.y][cp.x] == 1) dir = get_direction(dir);
			cp.y += dy[dir];
			cp.x += dx[dir];
		}
	}
}

int get_direction(int dir)
{
	if (dir == 0) return 1;
	else if (dir == 1) return 0;
	else if (dir == 2) return 3;
	else if (dir == 3) return 2;
	else return -1;
}

void output()
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
}