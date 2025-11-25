#include <iostream>
using namespace std;

int T;
int N, M;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();
	}
	return 0;
}

void init() {
	cin >> N >> M;
}

void solve() {
	long long rst = 1;

	for (int t = 1; t <= N; t++) {
		rst *= (M - t + 1);
		rst /= t;
	}

	cout << rst << '\n';
}