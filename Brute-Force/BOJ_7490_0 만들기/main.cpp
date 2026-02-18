#include <iostream>
#include <string>
using namespace std;

int N;
string expr;

void init();
void go(int lev, int res, int num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		expr.push_back('1');
		go(1, 0, 1);
		expr.pop_back();
		
		cout << '\n';
	}
	return 0;

}

void init() {
	cin >> N;
}

void go(int lev, int res, int num) {
	if (lev == N) {
		if (res + num == 0) {
			cout << expr << '\n';
		}

		return;
	}

	// 1. 공백
	expr.push_back(' ');
	expr.push_back('1' + lev);
	if (num < 0) {
		go(lev + 1, res, num * 10 - (lev + 1));
	}
	else {
		go(lev + 1, res, num * 10 + lev + 1);
	}
	expr.pop_back();
	expr.pop_back();
	// 2. 더하기
	expr.push_back('+');
	expr.push_back('1' + lev);
	go(lev + 1, res + num, lev + 1);
	expr.pop_back();
	expr.pop_back();
	// 3. 빼기
	expr.push_back('-');
	expr.push_back('1' + lev);
	go(lev + 1, res + num, -(lev + 1));
	expr.pop_back();
	expr.pop_back();
}