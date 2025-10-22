#include <iostream>
#include <string>
using namespace std;

string s;
bool visited[11];
int cnt[26];

string buffer;

int len, ans;

void init();
void go(const int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	go(0);

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> s;

	len = s.length();

	buffer.resize(10);

	for (int i = 0; i < len; i++) {
		cnt[s[i] - 'a']++;
	}
}

void go(const int idx) {
	if (idx == len) {
		for (int i = 0; i < len - 1; i++) {
			if (buffer[i] == buffer[i + 1])
				return;
		}
		ans++;
		return;
	}

	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0) continue;
		cnt[i]--;
		buffer[idx] = 'a' + i;
		go(idx + 1);
		cnt[i]++;
	}
}