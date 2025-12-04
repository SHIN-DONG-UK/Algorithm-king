#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100005];
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
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	ans = 2e9;
}

void solve() {
	for (int i = 0; i < N-1; i++) {
		int left = i + 1;
		int right = N - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			int m = arr[mid] - arr[i];

			if (m >= M) {
				right = mid - 1;
				if (ans > m) ans = m;
			}
			else {
				left = mid + 1;
			}
		}
	}
}