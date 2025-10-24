#include <iostream>
using namespace std;

int k, S;
int arr[13];
bool visited[3000000];

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
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		S += arr[i];
	}
}

void solve() {
	go(1, arr[0]);
	go(1, 0);
	go(1, -arr[0]);

	int cnt = 0;
	for (int i = 1; i <= S; i++) {
		if (!visited[i])
			cnt++;
	}

	cout << cnt << '\n';
}

void go(int idx, int sum) {
	if (idx == k) {
		if (sum > 0) {
			visited[sum] = true;
			//cout << sum << '\n';
		}
			
		return;
	}

	go(idx + 1, sum + arr[idx]); // 오른쪽에 무게 추
	go(idx + 1, sum);			 // 무게 추를 달지 않음
	go(idx + 1, sum - arr[idx]); // 왼쪽에 무게 추
}