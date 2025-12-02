#include <iostream>
#include <string>
using namespace std;

int T;
string word;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();
	}
	return 0;
}

void init() {
	cin >> word;
}

void solve() {
	// 1. 다른게 등장하면, 왼쪽을 삭제한다
	int left = 0;
	int right = word.size() - 1;
	int cnt = 0;
	while (left <= right) {
		if (word[left] == word[right]) {
			left++;
			right--;
		}
		else {
			cnt++;
			left++;
			if (cnt > 1) break;
		}
	}
	
	if (cnt == 0) {
		cout << "0\n";
		return;
	}
	else if (cnt == 1) {
		cout << "1\n";
		return;
	}
	// 2. 다른게 등장하면, 오른쪽을 삭제한다
	left = 0;
	right = word.size() - 1;
	cnt = 0;
	while (left <= right) {
		if (word[left] == word[right]) {
			left++;
			right--;
		}
		else {
			cnt++;
			right--;
			if (cnt > 1) break;
		}
	}

	if (cnt == 1) {
		cout << "1\n";
		return;
	}
	else {
		cout << "2\n";
		return;
	}
}