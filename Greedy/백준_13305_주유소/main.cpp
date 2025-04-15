#include <iostream>
using namespace std;

int N;
long long DIST[100000];
long long PRICES[100000];
long long ans;

void input();
void solve();

int main() {
	input();
	solve();

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> DIST[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> PRICES[i];
	}
}

void solve() {
	int price = PRICES[0];
	ans += DIST[0] * price;

	for (int i = 1; i < N - 1; i++) {
		if (price > PRICES[i]) price = PRICES[i];
		ans += DIST[i] * price;
	}
}