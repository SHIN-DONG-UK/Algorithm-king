#include <iostream>

using namespace std;

long long S;
long long number = 1;

void input();
void solve();

int main() {
	input();
	solve();

	cout << number - 1 << '\n';
}

void input() {
	cin >> S;
}

void solve() {
	long long sum = 0;
	while (true) {
		sum += number;
		if (sum > S) break;
		number++;
	}
}