#include <iostream>
#include <cstring>
using namespace std;

char s[2005];

char stk[2005]; int stk_size;
inline void mpush(const char& c);
inline void mpop();
inline char mtop();

int ans;

void init();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int turn = 1;

	while (true) {
		init();

		cin >> s;
		if (s[0] == '-')
			break;

		int i = 0;
		while (s[i] != 0) {
			if (stk_size == 0) {
				mpush(s[i]);
			}	
			else {
				if (mtop() == '{' && s[i] == '}') {
					mpop();
				}
				else {
					mpush(s[i]);
				}
			}
			i++;
		}

		while (stk_size > 0) {
			if (stk[stk_size - 1] == '{') {
				ans++;
				mpop();
				mpop();
			}
			else if (stk[stk_size - 1] == '}') {
				if (mtop() == '}') {
					ans++;
					mpop();
					mpop();
				}
				else {
					ans += 2;
					mpop();
					mpop();
				}
			}
		}

		cout << turn << ". " << ans << '\n';
		turn++;
	}

	return 0;
}

void init() {
	stk_size = 0;
	ans = 0;
}

inline void mpush(const char& c) {
	stk[++stk_size] = c;
}

inline void mpop() {
	if (stk_size > 0) {
		stk[stk_size--] = 0;
	}
}

inline char mtop() {
	return stk[stk_size];
}