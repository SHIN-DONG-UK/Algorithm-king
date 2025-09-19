#include <iostream>
#include <queue>
using namespace std;

using ll = long long;

int n, m;
priority_queue<ll, vector<ll>, greater<>> cards;
ll ans;

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
	cin >> n >> m;
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cards.push(num);
	}
}

void solve() {
	ll c1, c2;
	while (m--) {
		c1 = cards.top(); cards.pop();
		c2 = cards.top(); cards.pop();
		cards.push(c1 + c2);
		cards.push(c1 + c2);
	}

	while (!cards.empty()) {
		ans += cards.top(); cards.pop();
	}
}