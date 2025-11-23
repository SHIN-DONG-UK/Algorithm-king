#include <iostream>
using namespace std;

char arr[105]; int len;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> arr;
	while (arr[len] > 0) { len++; }
}

void solve() {
	int i = 0;
	int cnt = 0;
	while (i < len) {
		if (arr[i] == 'd' && arr[i + 1] == 'z' && arr[i + 2] == '=') { i += 3; cnt++; }
		else if (arr[i] == 'c' && arr[i + 1] == '=') { i += 2; cnt++; }
		else if (arr[i] == 'c' && arr[i + 1] == '-') { i += 2; cnt++; }
		else if (arr[i] == 'd' && arr[i + 1] == '-') { i += 2; cnt++; }
		else if (arr[i] == 'l' && arr[i + 1] == 'j') { i += 2; cnt++; }
		else if (arr[i] == 'n' && arr[i + 1] == 'j') { i += 2; cnt++; }
		else if (arr[i] == 's' && arr[i + 1] == '=') { i += 2; cnt++; }
		else if (arr[i] == 'z' && arr[i + 1] == '=') { i += 2; cnt++; }
		else { cnt++; i++; }
		
	}
	cout << cnt << '\n';
}