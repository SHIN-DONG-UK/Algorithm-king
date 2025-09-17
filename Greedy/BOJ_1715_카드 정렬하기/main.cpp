#include <iostream>
#include <queue>
using namespace std;

const int MX = 100'000;


int N;
priority_queue<int, vector<int>, greater<>> PQ;
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
	cin >> N;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		PQ.push(tmp);
	}
}

void solve() {
	int num1, num2;
	while (!PQ.empty()) {
		num1 = PQ.top(); PQ.pop();
		if (PQ.empty()) continue;
		num2 = PQ.top(); PQ.pop();
		PQ.push(num1 + num2);
		ans += (num1 + num2);
	}
}