#include <iostream>
#include <algorithm>
using namespace std;

using u64 = unsigned long long;

u64 N;
u64 dice[6];

int mini, mini2, mini3;
int big;

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
	cin >> N;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
	}

	mini = 55;
	for (int i = 0; i < 6; i++) {
		if (mini > dice[i])
			mini = dice[i];
		if (dice[i] > big)
			big = dice[i];
	}

	mini2 = min({
		dice[0] + dice[1],
		dice[0] + dice[2],
		dice[0] + dice[3],
		dice[0] + dice[4],
		dice[1] + dice[2],
		dice[1] + dice[3],
		dice[1] + dice[5],
		dice[2] + dice[4],
		dice[2] + dice[5],
		dice[3] + dice[4],
		dice[3] + dice[5],
		dice[4] + dice[5]
		});

	mini3 = min({
		dice[3] + dice[0] + dice[1],
		dice[3] + dice[1] + dice[5],
		dice[3] + dice[5] + dice[4],
		dice[3] + dice[4] + dice[0],
		dice[2] + dice[0] + dice[1],
		dice[2] + dice[1] + dice[5],
		dice[2] + dice[5] + dice[4],
		dice[2] + dice[4] + dice[0],
		});
}

void solve() {
	if (N == 1) {
		u64 sum = 0;
		for (int i = 0; i < 6; i++) {
			sum += dice[i];
		}

		cout << sum - big << '\n';
	}
	else if (N == 2) {
		u64 sum = 0;
		sum += mini3 * 4;
		sum += mini2 * 4;

		cout << sum << '\n';
	}
	else {
		u64 sum = 0;
		sum += mini3 * 4;
		sum += mini2 * (N - 2) * 4;
		sum += mini2 * (N - 1) * 4;
		sum += mini * (N - 2) * (N - 1) * 4;
		sum += mini * (N - 2) * (N - 2);

		cout << sum << '\n';
	}
}