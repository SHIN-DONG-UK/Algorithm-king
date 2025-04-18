#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M;
int map[20][20];
int ans;

void Init();
void Input();
void Solve();
void Check(int cy, int cx, int k);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		ans = 0;
		Input();
		Solve();
		
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
}

void Solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 1; k <= 22; k++)
				Check(i, j, k);
		}
	}
}

void Check(int cy, int cx, int k) {
	int cost = 0;
	int cnt = 0;
	
	for (int i = cy-k; i <= cy+k; i++) {
		for (int j = cx-k; j <= cx+k; j++) {
			if (i < 0 || i >= N || j < 0 || j >= N)
				continue;
			// 마름모 범위에 들어가는 좌표들
			if (abs(i - cy) + abs(j - cx) <= k - 1) {
				if (map[i][j] == 1) {
					cost += M;
					cnt++;
				}
					
			}
		}
	}
	if (cost >= k * k + (k - 1)*(k - 1))
		ans = max(ans, cnt);
}