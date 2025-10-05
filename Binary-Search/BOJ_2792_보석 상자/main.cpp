#include <iostream>
using namespace std;

int N, M;
int arr[300000];
int ans;

void init();
void solve();
bool check(const int& tar);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	
	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
}
void solve() {
	int l = 1; int r = 1e9;
	int mid;

	while (l <= r) {
		mid = (l + r) / 2;
		
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
}

bool check(const int& tar) {
	int nCount = 0;

	for (int i = 0; i < M; i++) {
		nCount += arr[i] / tar;
		if (arr[i] % tar > 0) nCount++;

		if (nCount > N) return false;
	}

	return true;
}