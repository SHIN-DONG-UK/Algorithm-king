#define A 1
#define B 2
#define C 3
#include <iostream>
#include <vector>
using namespace std;

int N;
int cnt;

vector<pair<int, int>> mlog;

void hanoi(int k, int from, int by, int to);
void move(int from, int to);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	hanoi(N, A, B, C);

	cout << cnt << '\n';
	for (auto& p : mlog)
		cout << p.first << ' ' << p.second << '\n';

	return 0;
}

void hanoi(int k, int from, int by, int to) {
	if (k == 0) {
		return;
	}
	hanoi(k - 1, from, to, by);
	move(from, to);
	hanoi(k - 1, by, from, to);
}

void move(int from, int to) {
	cnt++;
	mlog.push_back({ from, to });
}