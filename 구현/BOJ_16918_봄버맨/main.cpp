#include <iostream>
using namespace std;

const int MX = 200;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C, N;
char arr[MX + 1][MX + 1];
bool visited[MX + 1][MX + 1];
bool visited2[MX + 1][MX + 1];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'O') {
				visited[i][j] = true;
				int ny, nx;
				for (int d = 0; d < 4; d++) {
					ny = i + dy[d];
					nx = j + dx[d];
					if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
					visited[ny][nx] = true;
				}
			}
		}
	}
}

void solve() {
	if (N == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << arr[i][j];
				
			}
			cout << '\n';
		}
		cout << '\n';
	}
	else if (N % 2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				cout << 'O';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	else if (N % 4 == 3) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (visited[i][j]) cout << '.';
				else cout << 'O';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	else if (N % 4 == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (!visited[i][j]) {
					visited2[i][j] = true;
					int ny, nx;
					for (int d = 0; d < 4; d++) {
						ny = i + dy[d];
						nx = j + dx[d];
						if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
						visited2[ny][nx] = true;
					}
				}
			}
		}
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (visited2[i][j]) cout << '.';
				else cout << 'O';
			}
			cout << '\n';
		}
		cout << '\n';
	}
}