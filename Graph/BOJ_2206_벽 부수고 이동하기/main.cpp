#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int y;
	int x;
	bool stat;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char map[1001][1001];
int dist[1001][1001][2];

void input();
void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solution();

	if (dist[N - 1][M - 1][0] == 0 && dist[N - 1][M - 1][1] == 0) cout << -1 << '\n';
	else if (dist[N - 1][M - 1][0] == 0) cout << dist[N - 1][M - 1][1] << '\n';
	else if (dist[N - 1][M - 1][1] == 0) cout << dist[N - 1][M - 1][0] << '\n';
	else cout << min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]) << '\n';

	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}
}

void solution() {
	queue<Node> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = dist[0][0][1] = 1;

	Node cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = cur.y + dy[d];
			int nx = cur.x + dx[d];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (dist[ny][nx][cur.stat] > 0) continue;

			// 길이면, 그대로 진행
			if (map[ny][nx] == '0') {
				dist[ny][nx][cur.stat] = dist[cur.y][cur.x][cur.stat] + 1;
				q.push({ny, nx, cur.stat});
			}
			// 벽인데 아직 부순 적 없으면 진행
			else if (map[ny][nx] == '1' && cur.stat == false) {
				dist[ny][nx][1] = dist[cur.y][cur.x][0] + 1;
				q.push({ny, nx, 1});
			}
		}
	}
}