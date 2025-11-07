#include <iostream>
using namespace std;

int T, n;
int dp[45];
int buff[45];

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
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i < 45; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
}

void solve() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;

		int cnt = 0;
		for (int j = 44; j >= 1; j--) {
			if (dp[j] <= n) {
				buff[++cnt] = dp[j];
				n -= dp[j];
			}

			if (n == 0) {
				break;
			}
		}

		for (int k = cnt; k >= 1; k--) {
			cout << buff[k] << ' ';
		}
		cout << '\n';
	}
}