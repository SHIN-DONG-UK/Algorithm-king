#include <iostream>
using namespace std;

int T;
char arr[201]; int len_arr;

void init();
bool go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		if (go(0)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}

void init() {
	cin >> arr;
	len_arr = 0;
	while (arr[len_arr] > 0) { len_arr++; }
}

bool go(int idx) {
	if (idx == len_arr) {
		return true;
	}

	if (arr[idx] == '0') {
		if (idx + 1 >= len_arr) {
			return false;
		}
		
		if (arr[idx + 1] == '0') {
			return false;
		}

		if (go(idx + 2)) return true;
	}
	else {
		if (idx + 2 >= len_arr) {
			return false;
		}
		if (arr[idx + 1] != '0' || arr[idx + 2] != '0') {
			return false;
		}

		// 1. 0털기
		int j = idx + 3;
		while (arr[j] == '0' && j < len_arr) { j++; }
		if (j == len_arr) return false;

		// 2. 1털기 -> [수정] 1은 다 털면 안됨
		//while (arr[j] == '1' && j < len_arr) { j++; }
		//if (go(j)) return true;

		// 2. 털면서 다 해봐야 함
		while (arr[j] == '1' && j < len_arr) {
			if (go(j + 1)) return true;
			j++;
		}
	}

	return false;
}