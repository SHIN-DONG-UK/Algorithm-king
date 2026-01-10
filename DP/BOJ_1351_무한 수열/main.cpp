#include <iostream>
#include <unordered_map>
using namespace std;

long long N, P, Q;
unordered_map<long long, long long> memo;

void init();
long long go(long long now);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	long long ans = go(N);
	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> N >> P >> Q;
}

long long go(long long now) {
	if (now == 0) {
		return 1ll;
	}

	if (memo.count(now) > 0) {
		return memo[now];
	}

	long long rst = go(now / P) + go(now / Q);
	memo[now] = rst;
	return rst;
}