#include <iostream>
using namespace std;

bool board[105][105];

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	int x, y;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;

		for (int i = y; i < y + 10; i++) {
			for (int j = x; j < x + 10; j++) {
				board[i][j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (board[i][j]) ans++;
		}
	}
	
	cout << ans << '\n';

	return 0;
}