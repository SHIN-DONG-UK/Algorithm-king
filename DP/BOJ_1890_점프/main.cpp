#include <iostream>
using namespace std;

using u64 = unsigned long long;

const int MX = 100;

int N;
int arr[MX][MX];
u64 dp[MX][MX];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	solve();

	cout << dp[0][0] << '\n';
	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	dp[N - 1][N - 1] = 1;
}

void solve() {
	for (int y = N - 1; y >= 0; y--) {
		for (int x = N - 1; x >= 0; x--) {
			
			for (int k = 1; k <= 9; k++) {
				int ny = y - k;
				if (ny < 0) break;
				if (arr[ny][x] == k) dp[ny][x] += dp[y][x];
			}
			for (int k = 1; k <= 9; k++) {
				int nx = x - k;
				if (nx < 0) break;
				if (arr[y][nx] == k) dp[y][nx] += dp[y][x];
			}
		}
	}
}