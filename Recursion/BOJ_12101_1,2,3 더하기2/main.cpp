#include <iostream>
using namespace std;

int n, k;
int now_ord;
int path[11];

void init();
bool go(int idx, int val);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	if (!go(0, 0)) {
		cout << "-1\n";
	}

	return 0;
}

void init() {
	cin >> n >> k;
}

bool go(int idx, int val) {
	if (val > n) return false;

	if (val == n) {
		now_ord++;

		if (now_ord == k) {
			for (int i = 0; i < idx - 1; i++) {
				cout << path[i] << '+';
			}
			cout << path[idx - 1] << '\n';
			return true;
		}
	}

	for (int i = 1; i <= 3; i++) {
		path[idx] = i;
		if (go(idx + 1, val + i)) return true;
	}

	return false;
}