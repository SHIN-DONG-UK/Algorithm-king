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
			for (int k = 1; k <= N + 2; k++)
				Check(i, j, k);
		}
	}
}

void Check(int cy, int cx, int k) {
	int cost = 0;
	int cnt = 0;
	
	for(int dy = -k + 1; dy < k; dy++){
		int row = cy + dy;
		int span = k - 1 - abs(dy);
		for(int dx = -span; dx < span + 1; dx++){
			int col = cx + dx;
			if (row < 0 || row >= N || col < 0 || col >= N)
				continue;
			if (map[row][col] == 1) {
					cost += M;
					cnt++;
			}
		}
		
	}
	if (cost >= k * k + (k - 1)*(k - 1))
		ans = max(ans, cnt);
}