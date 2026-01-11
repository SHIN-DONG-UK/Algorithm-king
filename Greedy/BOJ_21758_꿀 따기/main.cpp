#include <iostream>
using namespace std;

int N;
int arr[100001];
int sum[100001];
int g_max;

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

	int s = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		
		s += arr[i];
		sum[i] = s;
	}
}

void solve() {
	// 1. 벌------벌통, 나머지 벌 어딘가
	int fixed = sum[N] - arr[1];
	for (int i = 2; i < N; i++) {
		int tmp = fixed - arr[i] + sum[N] - sum[i];
		if (g_max < tmp) {
			g_max = tmp;
		}
	}
	// 2. 벌통------벌, 나머지 벌 어딘가
	fixed = sum[N] - arr[N];
	for (int i = 2; i < N; i++) {
		int tmp = fixed - arr[i] + sum[i] - arr[i];
		if (g_max < tmp) {
			g_max = tmp;
		}
	}

	// 3. 벌--------벌, 벌통 어딘가
	for (int i = 2; i < N; i++) {
		int tmp = sum[i] - arr[1] + sum[N - 1] - sum[i - 1];
		if (g_max < tmp) {
			g_max = tmp;
		}
	}

	cout << g_max << '\n';
}