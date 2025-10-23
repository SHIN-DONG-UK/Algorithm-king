#include <iostream>
#include <string>
using namespace std;

int N;

bool visited[26];

int check(const string& s);
inline char mlower(const char& c);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	cin.ignore();

	string s;

	for (int k = 0; k < N; k++) {
		getline(cin, s);

		int idx = check(s);

		if (idx < 0) {
			cout << s;
		}
		else {
			for (int i = 0; i < s.size(); i++) {
				if (idx == i) {
					cout << '[';
					cout << s[i];
					cout << ']';
				}
				else {
					cout << s[i];
				}
			}
		}

		cout << '\n';
	}
}

int check(const string& s) {
	char c = mlower(s[0]);
	if (!visited[c - 'a']) {
		visited[c - 'a'] = true;
		return 0;
	}

	//1. 단어의 첫 글자가 이미 단축키로 지정되었는지 살펴본다.
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == ' ') {
			c = mlower(s[i + 1]);
			if (!visited[c - 'a']) {
				visited[c - 'a'] = true;
				return i + 1;
			}
		}
	}

	//2. 왼쪽에서부터 차례대로 지정되지 않은 것을 단축키로 지정한다.
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		c = mlower(s[i]);

		if (!visited[c - 'a']) {
			visited[c - 'a'] = true;
			return i;
		}
	}

	//그런 알파벳이 없다.
	return -1;
}

inline char mlower(const char& c) {
	if (c >= 'a') return c;
	else return c + 'a' - 'A';
}