#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 501
using namespace std;

struct Point {
	int y;
	int x;
};

// 상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M, K;
int map[MAX][MAX];
int next_map[MAX][MAX];
int active_map[MAX][MAX];
int ans;

Point left_top_min;
Point right_bottom_max;

Point left_top;
Point right_bottom;

void Init();
void Input();
void Simul();
void GetAnswer();
void Print();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Init();
		Input();
		Simul();
		GetAnswer();
		cout << '#' << tc << ' ' << ans << '\n';
	}
	

	return 0;

}

void Init() {
	memset(next_map, 0, sizeof(next_map));
	memset(map, 0, sizeof(map));
	memset(active_map, 0, sizeof(active_map));
	ans = 0;
}

void Input() {
	cin >> N >> M >> K;

	left_top = { 250 - N / 2, 250 - M / 2 };
	if (N % 2 == 1)
		right_bottom.y = 250 + N / 2;
	else
		right_bottom.y = 250 + N / 2 - 1;
	if (M % 2 == 1)
		right_bottom.x = 250 + M / 2;
	else
		right_bottom.x = 250 + M / 2 - 1;

	left_top_min = left_top;
	right_bottom_max = right_bottom;

	for (int i = left_top.y; i <= right_bottom.y; i++)
	{
		for (int j = left_top.x; j <= right_bottom.x; j++)
		{
			cin >> map[i][j];
		}
	}

}

void Simul() {
	int t = 0;
	while (t < K) {
		for (int i = left_top.y; i <= right_bottom.y; i++)
		{
			for (int j = left_top.x; j <= right_bottom.x; j++)
			{
				int ny, nx;
				// 번식 진행
				if (map[i][j] > 0  && active_map[i][j] != -1 && t - active_map[i][j] >= map[i][j] && t - active_map[i][j] < map[i][j] * 2) {
					for (int d = 0; d < 4; d++)
					{
						ny = i + dy[d];
						nx = j + dx[d];
						// 번식을 하기 위해 해당 칸이 번식할 수 있는 곳인지 확인하고, 
						// 가장 큰 생명력을 가진 줄기 세포가 번식해야 함
						if (map[ny][nx] == 0) {
							if (map[i][j] > next_map[ny][nx]) {
								next_map[ny][nx] = map[i][j];
								left_top_min.y = min(ny, left_top_min.y);
								left_top_min.x = min(nx, left_top_min.x);
								right_bottom_max.y = max(ny, right_bottom_max.y);
								right_bottom_max.x = max(nx, right_bottom_max.x);
							}
							
						}


					}
				}

			}
		}

		// 좌표 업데이트
		left_top = left_top_min;
		right_bottom = right_bottom_max;

		// 번식 확정
		for (int i = left_top.y; i <= right_bottom.y; i++)
		{
			for (int j = left_top.x; j <= right_bottom.x; j++)
			{
				if (next_map[i][j] > 0) {
					map[i][j] = next_map[i][j];
					active_map[i][j] = t + 1;
					next_map[i][j] = 0;

				}
				
			}
		}

		t++;
		
		// 세포 죽음
		for (int i = left_top.y; i <= right_bottom.y; i++)
		{
			for (int j = left_top.x; j <= right_bottom.x; j++)
			{
				if (active_map[i][j] == -1)
					continue;
				if (t - active_map[i][j] == map[i][j] * 2)
					active_map[i][j] = -1;

			}
		}
		//Print();
		
	}
}

void Print() {
	for (int i = left_top.y; i <= right_bottom.y; i++)
	{
		for (int j = left_top.x; j <= right_bottom.x; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	cout << '\n';
	for (int i = left_top.y; i <= right_bottom.y; i++)
	{
		for (int j = left_top.x; j <= right_bottom.x; j++)
		{
			cout << active_map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void GetAnswer() {
	for (int i = left_top.y; i <= right_bottom.y; i++)
	{
		for (int j = left_top.x; j <= right_bottom.x; j++)
		{
			if (active_map[i][j] > 0)
				ans++;
		}
	}
}