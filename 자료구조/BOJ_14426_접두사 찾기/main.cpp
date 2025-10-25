#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N, M;
unordered_set<string> hset;
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
	cin >> N >> M;

	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		string prefix;

		for (int j = 0; j < s.size(); j++) {
			prefix.push_back(s[j]);
			hset.insert(prefix);
		}
	}
}

void solve() {
	string s;
	for (int i = 0; i < M; i++) {
		cin >> s;
		if (hset.count(s) != 0)
			ans++;
	}
}