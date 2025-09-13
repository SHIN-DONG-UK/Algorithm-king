#define WALL -1
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

//상좌하우
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };

struct Point {
	int y;
	int x;
};

struct Node {
	Point p;
	int dist;

	bool operator < (const Node& other) const {
		if (other.dist == dist) {
			if (other.p.y == p.y) return other.p.x < p.x;
			return other.p.y < p.y;
		}
		return other.dist < dist;
	}
};

const int MX = 20;
const int MX_C = MX * MX;


int n, m, c; Point taxi;
int board[MX + 1][MX + 1];
Point dst[MX_C]; int unused;
int visited[MX + 1][MX + 1];

void init();
void solve();

void move_near(int& dist, int& id);
int move_dst(int id);

void mprint();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << c << '\n';

	return 0;
}

void init() {
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				board[i][j] = WALL;
			}
		}
	}

	cin >> taxi.y >> taxi.x;

	int y1, x1, y2, x2;
	for (int i = 0; i < m; i++) {
		cin >> y1 >> x1 >> y2 >> x2;
		board[y1][x1] = ++unused;
		dst[unused] = { y2,x2 };
	}
}

void solve() {
	for (int i = 0; i < m; i++) {
		int dist1 = 0;
		int id = -1;
		
		//mprint();//[DEBUG]

		//1. 현재 위치에서 최단거리에 있는 승객을 태우러 간다
		move_near(dist1, id);   //taxi는 이미 update
		c -= dist1;
		if (c < 0) {
			c = -1;
			return;
		}
		//mprint();//[DEBUG]

		//2. 목적지에 데려다 준다
		int dist2 = move_dst(id);  //taxi는 이미 update
		c -= dist2;
		if (c < 0) {
			c = -1;
			return;
		}
		//mprint();//[DEBUG]

		//3. 이동거리의 두 배만큼 배터리를 충전한다
		c += dist2 * 2;
	}
}

void move_near(int& dist, int& id) {
	if (board[taxi.y][taxi.x] > 0) {
		dist = 0;
		id = board[taxi.y][taxi.x];
		board[taxi.y][taxi.x] = 0; //더 이상 이 승객은 유효하지 않음
		return;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = 1e9;
		}
	}

	//queue<Point> Q;
	priority_queue<Node> PQ;
	visited[taxi.y][taxi.x] = 0;
	PQ.push({ taxi, 0 });

	Node now, next;
	while (!PQ.empty()) {
		now = PQ.top(); PQ.pop();

		if (visited[now.p.y][now.p.x] < now.dist) continue; //dummy 컷

		if (board[now.p.y][now.p.x] > 0) {
			dist = now.dist;
			id = board[now.p.y][now.p.x];
			board[now.p.y][now.p.x] = 0; //더 이상 이 승객은 유효하지 않음
			taxi = now.p;
			return;
		}

		for (int d = 0; d < 4; d++) {
			next.p = { now.p.y + dy[d], now.p.x + dx[d] };
			if (next.p.y <= 0 || next.p.y > n || next.p.x <= 0 || next.p.x > n) continue;
			if (board[next.p.y][next.p.x] == WALL) continue;

			next.dist = now.dist + 1;
			if (visited[next.p.y][next.p.x] > next.dist) {
				visited[next.p.y][next.p.x] = next.dist;
				PQ.push(next);
			}
		}
	}
}

int move_dst(int id) {
	memset(visited, 0, sizeof(visited));
	Point e = dst[id];
	queue<Point> Q;
	visited[taxi.y][taxi.x] = 1;
	Q.push(taxi);

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y <= 0 || np.y > n || np.x <= 0 || np.x > n) continue;
			if (board[np.y][np.x] == WALL) continue;
			if (visited[np.y][np.x] > 0) continue;
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			Q.push(np);

			if (np.y == e.y && np.x == e.x) {
				taxi = e;
				return visited[cp.y][cp.x];
			}
		}
	}

	return int(1e9);
}

void mprint() {
	cout << '\n';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == taxi.y && j == taxi.x) cout << "* ";
			else cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}