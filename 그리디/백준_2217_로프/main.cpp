#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[100001];
int ans;

void input();
void solve();
void output();

int main() {
	input();
	solve();

	cout << ans << '\n';
}

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	sort(arr + 1, arr + N + 1, greater<int>());
	//output();
}

void solve() {
	ans = arr[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] * i > ans) ans = arr[i] * i;
	}
}

void output() {
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}