#include <iostream>
#include <algorithm>
using namespace std;

int x, n;
int arr[1000000];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while (cin >> x) {
		init();
		solve();
	}
	return 0;
}

void init() {
	// cm 단위를 nm 단위로 변환
	// cm -> mm -> nm
	x = x * 10 * 1000000;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

void solve() {
	int l_end = 0; int r_end = n - 1;
	while (l_end < r_end) {
		int tmp = arr[l_end] + arr[r_end];
		if (tmp > x) {
			r_end--;
		}
		else if (tmp < x) {
			l_end++;
		}
		else {
			cout << "yes" << ' ' << arr[l_end] << ' ' << arr[r_end] << '\n';
			return;
		}
	}
	cout << "danger\n";
}