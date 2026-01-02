#include <iostream>
using namespace std;

int X;

int sum, a, cnt;

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
	cin >> X;

	sum = a = 64;
	cnt = 1;
}

void solve() {
	while (sum > X) {
		if (sum - a / 2 >= X) {
			sum -= a / 2;
			a /= 2;
		}
		else {
			a /= 2;
			cnt++;
		}
	}
	
	cout << cnt << '\n';
}