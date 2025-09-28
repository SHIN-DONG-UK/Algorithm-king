#include <iostream>
using namespace std;

int N;
int arr[21];
bool visited[2'000'001];

void init();
void solve();
void go(int idx, int sum);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
}

void go(int idx, int sum) {
	if (idx == N + 1) {
		visited[sum] = true;
		return;
	}

	go(idx + 1, sum + arr[idx]); //O
	go(idx + 1, sum);//X
}

void solve() {
	go(0, 0);

	for (int i = 1; i <= 2000000; i++) {
		if (!visited[i]) {
			cout << i << '\n';
			return;
		}
	}
}