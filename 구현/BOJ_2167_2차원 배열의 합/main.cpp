#include <iostream>
using namespace std;


int N, M, K;
int arr[301][301];
int S[301][301];

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
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		int row_sum = 0;

		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];

			row_sum += arr[i][j];

			S[i][j] = S[i - 1][j] + row_sum;
		}
	}

	cin >> K;
}

void solve() {
	int i, j, x, y;
	
	while (K--) {
		cin >> i >> j >> x >> y;
		int T = S[x][y] - S[i - 1][y] - S[x][j - 1] + S[i - 1][j - 1];

		cout << T << '\n';
	}
}