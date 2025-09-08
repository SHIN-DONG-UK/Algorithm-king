//BOJ_1806_부분합

#include <iostream>
using namespace std;

const int MX = 100'005;

int N, s;
int arr[MX];
int S[MX];


void init();
int solve();
bool check(int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int ans = solve();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> N >> s;

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum += arr[i];
		S[i] = sum;
	}
}

int solve() {
	int rst = 0;

	int l = 1; int r = N;

	int mid;

	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid)) {
			rst = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return rst;
}

bool check(int x) {
	int tmp;
	for (int i = x; i <= N; i++) {
		tmp = S[i] - S[i - x];
		if (tmp >= s) return true;
	}
	return false;
}