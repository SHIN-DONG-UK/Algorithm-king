#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int M, N;
char map[1001][1001];
bool visited[1001][1001];

void input();
bool bfs(Point sp);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();

	for (int j = 0; j < N; j++) {
		Point sp = { 0, j };
		if (map[sp.y][sp.x] == '1')
			continue;

		if (bfs(sp)) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

void input() {
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		cin >> map[i];
}

bool bfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= M || np.x < 0 || np.x >= N) continue;
			if (visited[np.y][np.x]) continue;
			if (map[np.y][np.x] == '1') continue;
			visited[np.y][np.x] = 1;
			q.push(np);

			if (np.y == M - 1)
				return true;
		}
	}
	return false;
}