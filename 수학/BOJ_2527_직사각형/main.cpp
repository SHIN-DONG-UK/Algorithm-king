#include <iostream>
using namespace std;

int x, y, p, q;
int tx, ty, tp, tq;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}

void solve() {
	for (int i = 0; i < 4; i++) {
		cin >> x >> y >> p >> q >> tx >> ty >> tp >> tq;
		if (tp < x || tx > p || tq < y || ty > q) {
			//4. 겹치는 부분이 없는 경우
			cout << "d\n";
		}
		else if ((x == tp && q == ty) || (p == tx && q == ty) || (p == tx && y == tq) || (x == tq && y == tq)) {
			//3. 점으로 만나는 경우
			cout << "c\n";
		}
		else if (tp == x || ty == q || p == tx || y == tq) {
			//2. 선으로 만나는 경우
			cout << "b\n";
		}
		else {
			//1. 겹치는게 직사각형
			cout << "a\n";
		}
	}
}