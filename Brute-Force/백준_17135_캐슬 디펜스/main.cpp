#include <iostream>
#include <algorithm>

#define MAX_NM 15
#define ARCHER_NUM 3
using namespace std;

int N, M, D;
int original[MAX_NM][MAX_NM];
int map[MAX_NM][MAX_NM];
int next_map[MAX_NM][MAX_NM];

// 방향 배열
// 우상 우하
int dy[3] = { -1,1 };
int dx[3] = { 1,1 };
// 조합
int path[ARCHER_NUM];
int visited[MAX_NM];

// 게임
int monster;
int ans;

void Input();
void Go(int idx, int start);
void PlayGame(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Go(0, 0);

	cout << ans << '\n';
	return 0;
}

void Input() {
	cin >> N >> M >> D;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> original[i][j];
			if (original[i][j])
				monster += 1;
		}
	}
}

void Go(int idx, int start) {
	if (idx == ARCHER_NUM) {
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				map[i][j] = original[i][j];
			}
		}

		PlayGame(monster);
		return;
	}

	for (int i = start; i < M; i++)
	{
		path[idx] = i;
		Go(idx + 1, i + 1);
	}
}

void PlayGame(int num) {
	int score = 0;
	int t = num;
	while(t) {

		// 궁수 턴
		for (int i = 0; i < 3; i++)
		{
			int flag = 0;
			for (int k = 0; k < D; k++)
			{
				if (flag)
					break;

				int y = N - 1;
				int x = path[i] - k;

				if (y >= 0 && y < N && x >= 0 && x < M) {
					if (map[y][x]) {
						next_map[y][x] = 1;
						break;
					}
				}
				
				for (int d = 0; d < 2; d++)
				{
					if (flag)
						break;

					for (int m = 0; m < k; m++)
					{
						y += dy[d];
						x += dx[d];

						if (y < 0 || y >= N || x < 0 || x >= M)
							continue;

						if (map[y][x]) {
							flag = 1;
							next_map[y][x] = 1;
							break;
						}

					}
				}
					
			}
			
		}

		// 원래 맵에 반영
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (next_map[i][j]) {
					map[i][j] = 0;
					t--;
					score++;
					next_map[i][j] = 0;
				}
				
			}
		}

		// 몬스터 턴(적)
		for (int i = N-1; i >= 1 ; i--)
		{
			for (int j = 0; j < M; j++)
			{
				if (i == N - 1) {
					if (map[i][j]) {
						t--;
						map[i][j] = 0;
					}
				}

				map[i][j] = map[i - 1][j];
			}
		}

		for (int j = 0; j < M; j++)
			map[0][j] = 0;
		
	}

	ans = max(ans, score);
}