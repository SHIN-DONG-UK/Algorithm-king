#include <iostream>
using namespace std;

char arr[1001];
int len, a_cnt;
int ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	
	solve();

	cout << ans << '\n';
	return 0;
}

void init() {
	cin >> arr;

	while (arr[len] > 0) {
		if (arr[len] == 'a')
			a_cnt++;
		len++;
	}
	ans = 1000;
}

void solve() {
	// 1. 초기 윈도우의 b 개수를 구한다
	int tmp = 0;
	for (int i = 0; i < a_cnt; i++) {
		if (arr[i] == 'b')
			tmp++;
	}

	// 2. 모든 윈도우를 검사하고 최솟값을 구한다
	for (int i = 0; i < len; i++) {
		int front = i;
		int rear = (i + a_cnt) % len;
		if (arr[front] == 'b') tmp--;
		if (arr[rear] == 'b') tmp++;

		if (ans > tmp)
			ans = tmp;
	}
}