#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long path[11];
vector<long long> ans;

void init();
void solve();
void go(int idx, int start, int len);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	if (N >= ans.size()) cout << "-1\n";
	else cout << ans[N] << '\n';

	return 0;
}

void init() {
	cin >> N;
}

void solve() {
	for (int i = 1; i <= 10; i++) {
		go(0, 9, i);
	}

	sort(ans.begin(), ans.end());
}
void go(int idx, int start, int len) {
	if (idx == len) {
		long long num = 0;
		for (int i = 0; i < idx; i++) {
			num *= 10LL;
			num += path[i];
		}
		ans.push_back(num);
		return;
	}
	for (int i = start; i >= 0; i--) {
		path[idx] = i;
		go(idx + 1, i - 1, len);
	}
}