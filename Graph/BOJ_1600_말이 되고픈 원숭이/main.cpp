#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int hy[8] = { -2,-1,1,2,2,1,-1,-2 };
int hx[8] = { 1,2,2,1,-1,-2,-2,-1 };

struct Point {
	int y;
	int x;
};

struct Vertex {
	Point p;
	int k;
};

int K;
int W, H;
int board[205][205];
int visited[205][205][32];

void init();
void solve();
void mprint(Point& p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	int ans = 1e9;
	for (int i = 0; i <= K; i++) {
		if (visited[H-1][W-1][i] != 0 && ans > visited[H - 1][W - 1][i])
			ans = visited[H - 1][W - 1][i];
	}
	if (ans == 1e9) cout << "-1\n";
	else cout << ans - 1 << '\n';

	return 0;
}

void init() {
	cin >> K;
	cin >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> board[i][j];
		}
	}
}

void solve() {
	queue<Vertex> Q;
	Q.push({ 0,0,0 });
	visited[0][0][0] = 1;

	Vertex now;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();

		//cout << "현재 K: " << now.k << '\n';
		//mprint(now.p);

		Point next;
		for (int d = 0; d < 4; d++) {
			next = { now.p.y + dy[d], now.p.x + dx[d] };
			if (next.y < 0 || next.y >= H || next.x < 0 || next.x >= W)
				continue;
			if (board[next.y][next.x] == 1)
				continue;
			if (visited[next.y][next.x][now.k] > 0)
				continue;
			visited[next.y][next.x][now.k] = visited[now.p.y][now.p.x][now.k] + 1;
			Q.push({ next, now.k });
		}

		if (now.k < K) {
			for (int d = 0; d < 8; d++) {
				next = { now.p.y + hy[d], now.p.x + hx[d] };
				if (next.y < 0 || next.y >= H || next.x < 0 || next.x >= W)
					continue;
				if (board[next.y][next.x] == 1)
					continue;
				if (visited[next.y][next.x][now.k + 1] > 0)
					continue;
				visited[next.y][next.x][now.k + 1] = visited[now.p.y][now.p.x][now.k] + 1;
				Q.push({ next, now.k + 1 });
			}
		}
	}
}

void mprint(Point& p) {
	cout << '\n';
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == p.y && j == p.x) cout << "* ";
			else cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}