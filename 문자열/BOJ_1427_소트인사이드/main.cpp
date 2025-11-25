#include <iostream>
#include <algorithm>
using namespace std;

int N;
int len;
int arr[11];

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
	cin >> N;

	while (N > 0) {
		arr[++len] = N % 10;
		N /= 10;
	}
}

void solve() {
	sort(arr + 1, arr + len + 1, greater<>());

	for (int i = 1; i <= len; i++) {
		cout << arr[i];
	}
	cout << '\n';

}