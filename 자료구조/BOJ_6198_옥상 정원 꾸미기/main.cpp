#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> stk;
long long ans;

void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}

void solve() {
	cin >> N;

	int h;
	for (int i = 0; i < N; i++) {
		cin >> h;
		while (!stk.empty() && stk.top() <= h) {
			stk.pop();
		}
		ans += stk.size();

		stk.push(h);
	}

	cout << ans << '\n';
}
