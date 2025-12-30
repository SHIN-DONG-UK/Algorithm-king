#include <iostream>
using namespace std;

int N, M;
int arr_a[1000001];
int arr_b[1000001];

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
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr_a[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> arr_b[i];
	}
}

void solve() {
	int idx_a = 0;
	int idx_b = 0;

	while (!((idx_a == N) && (idx_b == M))) {
		if (idx_a == N) {
			cout << arr_b[idx_b] << ' ';
			idx_b++;
		}
		else if (idx_b == M) {
			cout << arr_a[idx_a] << ' ';
			idx_a++;
		}
		else if (arr_a[idx_a] < arr_b[idx_b]) {
			cout << arr_a[idx_a] << ' ';
			idx_a++;
		}
		else {
			cout << arr_b[idx_b] << ' ';
			idx_b++;
		}
	}
}