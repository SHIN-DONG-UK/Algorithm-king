#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define MAX 100
using namespace std;

struct Point {
	int y;
	int x;
};

// 좌 하 우
int dy[3] = { 0,1,0 };
int dx[3] = { -1,0,1 };

// 101 x 102 (아래쪽  패딩 + 좌우 패딩)
int map[MAX+1][MAX+2];
int ans;

void Input();
void Simul();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 10; i++)
	{
		cin >> tc;
		Input();
		Simul();

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}

void Input() {
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			cin >> map[i][j];
		}
	}
}

void Simul() {
	Point cp, np;
	for (int j = 1; j <= MAX; j++)
	{
		if (map[0][j]) {
			cp = { 0, j };
			while (true) {
				// 좌 검사
				np = { cp.y + dy[LEFT], cp.x + dx[LEFT] };
				if (map[np.y][np.x] == 1) {
					// 쭉 직진
					while (map[np.y][np.x]) {
						np.y += dy[LEFT];
						np.x += dx[LEFT];
					}
					cp = { np.y - dy[LEFT] + dy[DOWN], np.x - dx[LEFT] + dx[DOWN]};
					continue;
				}
				// 우 검사
				np = { cp.y + dy[RIGHT], cp.x + dx[RIGHT] };
				if (map[np.y][np.x] == 1) {
					// 쭉 직진
					while (map[np.y][np.x]) {
						np.y += dy[RIGHT];
						np.x += dx[RIGHT];
					}
					cp = { np.y - dy[RIGHT] + dy[DOWN], np.x - dx[RIGHT] + dx[DOWN]};
					continue;
				}
				// 아래로 이동
				np = { cp.y + dy[DOWN], cp.x + dx[DOWN] };
				if (map[cp.y][cp.x] == 2 || map[np.y][np.x] == 2) {
					// 정답 출력
					ans = j - 1;
					return;
				}
				else if (map[np.y][np.x] == 1)
					cp = np;
				else
					break;
			
			}
		}
	}
}