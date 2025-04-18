#include <iostream>
#define MAX_N 16
using namespace std;

int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };
int N;
int map[MAX_N][MAX_N];
int ans;

void Input();
void Dfs(int y, int x, int dir);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	Input();
	Dfs(0, 1, 0);

	cout << ans << '\n';
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Dfs(int y, int x, int dir) {
	if (y == N - 1 && x == N - 1) {
		ans++;
		return;
	}

	int ny, nx;

	for (int pushNum = 0; pushNum < 3; pushNum++) {
		if (dir == 0 && pushNum == 2)
			continue;
		if (dir == 2 && pushNum == 0)
			continue;

		if (pushNum == 1) {
			// 0,1,2방향 다음칸이 비어있어야 함
			int flag = 0;
			for (int d = 0; d < 3; d++) {
				ny = y + dy[d];
				nx = x + dx[d];

				// 다음 칸이 맵밖이므로 못감
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
					flag = 1;
					break;
				}
				// 다음 칸이 벽이면 못감
				if (map[ny][nx] == 1) {
					flag = 1;
					break;
				}
			}
			// flag==1이면 pushNum==1로 못밈
			if (flag)
				continue;
			// 다음 칸(pushNum==1 방향)으로 이동하고 해당 방향으로 시작
			ny = y + dy[pushNum];
			nx = x + dx[pushNum];
			Dfs(ny, nx, pushNum);
		}
		else {
			// pushNum 방향 다음칸이 비어있어야 함
			ny = y + dy[pushNum];
			nx = x + dx[pushNum];
			// 다음 칸이 맵밖이므로 못감
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			// 다음 칸이 벽이면 못감
			if (map[ny][nx] == 1)
				continue;
			// 다음 칸으로 이동하고 해당 방향으로 시작
			Dfs(ny, nx, pushNum);

		}
	}
}