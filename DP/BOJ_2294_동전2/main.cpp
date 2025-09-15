#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];
bool visited[100001];
vector<int> coin;

int n, k;


void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	if (dp[k] == 1e9) cout << "-1\n";
	else cout << dp[k] << '\n';

	return 0;
}

void init() {
	cin >> n >> k;

	int value = 0;
	for (int i = 0; i < n; i++) {
		cin >> value;
		if (visited[value]) continue;
		visited[value] = true;
		coin.push_back(value);
	}

	for (int i = 1; i <= k; i++) {
		if (visited[i]) dp[i] = 1;
		else dp[i] = 1e9;
	}
}

void solve() {
	for (int i = 1; i <= k; i++) {

		int mini = 1e9;
		for (auto& co : coin) {
			if (i - co > 0 && mini > dp[i - co])
				mini = dp[i - co];
		}
		
		dp[i] = min(dp[i], mini + 1);
	}
}