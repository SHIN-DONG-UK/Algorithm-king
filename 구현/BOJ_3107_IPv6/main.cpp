#include <iostream>
using namespace std;

char arr[40];
char arr2[9][5]; int csize[9]; int hsize;

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
	cin >> arr;
	hsize = 1;

	int i = 0;
	while (arr[i] > 0) {
		if (arr[i] == ':' && arr[i + 1] == ':') {
			arr2[++hsize][0] = 'x';
		}
		else if (arr[i] == ':') {
			hsize++;
		}
		else {
			arr2[hsize][++csize[hsize]] = arr[i];
		}
		i++;
	}
}

void solve() {
	for (int i = 1; i <= hsize; i++) {
		if (arr2[i][0] == 'x') {
			for (int k = 0; k < 8 - hsize + 1; k++) {
				cout << "0000:";
			}
		}
		else {
			for (int j = 0; j < 4 - csize[i]; j++) {
				cout << '0';
			}
			for (int j = 1; j <= csize[i]; j++) {
				cout << arr2[i][j];
			}
			if(i != hsize)
				cout << ':';
		}
	}
	cout << '\n';
}