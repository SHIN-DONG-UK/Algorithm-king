#include <iostream>
using namespace std;

int T;
long long arr[65][11];

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
	cin >> T;

	for (int j = 1; j <= 10; j++) {
		arr[1][j] = j;
	}

	for (int i = 2; i <= 64; i++) {
		for (int j = 1; j <= 10; j++) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
}

void solve() {
	int n = 0;
	while (T--) {
		cin >> n;
		cout << arr[n][10] << '\n';
	}
}