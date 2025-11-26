#include <iostream>
#include <algorithm>
using namespace std;

struct Wire {
	int A, B;
};

int N;
Wire wires[105];
int dp[105];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

bool compare(const Wire& a, const Wire& b) {
	return a.A < b.A;
}

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> wires[i].A >> wires[i].B;
	}

	sort(wires + 1, wires + N + 1, compare);
}

void solve() {
	int mmax = 0;

	dp[1] = 1;
	for (int i = 2; i <= N; i++) {
		int large = 0;
		for (int j = 1; j < i; j++) {
			if (wires[j].B < wires[i].B && large < dp[j]) {
				large = dp[j];
			}
		}

		dp[i] = large + 1;

		if (mmax < dp[i])
			mmax = dp[i];
	}

	cout << N - mmax << '\n';
}
