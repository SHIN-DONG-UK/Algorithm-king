#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 100'000;

int N;
int arr[MX];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

bool compare(const int& a, const int& b) {
	return abs(a) < abs(b);
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N, compare);
}

void solve() {
	int val;
	int ab = 2e9 + 1;
	int sol1, sol2;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			val = arr[i] + arr[j];
			if (ab > abs(val)) {
				ab = abs(val);
				sol1 = arr[i];
				sol2 = arr[j];
			}
			else break;
		}
	}
	if (sol1 > sol2)
		cout << sol2 << ' ' << sol1 << '\n';
	else
		cout << sol1 << ' ' << sol2 << '\n';
}