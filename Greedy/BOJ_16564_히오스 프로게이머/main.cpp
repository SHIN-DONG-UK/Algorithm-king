#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[1000005];
int ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans << '\n';
	return 0;
}

void init() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + N + 1);
}

void solve() {
	int now = 0;
	for (int i = 1; i <= N - 1; i++) {
		now = i * (arr[i + 1] - arr[i]);
		if (K >= now) {
			K -= now;
		}
		else {
			ans = arr[i] + K / i;
			return;
		}
	}
	ans = arr[N] + K / N;
}