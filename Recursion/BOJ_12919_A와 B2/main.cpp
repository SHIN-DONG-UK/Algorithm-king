#include <iostream>
#include <string>
using namespace std;

char S[50];
char T[51];

char tmp[51];

int len_s, len_t;

void init();
void solve();

bool go(int l, int r, bool dir);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	if (go(0, len_t - 1, true)) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}

void init() {
	cin >> S;
	while (S[len_s] != 0) { len_s++; }
	cin >> T;
	while (T[len_t] != 0) { len_t++; }
}

bool go(int l, int r, bool dir) {
	// [FOR DEBUG]
	string tmp = "";
	if (dir) {
		for (int i = l; i <= r; i++) {
			tmp += T[i];
		}
	}
	else {
		for (int i = r; i >= l; i--) {
			tmp += T[i];
		}
	}
	//

	if (r - l + 1 == len_s) {
		if (dir) {
			// 정방향
			for (int i = 0; i < len_s; i++) {
				if (S[i] != T[l + i]) return false;
			}
		}
		else {
			// 역방향
			for (int i = 0; i < len_s; i++) {
				if (S[i] != T[r - i]) return false;
			}
			
		}
		return true;
	}

	if (dir) {
		// 정방향
		if (T[l] == 'A' && T[r] == 'A') {
			if (go(l, r - 1, dir)) return true;
		}

		else if (T[l] == 'A' && T[r] == 'B') {
			return false;
		}

		else if (T[l] == 'B' && T[r] == 'A') {
			if (go(l, r - 1, dir)) return true;
			if (go(l + 1, r, !dir)) return true;
		}
		else {
			if (go(l + 1, r, !dir)) return true;
		}

	}
	else {
		// 역방향
		if (T[r] == 'A' && T[l] == 'A') {
			if (go(l + 1, r, dir)) return true;
		}

		else if (T[r] == 'A' && T[l] == 'B') {
			return false;
		}

		else if (T[r] == 'B' && T[l] == 'A') {
			if (go(l + 1, r, dir)) return true;
			if (go(l, r - 1, !dir)) return true;
		}

		else {
			if (go(l, r - 1, !dir)) return true;
		}
	}

	return false;
}