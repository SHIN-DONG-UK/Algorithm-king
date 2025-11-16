#include <iostream>
using namespace std;

struct Vec {
	long long x;
	long long y;
};

int N;
Vec arr[1500];
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
		cin >> arr[i].x >> arr[i].y;
	}
}

void solve() {
	Vec v1, v2;
	for (int i = 0; i < N - 2; i++) { // 점 A
		for (int j = i + 1; j < N - 1; j++) { // 점 B
			for (int k = j + 1; k < N; k++) { // 점 C
				// 1. A각 검사
				v1 = { arr[j].x - arr[i].x, arr[j].y - arr[i].y };
				v2 = { arr[k].x - arr[i].x, arr[k].y - arr[i].y };
				if (v1.x * v2.x + v1.y * v2.y == 0) {
					ans++;
					continue;
				}
				// 2. B각 검사
				v1 = { arr[i].x - arr[j].x, arr[i].y - arr[j].y };
				v2 = { arr[k].x - arr[j].x, arr[k].y - arr[j].y };
				if (v1.x * v2.x + v1.y * v2.y == 0) {
					ans++;
					continue;
				}

				// 3. C각 검사
				v1 = { arr[i].x - arr[k].x, arr[i].y - arr[k].y };
				v2 = { arr[j].x - arr[k].x, arr[j].y - arr[k].y };
				if (v1.x * v2.x + v1.y * v2.y == 0) {
					ans++;
					continue;
				}
			}
		}
	}
}