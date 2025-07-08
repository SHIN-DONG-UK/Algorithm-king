#include <iostream>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

int ay[4][10] = {
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{0,1,0,-1,2,1,0,-1,0,1},
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{0,-1,0,1,-2,-1,0,1,0,-1}
};

int ax[4][10] = {
	{0,-1,0,1,-2,-1,0,1,0,-1},
	{-2,-1,-1,-1,0,1,1,1,2,0},
	{0,1,0,-1,2,1,0,-1,0,1},
	{-2,-1,-1,-1,0,1,1,1,2,0}
};

int percent[9] = { 2,10,7,1,5,10,7,1,2 };

int N;
int map[500][500];
int cur_y, cur_x, dir;
int gAns;

void input();
void solve();
void spread(int y, int x, int d);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();

	solve();

	cout << gAns << '\n';
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)	{
			cin >> map[i][j];
		}
	}
	//init
	cur_y = cur_x = N / 2;
	dir = 0;
}

void solve() {
	int k = 1; //dir 유지 횟수
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				cur_y += dy[dir]; cur_x += dx[dir];

				if (cur_x == -1) return;

				spread(cur_y, cur_x, dir);
			}
			dir = (dir + 1) % 4;
		}
		k++;
	}
}

void spread(int y, int x, int d) {
	int total = map[y][x];
	int sum = 0;

	int ny, nx, diff;
	for (int c = 0; c < 9; c++) {
		ny = y + ay[d][c]; nx = x + ax[d][c];
		diff = (total * percent[c]) / 100;
		sum += diff;
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) gAns += diff;
		else map[ny][nx] += diff;
	}
	// alpha 결정
	ny = y + ay[d][9]; nx = x + ax[d][9];
	diff = total - sum;
	if (ny < 0 || ny >= N || nx < 0 || nx >= N) gAns += diff;
	else map[ny][nx] += diff;

	map[y][x] = 0; //다 날아감
}