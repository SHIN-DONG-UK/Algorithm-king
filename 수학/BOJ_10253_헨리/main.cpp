#include <iostream>
using namespace std;

using ll = long long;

int T;
ll a, b;
ll x;

void init();
void solve();

bool check(ll mid);
inline ll gcd(ll a, ll b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();
	}
	return 0;
}

void init() {
	cin >> a >> b;
}

void solve() {
	while (true) {
		// 1. 조건을 만족하는 가장 작은 x1을 찾는다
		/*ll l = 2; ll r = (1ll << 30);
		ll mid;

		while (l <= r) {
			mid = (l + r) / 2;

			if (check(mid)) {
				x = mid;
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}*/
		ll x = (b + a - 1) / a;

		// 2. a/b에 1/x를 뺀다
		ll g = gcd(b, x);
		ll common = b * x / g;
		ll t = a * (x / g) - b / g;

		//3. 만약 뺀 결과가 0이면 종료한다
		if (t == 0) {
			cout << x << '\n';
			return;
		}

		ll g2 = gcd(common, t);
		a = t / g2;
		b = common / g2;
	}
	

}

bool check(ll mid) {
	ll g = gcd(b, mid);
	ll na = a * (mid / g);
	ll nmid = b / g;

	if (na >= nmid) return true;
	else return false;
}

inline ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

