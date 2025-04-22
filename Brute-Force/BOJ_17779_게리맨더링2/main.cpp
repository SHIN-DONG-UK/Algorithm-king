#include <iostream>
#include <cstring>

using namespace std;

struct Point
{
	int y;
	int x;
};

// 좌하 우하 우상 좌상
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { -1,1,1,-1 };
int A[21][21];
int visited[21][21];
int scores[6];

int N;
int ans = 1e9;

void Input();
void BruteForce();
void DrawFiveArea(Point std, int d1, int d2);
void GetScore(Point std, int d1, int d2);

int main() {
	Input();
	BruteForce();

	cout << ans << '\n';

	return 0;
}

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}
}

void BruteForce()
{
	int minVal, maxVal, diff;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int d1 = 1; d1 <= N; d1++)
			{
				for (int d2 = 1; d2 <= N; d2++)
				{
					if (i + d1 < 1 || j - d1 < 1)
						continue;
					if (i + d2 > N || j + d2 > N)
						continue;
					if (i + d1 + d2 > N || j - d1 + d2 > N)
						continue;

					DrawFiveArea({i, j}, d1, d2);
					GetScore({ i, j }, d1, d2);
					
					minVal = 1e9;
					maxVal = 0;
					for (int i = 1; i <= 5; i++)
					{
						if (minVal > scores[i])
							minVal = scores[i];
						if (maxVal < scores[i])
							maxVal = scores[i];
					}
					diff = maxVal - minVal;
					if (ans > diff)
						ans = diff;
				}
			}
		}
	}
}

void DrawFiveArea(Point std, int d1, int d2)
{
	memset(scores, 0, sizeof(scores));
	memset(visited, 0, sizeof(visited));
	
	int cnt = min(d1, d2);
	int num = 0;
	Point cp;
	while (num <= cnt)
	{
		cp = { std.y + num, std.x };
		if (visited[cp.y][cp.x] == 0) {
			visited[cp.y][cp.x] = 5;
			scores[5] += A[cp.y][cp.x];
		}
		
		for (int d = 0; d < 4; d++)
		{
			if (d == 0 || d == 2) {
				for (int i = 0; i < d1-num; i++)
				{
					cp.y += dy[d];
					cp.x += dx[d];
					if (visited[cp.y][cp.x] > 0)
						continue;
					visited[cp.y][cp.x] = 5;
					scores[5] += A[cp.y][cp.x];
				}
			}
			else {
				for (int i = 0; i < d2-num; i++)
				{
					cp.y += dy[d];
					cp.x += dx[d];
					if (visited[cp.y][cp.x] > 0)
						continue;
					visited[cp.y][cp.x] = 5;
					scores[5] += A[cp.y][cp.x];
				}
			}
		}
		num++;
	}
}

void GetScore(Point std, int d1, int d2)
{
	// 1번 선거구
	for (int i = 1; i < std.y + d1; i++)
	{
		for (int j = 1; j <= std.x; j++)
		{
			if (visited[i][j] > 0)
				continue;
			// 대각 범위 제한
			if (std.y + std.x <= i + j)
				continue;
			visited[i][j] = 1;
			scores[1] += A[i][j];
		}
	}
	// 2번 선거구
	for (int i = 1; i <= std.y + d2; i++)
	{
		for (int j = std.x + 1; j <= N; j++)
		{
			if (visited[i][j] > 0)
				continue;
			// 대각 범위 제한
			if (std.x - std.y >= j - i)
				continue;
			visited[i][j] = 2;
			scores[2] += A[i][j];
		}
	}
	// 4번 선거구
	for (int i = std.y + d2 + 1; i <= N; i++)
	{
		for (int j = std.x - d1 + d2; j <= N; j++)
		{
			if (visited[i][j] > 0)
				continue;
			// 대각 범위 제한
			if (std.y + std.x + 2 * d2 >= i + j)
				continue;
			visited[i][j] = 4;
			scores[4] += A[i][j];
		}
	}
	// 3번 선거구
	for (int i = std.y + d1; i <= N; i++)
	{
		for (int j = 1; j < std.x - d1 + d2; j++)
		{
			if (visited[i][j] > 0)
				continue;
			// 대각 범위 제한
			if (std.x - std.y - 2 * d1 <= j - i)
				continue;
			visited[i][j] = 3;
			scores[3] += A[i][j];
		}
	}
	
}