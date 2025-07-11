#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int costs[100000][3];
int dp[100000][3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tc = 1;
	
	int N;
	while (1) {
		cin >> N;
		memset(dp, 0, 12 * N);
		if (N == 0) break;
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> costs[i][j];
			}
		}

		bool flag = false;
		dp[0][0] = 1e9;
		dp[0][1] = costs[0][1];
		dp[0][2] = costs[0][1] + costs[0][2];
		dp[1][0] = costs[0][1] + costs[1][0];
		dp[1][1] = min({ dp[1][0], dp[0][1], dp[0][2] }) + costs[1][1];
		dp[1][2] = min({ dp[1][1], dp[0][1], dp[0][2] }) + costs[1][2];

		for (int i = 2; i < N; i++) {
			dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][0];
			dp[i][1] = min({ dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] }) + costs[i][1];
			dp[i][2] = min({ dp[i][1], dp[i - 1][1], dp[i - 1][2] }) + costs[i][2];
		}

		cout << tc << '.' << ' ' <<  dp[N-1][1] << '\n';
		tc++;
	}
	return 0;
}