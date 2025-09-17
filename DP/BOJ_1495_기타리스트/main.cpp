#include <iostream>
using namespace std;

const int MX = 50 + 1;


int N, S, M;
int V[MX];
bool dp[MX][1001];

void init();
void solve();
void output();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	output();

	return 0;
}

void init() {
	cin >> N >> S >> M;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	dp[0][S] = true;
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!dp[i - 1][j]) continue;

			if (j + V[i] <= M) dp[i][j + V[i]] = true;
			if (j - V[i] >= 0) dp[i][j - V[i]] = true;
		}
	}
}

void output() {
	for (int j = M; j >= 0; j--) {
		if (dp[N][j]) {
			cout << j << '\n';
			return;
		}
	}
	cout << "-1\n";
	return;
}