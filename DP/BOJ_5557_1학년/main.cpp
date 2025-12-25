#include <iostream>
using namespace std;

int N;
int arr[101];
long long dp[101][21];

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
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	
	dp[1][arr[1]] = 1;

	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i - 1][j] == 0) continue;

			int tmp = j + arr[i];

			if (tmp <= 20) dp[i][tmp] += dp[i - 1][j];

			tmp = j - arr[i];

			if (tmp >= 0) dp[i][tmp] += dp[i - 1][j];
		}
	}

	cout << dp[N - 1][arr[N]] << '\n';
}