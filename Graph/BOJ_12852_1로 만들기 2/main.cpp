#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
int p[1'000'005];

void init();
void solve();
void output();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	output();
	
	return 0;
}

void init() {
	cin >> N;
}

void solve() {
	queue<int> Q;
	p[N] = -1;
	Q.push(N);

	int now, next;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();

		if (now == 1) {
			return;
		}
		//1번 연산
		if (now % 3 == 0) {
			next = now / 3;
			if (p[next] == 0) {
				p[next] = now;
				Q.push(next);
			}
		}
		//2번 연산
		if (now % 2 == 0) {
			next = now / 2;
			if (p[next] == 0) {
				p[next] = now;
				Q.push(next);
			}
		}

		//3번 연산
		next = now - 1;
		if (p[next] == 0) {
			p[next] = now;
			Q.push(next);
		}
	}
}

void output() {
	vector<int> tmp;

	int now = 1;
	while (now != -1) {
		tmp.push_back(now);
		now = p[now];
	}
	
	cout << tmp.size() - 1 << '\n';
	for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';
}