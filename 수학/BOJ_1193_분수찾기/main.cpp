#include <iostream>
using namespace std;

int x;

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
	cin >> x;
}

void solve() {
	int t = 0;
	while (1) {
		t++;
		if (t * (t + 1) / 2 >= x) {
			break;
		}
	}

	int move = t * (t + 1) / 2 - x;

	if (t % 2 == 0) {
		cout << t - move << '/' << 1 + move << '\n';
	}
	else {
		cout << 1 + move << '/' << t - move << '\n';
	}
}