#include <iostream>
using namespace std;

int H, W;
int heights[505];

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
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> heights[i];
	}
}

void solve() {
	int sum = 0;

	for (int i = 1; i < W - 1; i++) {

		int left_max = 0;
		int right_max = 0;

		// 1. 왼쪽 최댓값
		for (int j = 0; j < i; j++) {
			if (heights[j] > left_max) 
				left_max = heights[j];
		}

		// 2. 오른쪽 최댓값
		for (int j = i + 1; j < W; j++) {
			if (heights[j] > right_max)
				right_max = heights[j];
		}

		int diff = min(left_max, right_max) - heights[i];

		if (diff > 0)
			sum += diff;
	}

	cout << sum << '\n';
}