#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
bool light[101][101];	 // 불이 켜진 곳인지
bool visited[101][101];  // BFS용 방문 배열
vector<Point> alist[101][101]; // 그래프(인접리스트)

void input();
void solution();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solution();

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (light[i][j] == 1)
				ans++;
		}
	}

	cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N >> M;
	int y, x, b, a;
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> b >> a;
		alist[y][x].push_back({ b,a });
	}
}

void solution() {
	queue<Point> q;
	q.push({ 1,1 });
	visited[1][1] = 1;
	light[1][1] = 1;

	Point cp;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		// 전처리 : 불켜기
		for (auto& p : alist[cp.y][cp.x]) {
			if (!light[p.y][p.x]) {
				light[p.y][p.x] = 1;
				// 방문 가능한지 확인
				for (int d = 0; d < 4; d++) {
					int ny = p.y + dy[d];
					int nx = p.x + dx[d];
					if (ny > 0 && ny <= N && nx > 0 && nx <= N && visited[ny][nx]) {
						visited[p.y][p.x] = 1;
						q.push(p);
						break;
					}
				}
			}
		}

		// BFS 탐색
		for (int d = 0; d < 4; d++) {
			int ny = cp.y + dy[d];
			int nx = cp.x + dx[d];
			if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
			if (visited[ny][nx]) continue;
			if (light[ny][nx] == 0) continue;
			visited[ny][nx] = 1;
			q.push({ ny, nx });
		}
	}

}