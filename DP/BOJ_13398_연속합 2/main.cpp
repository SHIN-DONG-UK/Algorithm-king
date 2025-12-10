#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100005];
int DP[100005][2];

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
		cin >> A[i];
	}
}

void solve() {
	int ans;
	ans = DP[1][0] = DP[1][1] = A[1];
	for (int i = 2; i <= N; i++) {
		DP[i][0] = max(DP[i - 1][0] + A[i], A[i]);
		DP[i][1] = max(DP[i - 1][1] + A[i], DP[i - 1][0]);
		ans = max({ DP[i][0], DP[i][1], ans });
	}

	cout << ans << '\n';
}