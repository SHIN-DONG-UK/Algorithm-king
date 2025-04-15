#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arrA[50];
int arrB[50];
int ans;

void input();
void solve();
void output();

int main() {
	input();
	solve();
	//output();

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arrA[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> arrB[i];
	}

	sort(arrA, arrA + N);
	sort(arrB, arrB + N, greater<int>());
}

void solve() {
	for (int i = 0; i < N; i++) {
		ans += arrA[i] * arrB[i];
	}
}

void output() {
	cout << "[arrA]\n";
	for (int i = 0; i < N; i++) {
		cout << arrA[i] << ' ';
	}
	cout << '\n';

	cout << "[arrB]\n";
	for (int i = 0; i < N; i++) {
		cout << arrB[i] << ' ';
	}
	cout << '\n';
}