#include <iostream>
#include <cmath>
using namespace std;

int N;

void init();
void solve();

void go(int idx, int now);
bool is_prime(const int& num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N;
}

void solve() {
	go(1, 2);
	go(1, 3);
	go(1, 5);
	go(1, 7);
}

void go(int idx, int now) {
	if (idx == N) {
		cout << now << '\n';
		return;
	}

	int next = 0;
	for (int i = 1; i < 10; i++) {
		next = now * 10 + i;
		if (is_prime(next)) {
			go(idx + 1, next);
		}
	}
}

bool is_prime(const int& num) {
	int r = sqrt(num);
	for (int i = 2; i <= r; i++) {
		if (num % i == 0) return false;
	}
	return true;
}