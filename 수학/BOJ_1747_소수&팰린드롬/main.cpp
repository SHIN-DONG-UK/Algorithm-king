#include <iostream>
#include <cmath>
using namespace std;

const int MX = 1003001;

int N;

bool is_prime[MX + 1];
int tmp[7]; int curSize = 0;

void init();
void solve();
void eratosthenes();
int mreverse(int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	solve();

	return 0;
}

void init() {
	cin >> N;

	eratosthenes();
}

void solve() {
	for (int num = N; num <= MX; num++) {
		if (!is_prime[num]) continue;
		int reversed = mreverse(num);
		if (num == reversed) {
			cout << reversed << '\n';
			return;
		}
	}
}

void eratosthenes() {
	for (int i = 2; i <= MX; i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i <= sqrt(MX); i++) {
		if (is_prime[i]) {
			int j = 2;
			while (i * j <= MX) {
				is_prime[i * j] = false;
				j++;
			}
		}
		
	}
}

inline int mreverse(int num) {
	curSize = 0;
	while (num != 0) {
		tmp[curSize++] = num % 10;
		num /= 10;
	}

	int rst = 0; int idx = 0;
	while (curSize--) {
		rst *= 10;
		rst += tmp[idx++];
	}
	return rst;
}