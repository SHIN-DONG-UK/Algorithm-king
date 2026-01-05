#include <iostream>
#include <cstring>
using namespace std;

int T;
int N;
int coin[20];
int M;

int dp[10001][20];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();

		cout << dp[M][N - 1] << '\n';
	}
	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	cin >> M;

	memset(dp, 0, sizeof(dp));

	for (int j = 0; j< N; j++) {
		dp[0][j] = 1;
	}
}

void solve() {
	for (int j = 0; j < N; j++) {
		for (int i = 1; i <= M; i++) {
			if (j - 1 >= 0) {
				dp[i][j] += dp[i][j - 1];
			}
			if (i - coin[j] >= 0) {
				dp[i][j] += dp[i - coin[j]][j];
			}
		}
	}
}