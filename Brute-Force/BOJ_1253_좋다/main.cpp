#include <iostream>
#include <unordered_map>
using namespace std;

const int MX = 2000;

int N;
int arr[MX];
unordered_map<int, int> cnt;
int ans;

void init();
void solve();


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	
	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			int tmp = arr[i] - arr[j];
			cnt[arr[i]]--;
			cnt[arr[j]]--;
			
			if (cnt.count(tmp) > 0) {
				if (cnt[tmp] > 0) {
					ans++;
					flag = true;
				}
			}

			cnt[arr[j]]++;
			cnt[arr[i]]++;

			if (flag)
				break;
		}
	}
}