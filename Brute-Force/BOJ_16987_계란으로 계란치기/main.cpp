#include <iostream>
using namespace std;

int N;
int status[8];
int weight[8];

int max_val;

void init();
void go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	go(0);

	cout << max_val << '\n';

	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> status[i] >> weight[i];
	}
}

void go(int idx) {
	if (idx == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (status[i] <= 0) {
				cnt++;
			}
		}

		if (max_val < cnt) {
			max_val = cnt;
		}

		return;
	}

	if (status[idx] <= 0) {
		go(idx + 1);
		return;
	}

	bool flag = false;
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (status[i] <= 0) continue;
		flag = true;

		status[i] -= weight[idx];
		status[idx] -= weight[i];
		go(idx + 1);
		status[idx] += weight[i];
		status[i] += weight[idx];
	}

	if (!flag) {
		go(idx + 1);
		return;
	}
}