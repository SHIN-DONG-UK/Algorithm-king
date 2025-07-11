#include <iostream>
#include <vector>
using namespace std;

int N, M;
int dp[41];
vector<int> cnts;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= 40; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	cin >> N; cin >> M;
	int s = 0; int e = 0;
	for (int i = 0; i < M; i++) {
		cin >> e;
		cnts.push_back(e - s - 1);
		s = e;
	}
	cnts.push_back(N - s);

	int ans = 1;
	for (auto& c : cnts) {
		if (c == 0) continue;
		ans *= dp[c];
	}

	cout << ans << '\n';
	return 0;
}