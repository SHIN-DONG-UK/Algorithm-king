#include <iostream>
#include <cmath>
using namespace std;

int N, K;
long double arr[501];
long double acsum[501];
long double acsum2[501];

long double ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	printf("%.11Lf\n", sqrtl(ans));

	return 0;
}

void init() {
	cin >> N >> K;

	long double tmp = 0; long double tmp2 = 0;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];

		tmp += arr[i];
		acsum[i] = tmp;

		tmp2 += arr[i] * arr[i];
		acsum2[i] = tmp2;
	}

	ans = 1e24;

}

void solve() {
	//Brute-Force
	for (int len = K; len <= N; len++) {
		for (int idx = len; idx <= N; idx++) {
			if (idx - len < 0) continue;
			//분산 = E(X^2) - E(X)^2
			long double sqrmean = (acsum2[idx] - acsum2[idx - len]) / len;
			long double meansqr = ((acsum[idx] - acsum[idx - len]) / len) * ((acsum[idx] - acsum[idx - len]) / len);

			//long double tmp = (sqrmean - meansqr) * 1000000000000 / (len * len);
			long double tmp = sqrmean - meansqr;

			if (ans > tmp)
				ans = tmp;
		}
	}
}