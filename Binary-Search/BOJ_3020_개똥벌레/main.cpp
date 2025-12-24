#include <iostream>
#include <algorithm>
using namespace std;

int N, H;
int arr_ss[100001];
int arr_jys[100001];
int arr_cnt[200001];

void init();
void solve();

int lower_bound(int* p, int h);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> H;

	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			cin >> arr_jys[i / 2];
		}
		else {
			cin >> arr_ss[i / 2 + 1];
		}
	}

	sort(arr_ss + 1, arr_ss + N / 2 + 1);
	sort(arr_jys + 1, arr_jys + N / 2 + 1);
}

void solve() {
	int b = N / 2 + 1;
	for (int h = 1; h <= H; h++) {
		int collision_cnt_ss = b - lower_bound(arr_ss, h);
		int collision_cnt_jys = b - lower_bound(arr_jys, H - h + 1);

		arr_cnt[collision_cnt_ss + collision_cnt_jys]++;
	}

	for (int i = 0; i <= N; i++) {
		if (arr_cnt[i] > 0) {
			cout << i << ' ' << arr_cnt[i] << '\n';
			return;
		}
	}
}

int lower_bound(int* p, int h) {
	int left = 0;
	int right = N / 2;

	int mid;
	int rst = N / 2 + 1;

	while (left <= right) {
		mid = (left + right) / 2;

		if (p[mid] >= h) {
			//왼쪽 범위 탐색
			rst = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return rst;
}