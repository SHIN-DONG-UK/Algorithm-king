#include <iostream>
using namespace std;

long long A, B;
long long tar;

void init();
void solve();
int gcd(int a, int b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> A >> B;
	tar = B / A;
}

void solve() {
	int min = 1e9;
	long long a, b;
	for (long long t = 1; t * t <= tar; t++) {
		if (tar % t != 0) continue;
		if (gcd(t, tar / t) != 1) continue;

		if (min > t + tar / t) {
			min = t + tar / t;
			a = t;
			b = tar / t;
		}
	}

	cout << a * A << ' ' << b * A << '\n';
}

int gcd(int a, int b) {
	// gcd(a, b) = gcd(b, r)
	// r = a % b
	// gcd(6, 180) = gcd(180, 6) = gcd(6, 0)
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}