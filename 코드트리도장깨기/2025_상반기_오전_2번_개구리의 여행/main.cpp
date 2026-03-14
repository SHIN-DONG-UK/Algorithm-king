#define MAX_N 50

#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

struct Node {
	Point p;
	int cost;
	int jump;

	bool operator<(const Node& other) const {
		return other.cost < cost;
	}
};

int N, Q;
char board[MAX_N + 1][MAX_N + 1];
int best[MAX_N + 1][MAX_N + 1][6];

void init();
void solve();

void init_best();
int dijkstra(Point sp, Point ep);
bool check(Point p, int dir, int cnt);
void debug_print(Point now);
int calc(int target, int now);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	cin >> Q;
}

void solve() {
	int sy, sx, ey, ex;
	while (Q--) {
		cin >> sy >> sx >> ey >> ex;
		int rst = dijkstra({ sy, sx }, { ey, ex });
		cout << rst << '\n';
	}
}

int dijkstra(Point sp, Point ep) {
	init_best();

	priority_queue<Node> PQ;
	best[sp.y][sp.x][1] = 0;
	PQ.push({ sp, 0, 1 });

	while (!PQ.empty()) {
		Node top = PQ.top(); PQ.pop();

		//debug_print(top.p);

		// dummy 컷
		if (top.cost > best[top.p.y][top.p.x][top.jump]) continue;
		
		if (top.p.y == ep.y && top.p.x == ep.x) {
			//debug_print(top.p);
			return top.cost;
		}

		int nCost = 0;
		// 점프력
		for (int j = 1; j <= 5; j++) {
			if (j < top.jump) { nCost = top.cost + 2; }
			else if (j > top.jump) { nCost = top.cost + calc(j, top.jump) + 1; }
			else { nCost = top.cost + 1; }


			// 방향
			for (int d = 0; d < 4; d++) {
				Point np = { top.p.y + dy[d] * j, top.p.x + dx[d] * j };
				
				if (np.y <= 0 || np.y > N || np.x <= 0 || np.x > N) continue;
				if (board[np.y][np.x] == 'S') continue;
				if (!check(top.p, d, j)) continue;
				if (best[np.y][np.x][j] > nCost) {
					best[np.y][np.x][j] = nCost;
					PQ.push({ np, nCost, j });
				}
			}
		}
	}

	return -1;
}

void init_best() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= 5; k++) {
				best[i][j][k] = 1e9;
			}
		}
	}
}

bool check(Point p, int dir, int cnt) {
	for (int i = 1; i <= cnt; i++) {
		p.y += dy[dir];
		p.x += dx[dir];
		if (board[p.y][p.x] == '#') return false;
	}
	return true;
}

void debug_print(Point now) {
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == now.y && j == now.x) {
				cout << "F ";
			}
			else {
				cout << board[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

int calc(int target, int now) {
	int sum1 = target * (target + 1) * (2 * target + 1) / 6;
	int sum2 = now * (now + 1) * (2 * now + 1) / 6;
	return sum1 - sum2;
}