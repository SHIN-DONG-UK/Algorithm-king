#include <iostream>
using namespace std;

int N, K;
int cnt;

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
	cin >> N >> K;

	int tmp = N;
	do {
		if (tmp & 1) { cnt++; }
	} while (tmp = tmp >> 1);
}

void solve() {
	if (K >= cnt) {
		cout << "0\n";
	}
	else {
		int sum = 0;
		int cnt2 = 0;
		int num = 1;
		while (cnt2 != cnt - K + 1) {
			if (N & num) {
				cnt2++;
			}
			else {
				sum += num;
			}
			num = num << 1;
		}

		cout << sum + 1 << '\n';
	}
}