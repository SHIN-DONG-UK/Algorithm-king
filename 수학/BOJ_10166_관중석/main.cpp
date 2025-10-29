#include <iostream>
using namespace std;

int D1, D2;
bool visited[2005][2005];

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
	cin >> D1 >> D2;
}

void solve() {
	int ans = 0;
	int p, q;
	for (int d = D1; d <= D2; d++) {
		for (int k = 1; k < d; k++) {
			int g = gcd(d, k);
			p = k / g;
			q = d / g; 
			if (!visited[p][q]) {// 기약분수 형태로 관리 (p/q)
				visited[p][q] = true;
				ans++;
			}
		}
	}

	cout << ans + 1 << '\n'; // 북쪽 마지막에 추가
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}