#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coins[101];
//int dp[101][10001];
int dp[10001];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	cout << dp[k] << '\n';
	//cout << dp[n][k] << '\n';
	return 0;
}

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coins[i] >= 0) {
				dp[j] += dp[j - coins[i]];
			}
		}
	}
}

//void solve2() {
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= k; j++) {
//			int tmp = 0;
//			if (j - coins[i] >= 0) tmp = dp[i][j - coins[i]];
//			dp[i][j] = dp[i - 1][j] + tmp;
//		}
//	}
//}