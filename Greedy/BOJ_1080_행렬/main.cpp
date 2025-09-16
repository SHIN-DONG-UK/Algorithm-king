#include <iostream>
using namespace std;

const int MX = 50;


int N, M;
bool A[MX][MX];
bool B[MX][MX];

int ans;

void init();
void solve();

inline void flip(int& y, int& x);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans << '\n';
	return 0;
}

void init() {
	cin >> N >> M;
	char tmp[MX + 1];
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '1') {
				A[i][j] = true;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			if (tmp[j] == '1') {
				B[i][j] = true;
			}
		}
	}
}

void solve() {
	for (int i = 0; i <= N - 3; i++) {
		for (int j = 0; j <= M - 3; j++) {
			if (A[i][j] ^ B[i][j]) {
				flip(i, j);
				ans++;
			}
		}
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] ^ B[i][j]) {
				flag = true;
				ans = -1;
				break;
			}
		}
		if (flag) break;
	}
}

inline void flip(int& y, int& x) {
	for (int i = y; i < y + 3; i++) {
		for (int j = x; j < x + 3; j++) {
			A[i][j] = !A[i][j];
		}
	}
}