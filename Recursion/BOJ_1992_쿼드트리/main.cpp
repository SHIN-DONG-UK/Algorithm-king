#include <iostream>
using namespace std;

const int MX = 65;

int N;
char arr[MX][MX];

void init();
void go(int n, int y, int x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	go(N, 0, 0);

	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void go(int n, int y, int x) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (arr[y][x] != arr[i][j]) {
				int nxt = n / 2;
				cout << '(';
				go(nxt, y, x);
				go(nxt, y, x + nxt);
				go(nxt, y + nxt, x);
				go(nxt, y + nxt, x + nxt);
				cout << ')';
				return;
			}
		}
	}
	cout << arr[y][x];
}