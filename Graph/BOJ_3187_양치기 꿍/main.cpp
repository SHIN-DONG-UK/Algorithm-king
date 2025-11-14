#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

int R, C;
char board[255][255];
bool visited[255][255];
int global_sheep, global_woolf;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	
	cout << global_sheep << ' ' << global_woolf << '\n';


	return 0;
}

void init() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}
}

void solve() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j]) continue;
			if (board[i][j] == '#') continue;

			int local_sheep = 0;
			int local_woolf = 0;

			queue<Point> Q;
			visited[i][j] = true;
			Q.push({ i, j });

			if (board[i][j] == 'k')
				local_sheep++;
			else if (board[i][j] == 'v')
				local_woolf++;

			Point cp, np;
			while (!Q.empty()) {
				cp = Q.front(); Q.pop();
				for (int d = 0; d < 4; d++) {
					np = { cp.y + dy[d], cp.x + dx[d] };
					if (np.y < 0 || np.y >= R || np.x < 0 || np.x >= C) continue;
					if (board[np.y][np.x] == '#') continue;
					if (visited[np.y][np.x]) continue;

					visited[np.y][np.x] = true;
					Q.push(np);

					if (board[np.y][np.x] == 'k')
						local_sheep++;
					else if (board[np.y][np.x] == 'v')
						local_woolf++;
				}
			}

			if (local_sheep > local_woolf)
				global_sheep += local_sheep;
			else
				global_woolf += local_woolf;
		}
	}
}