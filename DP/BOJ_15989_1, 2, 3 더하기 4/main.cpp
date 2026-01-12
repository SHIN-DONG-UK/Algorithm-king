#include <iostream>
using namespace std;

int n;
int dp[4][10001];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		solve();
	}
	return 0;
}

void init() {
	cin >> n;
	for (int j = 1; j <= n; j++) {
		dp[1][j] = 1;
	}
	for (int i = 0; i <= 3; i++) {
		dp[i][0] = 1;
	}
}

void solve() {
	for (int i = 2; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - i < 0) continue;

			dp[i][j] += dp[i][j - i];
		}
	}

	cout << dp[3][n] << '\n';
}