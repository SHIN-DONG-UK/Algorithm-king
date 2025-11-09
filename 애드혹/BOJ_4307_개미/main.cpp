#include <iostream>
#include <algorithm>
using namespace std;

int T, l, n;
int arr[100000];

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
	cin >> l >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

void solve() {
	int ans_min = 0;
	
	for (int i = 0; i < n; i++) {
		int best = min(arr[i], l - arr[i]);
		if (ans_min < best)
			ans_min = best;
	}

	double collision_pos = ((double)arr[n - 1] + arr[0]) / 2;

	int ans_max = max(2 * collision_pos - arr[0], arr[n - 1] + l - 2 * collision_pos);

	cout << ans_min << ' ' << ans_max << '\n';

}