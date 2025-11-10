#include <iostream>
#include <queue>
using namespace std;

int N, Hc, T;
priority_queue<int> PQ;

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
	cin >> N >> Hc >> T;

	int k;
	for (int i = 0; i < N; i++) {
		cin >> k;
		PQ.push(k);
	}
}

void solve() {
	int tp;
	for (int t = 0; t < T; t++) {
		tp = PQ.top(); PQ.pop();

		if (tp < Hc) {
			cout << "YES\n";
			cout << t << '\n';
			return;
		}
		if (tp == 1) {
			PQ.push(tp);
		}
		else {
			PQ.push(tp / 2);
		}
		
	}

	tp = PQ.top();
	if (tp < Hc) {
		cout << "YES\n";
		cout << T << '\n';
	}
	else {
		cout << "NO\n";
		cout << tp << '\n';
	}
}