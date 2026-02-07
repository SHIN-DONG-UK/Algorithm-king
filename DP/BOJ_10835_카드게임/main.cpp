#include <iostream>
#include <cstring>
using namespace std;

int N, gAns;
int left_cards[2002];
int right_cards[2002];
int dp[2002][2002];

void init();
int go(int y, int x);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	cout << go(1, 1) << '\n';
	return 0;
}

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> left_cards[i]; }
	for (int i = 1; i <= N; i++) { cin >> right_cards[i]; }

	memset(dp, -1, sizeof(dp));
}

int go(int y, int x) {
	if (y > N || x > N) {
		return 0;
	}

	// 이미 계산한 적이 있으면, 반환
	if (dp[y][x] != -1) {
		return dp[y][x];
	}

	int tmp1 = go(y + 1, x);	 // 왼쪽 카드만 버린 경우
	int tmp2 = go(y + 1, x + 1); // 둘 다 버린 경우

	int rst = max(tmp1, tmp2);

	if (left_cards[y] > right_cards[x]) {
		int tmp3 = go(y, x + 1);
		rst = max(rst, tmp3 + right_cards[x]);
	}

	dp[y][x] = rst;
	return dp[y][x];
}