#include <iostream>
using namespace std;

int N;
int arr[10];
bool visited[10];
int maxi;

void init();
void go(int idx, int sum);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	go(1, 0);

	cout << maxi << '\n';

	return 0;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	maxi = 0;
}

void go(int idx, int sum) {
	if (idx == N - 1) {
		if (maxi < sum) {
			maxi = sum;
		}
		return;
	}

	for (int i = 1; i < N - 1; i++) {
		if (visited[i]) continue;
		visited[i] = true;

		int tmp = 1;
		int j = i - 1;
		while (visited[j]) { j--; }
		tmp *= arr[j];
		j = i + 1;
		while (visited[j]) { j++; }
		tmp *= arr[j];

		go(idx + 1, sum + tmp);
		visited[i] = false;
	}

}