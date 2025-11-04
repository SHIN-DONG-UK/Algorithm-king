#include <iostream>
using namespace std;

int N, K;
int small[20];
int big[20];

int ans;
bool f;

void init();
void go(int idx, int e);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	go(0, 0);

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> small[i] >> big[i];
	}
	cin >> K;

	ans = 1e9;
}

void go(int idx, int e) {
	if (idx == N - 1) {
		ans = ans > e ? e : ans;
		return;
	}
	else if (idx > N - 1) {
		return;
	}

	go(idx + 1, e + small[idx]);
	go(idx + 2, e + big[idx]);
	
	if (!f) {
		f = true;
		go(idx + 3, e + K);
		f = false;
	}
}