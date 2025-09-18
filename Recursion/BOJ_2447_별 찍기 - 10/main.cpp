#include <iostream>
using namespace std;

const int MX = 6561;

int N;
char board[MX][MX];

void draw(int y, int x, int n);
void mprint();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	draw(0, 0, N);
	mprint();

	return 0;
}

void draw(int y, int x, int n) {
	if (n == 3) {
		for (int i = y; i < y + n; i++) {
			for (int j = x; j < x + n; j++) {
				if (i == y + 1 && j == x + 1) continue;
				board[i][j] = '*';
			}
		}
		return;
	}

	for (int i = y; i < y + n; i+=n/3) {
		for (int j = x; j < x + n; j+=n/3) {
			if (i == y + n / 3 && j == x + n / 3) continue;
			draw(i, j, n / 3);
			
		}
	}
}

void mprint() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) cout << ' ';
			else cout << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}