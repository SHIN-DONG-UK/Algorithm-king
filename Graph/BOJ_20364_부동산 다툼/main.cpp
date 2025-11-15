#include <iostream>
using namespace std;

const int MX = 1 << 20;

int N, Q;
bool visited[MX];

void solve(const int& tar);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> Q;

	int target = 0;
	while (Q--) {
		cin >> target;

		solve(target);

	}
	return 0;
}

void solve(const int& tar) {
	int num = 0;
	int now = tar;

	while (now > 1) {
		if (visited[now]) {
			num = now;
		}
		now /= 2;
	}

	if (num == 0) { visited[tar] = true; }
	cout << num << '\n';
}