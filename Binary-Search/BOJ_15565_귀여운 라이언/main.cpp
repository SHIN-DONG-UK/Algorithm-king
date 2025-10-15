#include <iostream>
using namespace std;

int N, K;
int acumulArr[1000001]; // 1-based index
int mini;

void init();
void solve();
bool test(const int& now);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	if (mini == 1e9) mini = -1;

	cout << mini << '\n';

	return 0;
}

void init() {
	cin >> N >> K;

	int tmp = 0;
	int acu = 0;
	for (int i = 1; i <= N; i++) {
		cin >> tmp;

		if (tmp == 1) { acu++; }

		acumulArr[i] = acu;
	}

	mini = 1e9;
}

void solve() {
	int left = K; 
	int right = N;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (test(mid)) {
			mini = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
}

bool test(const int& now) {
	for (int i = now; i <= N; i++) {
		if (acumulArr[i] - acumulArr[i - now] >= K) {
			return true;
		}
	}
	return false;
}