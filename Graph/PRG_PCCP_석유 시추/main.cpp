#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
};

struct Data {
	int id;
	int size;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

const int MAX_ROW = 500;
const int MAX_COL = 500;

int N, M;
int board[MAX_ROW][MAX_COL];
bool visited[MAX_ROW][MAX_COL];

Data board_data[MAX_ROW][MAX_COL];

void init();
void bfs(int id, Point sp);
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
}

void bfs(int id, Point sp) {
	visited[sp.y][sp.x] = true;

	stack<Point> stk;
	queue<Point> q;

	q.push(sp);

	Point np;
	
	while (!q.empty()) {
		Point now = q.front(); q.pop();
		
		stk.push(now);

		for (int d = 0; d < 4; d++) {
			np = { now.y + dy[d], now.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) {
				continue;
			}
			if (visited[np.y][np.x]) {
				continue;
			}
			if (board[np.y][np.x] == 0) {
				continue;
			}

			q.push(np);
			visited[np.y][np.x] = true;
		}
		
	}

	int size = stk.size();
	while (!stk.empty()) {
		Point p = stk.top(); stk.pop();
		board_data[p.y][p.x] = { id, size };
	}
}

void solve() {
	int id_cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0) {
				continue;
			}
			if (visited[i][j]) {
				continue;
			}
				
			Point p = { i, j };
			bfs(id_cnt++, p);
		}
	}

	bool check[MAX_ROW * MAX_COL] = { false, };
	int largest_val = 0;

	for (int j = 0; j < M; j++) {
		memset(check, 0, M * N);
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (board[i][j] == 0) {
				continue;
			}
			Data data = board_data[i][j];

			if (check[data.id]) {
				continue;
			}

			check[data.id] = true;
			sum += data.size;
		}

		if (largest_val < sum) {
			largest_val = sum;
		}
	}

	cout << largest_val << '\n';
}