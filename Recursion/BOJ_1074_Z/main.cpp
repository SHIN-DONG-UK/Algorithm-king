#include <iostream>

using namespace std;

int N, r, c;
int ans, cnt;
bool flag;

int two[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

void go(int raw, int column, int n);

int main() {
	cin >> N >> r >> c;

	cnt += (two[N] / 2) * (two[N] / 2) * 3;
	go(two[N] /2, two[N] / 2, two[N] / 2);

	cout << cnt << '\n';
}

void go(int y, int x, int n) {
	if (flag)
		return;

	if (y == r && x == c) {
		flag = true;
		return;
	}

	// 1사분면?
	if (r < y && c < x) {
		// go
		cnt -= n * n * 3;
		cnt += (n / 2) * (n / 2) * 3;
		if(n == 1)
			go(y - 1, x - 1, n / 2);
		else
			go(y - n / 2, x - n / 2, n / 2);
	}

	// 2사분면
	else if (r < y && c >= x) {
		// go
		cnt -= n * n * 2;
		cnt += (n / 2) * (n / 2) * 3;
		if (n == 1)
			go(y - 1, x, n / 2);
		else
			go(y - n / 2, x + n / 2, n / 2);
	}
	// 3사분면
	else if (r >= y && c < x) {
		// go
		cnt -= n * n;
		cnt += (n / 2) * (n / 2) * 3;
		if (n == 1)
			go(y, x - 1, n / 2);
		else
			go(y + n / 2, x - n / 2, n / 2);
	}
	// 4사분면
	else {
		// go
		cnt += (n / 2)*(n / 2) * 3;
		go(y + n / 2, x + n / 2, n / 2);
	}
}