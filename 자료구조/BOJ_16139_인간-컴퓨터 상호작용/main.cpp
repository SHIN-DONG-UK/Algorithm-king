#include <iostream>
using namespace std;

const int MX = 200000;

char S[MX + 1];
int cumul[MX + 1][26];
int q;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> S;
	cin >> q;

	int i = 0;
	while (S[i] != '\0') {
		cumul[i][S[i] - 'a']++;
		for (int j = 0; j < 26; j++) {
			cumul[i + 1][j] = cumul[i][j];
		}
		i++;
	}
}

void solve() {
	char al;
	int l, r;
	while (q--) {
		cin >> al >> l >> r;
		if (l == 0) {
			cout << cumul[r][al - 'a'] << '\n';
		}
		else {
			cout << cumul[r][al - 'a'] - cumul[l - 1][al - 'a'] << '\n';
		}
	}
}