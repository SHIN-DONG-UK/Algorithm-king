#include <iostream>
using namespace std;

int N;
int arr[100005];
int global_opt;
int a1, a2;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	if (a1 > a2) {
		cout << a2 << ' ' << a1 << '\n';
	}
	else {
		cout << a1 << ' ' << a2 << '\n';
	}
	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	global_opt = 2e9 + 12345;
}

void solve() {
	for (int i = 0; i < N; i++) {
		int left, right;
		
		if (arr[i] < 0) {
			left = i + 1; right = N - 1;
		}
		else {
			left = 0; right = i - 1;
		}

		int mid = -1;
		int target = -arr[i];

		while (left <= right) {
			mid = (left + right) / 2;

			if (target < arr[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (mid < 0)
			continue;

		for (int j = mid - 1; j <= mid + 1; j++) {
			if (j < 0 || j >= N) continue;
			if (i == j) continue;
			int tmp_sum = arr[i] + arr[j];
			int abs_opt = tmp_sum > 0 ? tmp_sum : -tmp_sum;
			if (global_opt > abs_opt) {
				global_opt = abs_opt;
				a1 = arr[i]; a2 = arr[j];
			}
		}
	}

}