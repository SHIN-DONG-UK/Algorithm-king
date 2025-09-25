#include <iostream>
using namespace std;

int L, R;
int ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> L >> R;
}
void solve() {
	if (L == R) {
		//8의 개수 세기
		while (L != 0) {
			int rem = L % 10;
			L /= 10;

			if (rem == 8) {
				ans++;
			}
		}
	}
	else {
		//자릿수가 다르면 0
		//자릿수가 같으면 공통 8 찾기
		int lenL = 0;
		int lenR = 0;
		int l = L; int r = R;
		while (l != 0) {
			l /= 10;
			lenL++;
		}
		while (r != 0) {
			r /= 10;
			lenR++;
		}

		if (lenL != lenR)
			return;

		int ten = 1;
		for (int i = 0; i < lenL - 1; i++) {
			ten *= 10;
		}

		while (L != 0 && R != 0) {
			int tmpl = L / ten; L %= ten;
			int tmpr = R / ten; R %= ten;
			if (tmpl == tmpr) {
				if(tmpl == 8 && tmpr == 8)
					ans++;
				ten /= 10;
			}
			else return;
		}

	}
}