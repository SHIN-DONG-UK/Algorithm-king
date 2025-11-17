#include <iostream>
#include <algorithm>
using namespace std;

struct Beer {
	int v;
	int c;
};

int N, M, K;

Beer arr[200005];

void init();
void solve();
bool check(const int& level);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

bool compare(const Beer& a, const Beer& b) {
	return a.v > b.v;
}

void init() {
	cin >> N >> M >> K;
	for (int k = 0; k < K; k++) {
		cin >> arr[k].v >> arr[k].c;
	}

	sort(arr, arr + K, compare);
}

void solve() {
	long long left = 1;
	long long right = 1LL << 31;
	long long mid;

	int ans = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans << '\n';
}


bool check(const int& level) {
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		if (arr[i].c <= level) {
			cnt++;
			sum += arr[i].v;
		}

		if (cnt == N) {
			break;
		}
	}

	if (cnt < N) return false;
	if (sum >= M) return true;
	else return false;
}