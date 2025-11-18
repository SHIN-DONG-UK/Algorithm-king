#include <iostream>
using namespace std;

int A, B;
int a_len, b_len;
int ans;

int powerOftwo[11] = { 1, 2, 4, 8, 16 ,32, 64, 128, 256, 512, 1024 };

void init();
void solve();
void go(int idx, int num, const int& limit);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans << '\n';
	return 0;
}

void init() {
	cin >> A >> B;

	int a = A; int b = B;
	while (a > 0) {
		a /= 10;
		a_len++;
	}
	while (b > 0) {
		b /= 10;
		b_len++;
	}
}

void solve() {
	for (int k = a_len + 1; k < b_len; k++) {
		ans += powerOftwo[k];
	}

	if (a_len == b_len) {
		go(0, 0, a_len);
	}
	else {
		go(0, 0, a_len);
		go(0, 0, b_len);
	}

}

void go(int idx, long long num, const int& limit) {
	if (idx == limit) {
		if (num >= A && num <= B) { ans++; }
		return;
	}

	long long next_num = num * 10 + 4;
	go(idx + 1, next_num, limit);
	next_num = num * 10 + 7;
	go(idx + 1, next_num, limit);
}