#define B 1
#define W 2
#include <iostream>
#include <vector>
using namespace std;

// 상 우상 우 우하 하 좌하 좌 좌상
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M;
int map[8][8]; // 4x4 or 6x6 or 8x8

void init_map();
bool check(int y, int x, int dir, int dol);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		init_map(); // init map

		int x, y, dol;
		for (int m = 0; m < M; m++) {
			cin >> x >> y >> dol;

			y--; x--; // 0-based index
			map[y][x] = dol;
			
			for (int d = 0; d < 8; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (map[ny][nx] == 0 || map[ny][nx] == dol) continue;
				if (check(ny, nx, d, dol)) map[ny][nx] = dol;
			}
		}

		int b_cnt = 0;
		int w_cnt = 0;
		// 최종 돌 개수 카운트
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == B) b_cnt++;
				else if (map[i][j] == W) w_cnt++;
			}
		}

		// [output]
		cout << '#' << tc << ' ' << b_cnt << ' ' << w_cnt << '\n';
	}
	return 0;
}

void init_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
	map[N / 2 - 1][N / 2 - 1] = W;
	map[N / 2][N / 2] = W;
	map[N / 2 - 1][N / 2] = B;
	map[N / 2][N / 2 - 1] = B;
}

bool check(int y, int x, int dir, int dol) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny < 0 || ny >= N || nx < 0 || nx >= N) return false;
	if (map[ny][nx] == 0) return false;
	if (map[ny][nx] == dol) return true;

	map[ny][nx] = dol;
	if (check(ny, nx, dir, dol)) return true;
	map[ny][nx] = map[ny][nx] == 1 ? 2 : 1;
	return false;
}