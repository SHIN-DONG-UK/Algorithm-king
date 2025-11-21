#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
	int y;
	int x;
};

struct Node {
	Point p;
	int dist;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char board[51][51];
bool visited[51][51];
int global_max;

vector<vector<Point>> cluster;

void init();
void solve();
void get_cluster();
void init_visited(vector<Point>& v);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << global_max << '\n';
	return 0;
}

void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	get_cluster();

	global_max = 0;
}

void get_cluster() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			if (board[i][j] == 'W') continue;

			vector<Point> v;
			v.push_back({ i,j });

			queue<Point> Q;
			Q.push({ i, j });
			visited[i][j] = true;

			Point cp, np;
			while (!Q.empty()) {
				cp = Q.front(); Q.pop();
				for (int d = 0; d < 4; d++) {
					np = { cp.y + dy[d], cp.x + dx[d] };
					if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
					if (board[np.y][np.x] == 'W') continue;
					if (visited[np.y][np.x]) continue;
					visited[np.y][np.x] = true;
					Q.push(np);

					v.push_back(np);
				}
			}
			
			cluster.push_back(v);
		}
	}
}

void solve() {
	for (auto& v : cluster) {
		for (auto& p : v) {
			init_visited(v);

			int local_max = 0;
			queue<Node> Q;
			Q.push({ p, 0 });
			visited[p.y][p.x] = 1;

			Node cn, nn;
			while (!Q.empty()) {
				cn = Q.front(); Q.pop();

				for (int d = 0; d < 4; d++) {
					nn.p = { cn.p.y + dy[d], cn.p.x + dx[d] };
					if (nn.p.y < 0 || nn.p.y >= N || nn.p.x < 0 || nn.p.x >= M) continue;
					if (board[nn.p.y][nn.p.x] == 'W') continue;
					if (visited[nn.p.y][nn.p.x]) continue;

					visited[nn.p.y][nn.p.x] = true;
					nn.dist = cn.dist + 1;
					Q.push(nn);

					if (local_max < nn.dist)
						local_max = nn.dist;
				}
			}

			if (local_max > global_max)
				global_max = local_max;
		}
	}
}

void init_visited(vector<Point>& v) {
	for (auto& p : v) { visited[p.y][p.x] = false; }
}