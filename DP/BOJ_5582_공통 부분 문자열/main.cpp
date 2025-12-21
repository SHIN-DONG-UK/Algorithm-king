#include <iostream>
#include <string>
using namespace std;

string A, B;
int dp[4005][4005];
int max_val;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << max_val << '\n';
	return 0;
}

void init() {
	cin >> A;
	cin >> B;
}

void solve() {
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > max_val) max_val = dp[i][j];
			}
		}
	}
}
