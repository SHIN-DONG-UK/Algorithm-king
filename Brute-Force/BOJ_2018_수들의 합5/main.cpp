#include <iostream>
using namespace std;

int N, cnt;
long long l, r, sum;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << cnt << '\n';
	return 0;
}

void init() {
	cin >> N;
	l = r = sum = 1;
}

void solve() {
	while (l <= r && r <= N) {
		if (sum < N) {
			r++;
			sum += r;
		}
		else if (sum > N) {
			sum -= l;
			l++;
		}
		else {
			cnt++;
			r++;
			sum += r;
		}
	}
}