#define WHITE 0
#define RED 1
#define BLUE 2
#include <iostream>
using namespace std;

const int MX = 12 + 5;
const int MX_PIECE = 10 + 1;

int dy[5] = { 0,0,0,1,-1 }; //x우좌상하
int dx[5] = { 0,1,-1,0,0 };

struct Piece {
	int id;
	int y, x;
	int dir;
	int idx;
};

int n, k;
int color[MX][MX];
Piece pieces[MX_PIECE];
Piece* state[MX][MX][3]; int pSize[MX][MX];

int cnt;

void init();
void solve();

void rotate_dir(Piece* pt);
void move_WHITE(Piece* pt);
void move_RED(Piece* pt);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	solve();

	cout << cnt << '\n';

	return 0;
}

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> color[i][j];
		}
	}

	int y, x, dir;
	for (int t = 1; t <= k; t++) {
		cin >> y >> x >> dir;
		pieces[t] = { t,y,x,dir,0 };
		state[y][x][pSize[y][x]++] = &pieces[t];
	}

	for (int j = 0; j <= n + 1; j++) {
		color[0][j] = color[n + 1][j] = 2;
	}
	for (int i = 0; i <= n + 1; i++) {
		color[i][0] = color[i][n + 1] = 2;
	}
}

void solve() {
	while (cnt < 1000) {
		for (int t = 1; t <= k; t++) {
			Piece* now = &pieces[t];

			int ny = now->y + dy[now->dir];
			int nx = now->x + dx[now->dir];

			if (color[ny][nx] == WHITE) {
				cout << "현재 칸 : " << now->y << ", " << now->x << '\n';
				cout << "다음 칸 : " << ny << ", " << nx << '\n';
				move_WHITE(now);
			}
			else if (color[ny][nx] == RED) {
				cout << "현재 칸 : " << now->y << ", " << now->x << '\n';
				cout << "다음 칸 : " << ny << ", " << nx << '\n';
				move_RED(now);
			}
			else {
				rotate_dir(now);
				
				ny = now->y + dy[now->dir];
				nx = now->x + dx[now->dir];

				if (color[ny][nx] == WHITE) {
					cout << "현재 칸 : " << now->y << ", " << now->x << '\n';
					cout << "다음 칸 : " << ny << ", " << nx << '\n';
					move_WHITE(now);
				}
				else if (color[ny][nx] == RED) {
					cout << "현재 칸 : " << now->y << ", " << now->x << '\n';
					cout << "다음 칸 : " << ny << ", " << nx << '\n';
					move_RED(now);
				}
			}
		}
		cnt++;
	}
}

void rotate_dir(Piece* pt) {
	if (pt->dir % 2 == 1) {
		pt->dir++;
	}
	else {
		pt->dir--;
	}
}

void move_WHITE(Piece* now) {
	int ny = now->y + dy[now->dir];
	int nx = now->x + dx[now->dir];
	int y = now->y;
	int x = now->x;

	int len = pSize[y][x];

	for (int i = now->idx; i < len; i++) {
		if (pSize[ny][nx] == 3) {
			cnt++;  return;
		}
		Piece* pt = state[y][x][i];
		state[y][x][i] = nullptr;
		state[ny][nx][pSize[ny][nx]] = pt;
		pt->y = ny;
		pt->x = nx;
		pt->idx = pSize[ny][nx]++;
		pSize[y][x]--;
	}
}

void move_RED(Piece* now) {
	int ny = now->y + dy[now->dir];
	int nx = now->x + dx[now->dir];
	int y = now->y;
	int x = now->x;

	int len = pSize[y][x];
	for (int i = len - 1; i >= now->idx; i--) {
		if (pSize[ny][nx] == 3) {
			cnt++;  return;
		}
		Piece* pt = state[y][x][i];
		state[y][x][i] = nullptr;
		state[ny][nx][pSize[ny][nx]] = pt;
		pt->y = ny;
		pt->x = nx;
		pt->idx = pSize[ny][nx]++;
		pSize[y][x]--;
	}
}