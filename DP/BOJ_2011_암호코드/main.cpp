#include <iostream>
using namespace std;

char code[5005];
int icode[5005];
int opt[5005];
int len;

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
	cin >> code;
	while (code[len] > 0) {
		icode[len + 1] = code[len] - '0';
		len++;
	}
}

void solve() {
	if (icode[1] == 0) {
		cout << "0\n";
		return;
	}
	opt[0] = opt[1] = 1;

	int i = 2;

	while (i <= len) {
		if (icode[i] == 0) {
			if (icode[i - 1] == 1 || icode[i - 1] == 2) {
				opt[i] = opt[i - 2];
				opt[i + 1] = opt[i - 2];
				i++;
			}
			else {
				cout << "0\n";
				return;
			}
		}
		else {
			int tmp = icode[i - 1] * 10 + icode[i];
			if (tmp > 26) {
				opt[i] = opt[i - 1];
			}
			else {
				opt[i] = (opt[i - 1] + opt[i - 2]) % 1000000;
			}
		}
		i++;
	}
	cout << opt[len] << '\n';
}