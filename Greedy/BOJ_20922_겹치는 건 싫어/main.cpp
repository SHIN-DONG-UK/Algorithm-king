#include <iostream>
using namespace std;

const int MX = 200000;
const int MX_A = 100000;

int N, K;
int arr[MX];
int maxi;

int p1, p2;
int cnt[MX_A + 1];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << maxi << '\n';
	return 0;
}

void init() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	p1 = 0; p2 = 1;
	cnt[arr[p1]] = 1;
	maxi = 1;

	while (p2 < N) {
		if (cnt[arr[p2]] + 1 > K) {
			while (arr[p1] != arr[p2]) {
				cnt[arr[p1++]]--;
			}
			cnt[arr[p1++]]--;
		}
		else {
			cnt[arr[p2++]]++;
		}

		if (p2 - p1 > maxi)
			maxi = p2 - p1;
	}
}