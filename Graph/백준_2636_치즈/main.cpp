#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M;
int map[100][100];
int visited[100][100];
int air[100][100];
int flag;

void Input();
int MeltCheese();

int main() {
	int pre_cnt = 0;
	int cnt = 0;
	int turn = 0;

	Input();

	while (true) {
		cnt = MeltCheese();

		if (cnt == 0)
			break;

		pre_cnt = cnt;
		turn++;
	}

	cout << turn << '\n';
	cout << pre_cnt << '\n';
	return 0;
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
}

int MeltCheese() {
	memset(air, 0, sizeof(air));
	memset(visited, 0, sizeof(visited));

	queue<Point> q;
	air[0][0] = 1;
	visited[0][0] = 1;
	q.push({ 0, 0 });

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M)
				continue;

			if (visited[np.y][np.x] == 1)
				continue;
			if (map[np.y][np.x] == 1)
				continue;

			if (map[np.y][np.x] == 0) {
				visited[np.y][np.x] = 1;
				air[np.y][np.x] = 1;
				q.push(np);
			}
		}
	}

	int cnt = 0;
	int ny, nx;
	for (int i = 1; i < N-1; i++)
	{
		for (int j = 1; j < M-1; j++)
		{
			if (map[i][j] == 1) {
				// 치즈 조각 세기
				cnt++;

				for (int d = 0; d < 4; d++)
				{
					ny = i + dy[d];
					nx = j + dx[d];
					if (air[ny][nx] == 1) {
						map[i][j] = 0;
						break;
					}
						
				}
			}
		}
	}

	return cnt;
}