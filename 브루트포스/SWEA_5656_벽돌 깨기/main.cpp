#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_W 12
#define MAX_H 15
#define DOWN 1
using namespace std;

struct Point {
	int y;
	int x;
	int num;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, W, H;
int map[MAX_H + 1][MAX_W];
int tmp_map[MAX_H + 1][MAX_W];
int ans = 1e9;

// 중복 순열
int order[4];

void Init();
void Input();
void Go(int lev);
void CrashBlock(Point sp);
void GoDown();

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
		Go(0);

		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}

void Init() {
	ans = 1e9;
}

void Input() {
	cin >> N >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			cin >> map[i][j];
	}

	for (int j = 0; j < W; j++)
		map[H][j] = 77;
}

void Go(int lev) {
	if (lev == N) {
		/*
		for (int i = 0; i <= H; i++) {
			for (int j = 0; j < W; j++)
				tmp_map[i][j] = map[i][j];
		}*/
		memcpy(tmp_map, map, sizeof(tmp_map));

		for (int j = 0; j < N; j++) {
			for (int i = 0; i < H; i++) {
				if (tmp_map[i][order[j]] > 0) {
					CrashBlock({ i, order[j], tmp_map[i][order[j]]});
					break;
				}
			}
		}

		int tmp = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (tmp_map[i][j] > 0)
					tmp++;
			}
		}

		if (ans > tmp) {
			ans = tmp;
		}
		
		return;
	}

	for (int i = 0; i < W; i++) {
		order[lev] = i;
		Go(lev + 1);
	}
}

void CrashBlock(Point sp) {
	queue<Point> q;
	q.push(sp);
	tmp_map[sp.y][sp.x] = 0;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			for (int k = 1; k < cp.num; k++)
			{
				np = { cp.y + dy[d] * k, cp.x + dx[d] * k, tmp_map[cp.y + dy[d] * k][cp.x + dx[d] * k]};
				if (np.y < 0 || np.y >= H || np.x < 0 || np.x >= W)
					break;
				if (tmp_map[np.y][np.x] == 0)
					continue;
				else if (tmp_map[np.y][np.x] == 1)
					tmp_map[np.y][np.x] = 0;
				else {
					q.push(np);
					tmp_map[np.y][np.x] = 0;
				}
					
			}
		}
	}

	GoDown();
}

void GoDown() {
	Point np;
	for (int j = 0; j < W; j++)
	{
		for (int i = H-2; i >= 0; i--)
		{
			np = { i + dy[DOWN], j + dx[DOWN] };
			if (tmp_map[i][j] > 0 && tmp_map[np.y][np.x] == 0) {
				while (!tmp_map[np.y][np.x]) {
					np.y += dy[DOWN];
					np.x += dx[DOWN];
				}
				tmp_map[np.y - dy[DOWN]][np.x - dx[DOWN]] = tmp_map[i][j];
				tmp_map[i][j] = 0;
			}
		}
	}
}