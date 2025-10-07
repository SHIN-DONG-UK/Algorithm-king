#include <iostream>
using namespace std;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

int R, C, K;
char board[5][5];
bool visited[5][5];
int ans;

void init();
void go(int y, int x, int dist);
void mprint();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	if (board[R - 1][0] != 'T') {
		board[R - 1][0] = 'a';
		visited[R - 1][0] = true;
		go(R - 1, 0, 1);
		visited[R - 1][0] = false;
		board[R - 1][0] = '.';
	}
	
	
	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> R >> C >> K;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}
}

void go(int y, int x, int dist) {
	if (dist > K) {
		return;
	}

	if (y == 0 && x == C - 1) {
		if (dist == K) {
			ans++;
		}
		//mprint();
		return;
	}

	//mprint();

	int ny, nx;
	for (int d = 0; d < 4; d++) {
		
		ny = y + dy[d];
		nx = x + dx[d];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C) {
			continue;
		}
		if (board[ny][nx] == 'T') {
			continue;
		}
		if (visited[ny][nx]) {
			continue;
		}

		board[ny][nx] = 'a' + dist;
		visited[ny][nx] = true;
		go(ny, nx, dist + 1);
		visited[ny][nx] = false;
		board[ny][nx] = '.';
	}

}

void mprint() {
	cout << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}