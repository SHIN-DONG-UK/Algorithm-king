#include <iostream>
using namespace std;

int h1, h2;
int m1, m2;
int s1, s2;

int t_start, t_end; // (단위: sec)

struct Return {
	bool flag;
	int cnt;
};

void init();
Return count(int t);
int solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	int answer = solve();

	cout << "정답 = " << answer << '\n';

	return 0;
}

void init() {
	cin >> h1 >> m1 >> s1;
	cin >> h2 >> m2 >> s2;

	t_start = 3600 * h1 + 60 * m1 + s1;
	t_end = 3600 * h2 + 60 * m2 + s2;
}

Return count(int t) {
	long long A = 59LL * t / 3600;
	long long B = 719LL * t / 43200;
	long long C = t >= 43200 ? 1 : 0;

	bool flag = 59LL * t % 3600 == 0 || 719LL * t % 43200 == 0 ? true : false;
	Return rst = { flag, int(A + B + 1 - C) };

	return rst;
}

int solve() {
	Return return_start = count(t_start);
	Return return_end = count(t_end);

	int rst = return_end.cnt - return_start.cnt;
	if (return_start.flag) {
		rst += 1;
	}

	return rst;
}