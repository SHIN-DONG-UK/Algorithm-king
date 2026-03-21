#include <iostream>
using namespace std;

// 1-based index
int mountains[550001]; int len;
int lisList[550001];

long long simulation(int m);
int lower_bound(int len, int tar);
int upper_bound(int len, int tar);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;
	while (Q--) {
		int cmd;
		cin >> cmd;

		if (cmd == 100) {
			int n;
			cin >> n;
			for (int i = 1; i <= n; i++) {
				cin >> mountains[i];
			}
			len = n;
		}
		else if (cmd == 200) {
			int h;
			cin >> h;
			mountains[++len] = h;
		}
		else if (cmd == 300) {
			mountains[len--] = 0;
		}
		else if (cmd == 400) {
			int m;
			cin >> m;
			long long rst = simulation(m);
			cout << rst << '\n';
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

long long simulation(int m) {
	long long rst = 0;

	int lisLen = 0;
	lisList[++lisLen] = mountains[m];

	// 1. m부터 1까지 가장 긴 감소하는 부분 수열
	for (int i = m - 1; i >= 1; i--) {
		if (mountains[i] > mountains[m]) continue;

		if (mountains[i] < lisList[lisLen]) {
			lisList[++lisLen] = mountains[i];
		}
		else {
			int idx = upper_bound(lisLen, mountains[i]);
			lisList[idx] = mountains[i];
		}
	}
	rst += 1000000LL * lisLen;

	// 2. 0부터 끝까지 LIS
	lisLen = 0;
	lisList[++lisLen] = mountains[1];

	int max_height = 0;

	for (int i = 2; i <= len; i++) {
		if (mountains[i] > lisList[lisLen]) {
			lisList[++lisLen] = mountains[i];
			max_height = mountains[i]; // 길이가 길어지면 max_height는 강제 변경
		}
		else {
			// 중간에 끼워넣든가, 끝에 끼워넣든가
			int idx = lower_bound(lisLen, mountains[i]);
			max_height = max(max_height, lisList[idx]);
			lisList[idx] = mountains[i];
		}
	}

	rst += 1000000LL * (lisLen - 1);
	rst += max(max_height, lisList[lisLen]);

	return rst;
}

int lower_bound(int len, int tar) {
	int rst = -1;

	int left = 1; int right = len;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (lisList[mid] >= tar) {
			right = mid - 1;
			rst = mid;
		}
		else{
			left = mid + 1;
		}
	}

	return rst;
}

int upper_bound(int len, int tar) {
	int rst = -1;
	int left = 1; int right = len;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		if (lisList[mid] <= tar) {
			right = mid - 1;
			rst = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return rst;
}