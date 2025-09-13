#include <iostream>
using namespace std;

const int MX = 30000;
const int MX_VAR = 3000;

int N, d, k, c;
int sushi[MX + MX_VAR + 1];
int cnt[MX_VAR + 1];
int cur_cnt;


void init();
void solve();

void push(int sushi_num);
void pop(int sushi_num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> d >> k >> c;

	for (int i = 0; i < N; i++) {
		cin >> sushi[i];
	}

	for (int i = N; i < N + k; i++) {
		sushi[i] = sushi[i - N];
	}
}

void solve() {
	push(c);

	for (int i = 0; i < k; i++) {
		push(sushi[i]);
	}

	int ans = cur_cnt;
	for (int i = 0; i < N; i++) {
		push(sushi[i + k]);
		pop(sushi[i]);
		if (ans < cur_cnt) ans = cur_cnt;
	}

	cout << ans << '\n';
}

void push(int sushi_num) {
	if (cnt[sushi_num] == 0) cur_cnt++;
	cnt[sushi_num]++;
}

void pop(int sushi_num) {
	cnt[sushi_num]--;
	if (cnt[sushi_num] == 0) cur_cnt--;
}