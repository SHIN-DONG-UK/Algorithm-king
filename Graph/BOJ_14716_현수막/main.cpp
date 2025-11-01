#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M;
int board[250][250];
bool visited[250][250];

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
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
}

void solve() {
	int cnt = 0;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			if (visited[i][j]) continue;

			queue<Point> Q;
			Q.push({ i, j });
			visited[i][j] = true;

			Point cp, np;
			while (!Q.empty()) {
				cp = Q.front(); Q.pop();
				for (int d = 0; d < 8; d++) {
					np = { cp.y + dy[d], cp.x + dx[d] };
					if (np.y < 0 || np.y >= M || np.x < 0 || np.x >= N)
						continue;
					if (board[np.y][np.x] == 0)
						continue;
					if (visited[np.y][np.x])
						continue;
					
					visited[np.y][np.x] = true;
					Q.push(np);
				}
			}

			cnt++;
		}
	}

	cout << cnt << '\n';
}