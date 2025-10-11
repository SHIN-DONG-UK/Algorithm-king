#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N;
int arr[10000];
int diff;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();

		solve();

		cout << diff << '\n';
	}
	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	diff = 0;
}

void solve() {
	//1. 내림차순 정렬
	sort(arr, arr + N, greater<>());

	//2. 통나무 개수가 홀수 or 짝수
	if (N % 2 == 1) {
		diff = max(arr[0] - arr[1], arr[0] - arr[2]);

		for (int i = 1; i < N - 2; i+=2) {
			diff = max({ diff, arr[i] - arr[i + 2], arr[i + 1] - arr[i + 3] });
		}
	}
	else {
		for (int i = 0; i < N - 2; i += 2) {
			diff = max({ diff, arr[i] - arr[i + 2], arr[i + 1] - arr[i + 3] });
		}
	}
}