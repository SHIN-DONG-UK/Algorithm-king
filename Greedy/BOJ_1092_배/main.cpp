#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int cranes[55];
int boxes[10005];
bool is_removed[10005];

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
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cranes[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> boxes[i];
	}

	sort(cranes, cranes + N, greater<>());
	sort(boxes, boxes + M, greater<>());
}

void solve() {
	int cnt = 0;
	while (1) {
		bool flag = false;
		int idx = 0;
		for (int j = 0; j < M; j++) {
			if (idx == N) break;

			if (is_removed[j]) continue;

			if (cranes[idx] >= boxes[j]) {
				is_removed[j] = true;
				idx++;
				flag = true;
			}
		}
		
		if (!flag) break;

		cnt++;
	}

	bool flag2 = false;
	for (int j = 0; j < M; j++) {
		if (!is_removed[j]) {
			flag2 = true;
			break;
		}
	}
	if (flag2) cout << "-1\n";
	else cout << cnt << '\n';

}