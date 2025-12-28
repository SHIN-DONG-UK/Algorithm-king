#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

int N, M, T;
int board[101][101];
int visited[101][101];
int gram_time;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	init();
	solve();

	if (visited[N][M] == 0) {
		if (gram_time - 1 > T) {
			cout << "Fail\n";
		}
		else {
			cout << gram_time - 1 << '\n';
		}
	}
	else {
		int candi = min(visited[N][M], gram_time) - 1;
		if (candi > T) {
			cout << "Fail\n";
		}
		else {
			cout << candi << '\n';
		}
	}
	return 0;
}

void init() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
		}
	}

	gram_time = 10005;
}

void solve() {
	queue<Point> Q;
	Q.push({ 1,1 });
	visited[1][1] = 1;

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y <= 0 || np.y > N || np.x <= 0 || np.x > M) 
				continue;

			if (board[np.y][np.x] == 1) 
				continue;
			if (visited[np.y][np.x] > 0)
				continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			Q.push(np);

			if (board[np.y][np.x] == 2) {
				gram_time = visited[np.y][np.x] + abs(np.y - N) + abs(np.x - M);
			}
		}
	}
}