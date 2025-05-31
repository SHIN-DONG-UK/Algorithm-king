#define WALL -9999
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
};

struct Rbfs {
	int dist;
	Point p;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M, fuel;
int board[21][21]; // 1-based index
Point epList[401]; // 1-based index

Point pTaxi;

void input();
int simulation();

// [input] mode 0 : 시작점 / mode 음수 => 도착점 번호
// [output] 움직인 거리 / 만약 실패했다면 1e9
Rbfs goto_customer(); 
Rbfs goto_dest(Point dest);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	int ans = simulation();

	cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N >> M >> fuel;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) board[i][j] = WALL;
		}
	}

	cin >> pTaxi.y >> pTaxi.x;
	int sy, sx, ey, ex;
	for (int idx = 1; idx <= M; idx++) {
		cin >> sy >> sx >> ey >> ex;
		board[sy][sx] = idx;
		epList[idx] = { ey, ex };
	}
}

int simulation() {
	while (M--) {
		Rbfs r = goto_customer();

		if (r.dist == -1) return -1;
		if (fuel - r.dist < 0) return -1;

		int idx = board[r.p.y][r.p.x]; // 승객 인덱스
		board[r.p.y][r.p.x] = 0;	   // 맵에서 제거
		fuel -= r.dist;				   // 연료 감소
		pTaxi = r.p;				   // 택시 이동

		r = goto_dest(epList[idx]);

		if (r.dist == -1) return -1;
		if (fuel - r.dist < 0) return -1;

		fuel -= r.dist;				   // 연료 감소
		pTaxi = r.p;				   // 택시 이동

		// 연료 리필
		fuel += (2 * r.dist);
	}

	return fuel;
}

Rbfs goto_customer() {
	int visited[21][21] = { 0, };
	memset(visited, -1, sizeof(visited));

	// 현재 위치에 승객이 있다면 -> 도착지로 이동한 곳이 승객이 있는 경우
	if (board[pTaxi.y][pTaxi.x] > 0)
		return { 0, pTaxi };

	queue<Point> q;
	q.push(pTaxi);
	visited[pTaxi.y][pTaxi.x] = 0;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y <= 0 || np.y > N || np.x <= 0 || np.x > N) continue;
			if (board[np.y][np.x] == WALL) continue;
			if (visited[np.y][np.x] >= 0) continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}

	int min_val = 1e9;
	Point pMin = { -1,-1 };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] <= 0) continue;
			if (min_val > visited[i][j]) {
				min_val = visited[i][j];
				pMin = { i, j };
			}
		}
	}
	return { min_val, pMin };
}

Rbfs goto_dest(Point dest) {
	int visited[21][21] = { 0, };
	memset(visited, -1, sizeof(visited));

	queue<Point> q;
	q.push(pTaxi);
	visited[pTaxi.y][pTaxi.x] = 0;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y <= 0 || np.y > N || np.x <= 0 || np.x > N)continue;
			if (board[np.y][np.x] == WALL) continue;
			if (visited[np.y][np.x] >= 0) continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);

			if (np.y == dest.y && np.x == dest.x) {
				return { visited[np.y][np.x], dest };
			}
		}

	}
	// 도착지가 벽으로 막혀있을 수 있음
	return { -1, dest };
}