#include <iostream>
#include <string>
using namespace std;

string S, T;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	if (S == T) {
		cout << "1\n";
	}
	else {
		cout << "0\n";
	}

	return 0;
}

void init() {
	cin >> S;
	cin >> T;
}

void solve() {
	int sLen = S.size();

	while (T.size() > sLen) {
		if (T.back() == 'A') {
			T.pop_back();
		}
		else {
			T.pop_back();

			int tLen = T.size();

			string tmp = "";
			tmp.resize(tLen);

			for (int i = tLen - 1; i >= 0; i--) {
				tmp[tLen - 1 - i] = T[i];
			}

			T = tmp;
		}
	}
}