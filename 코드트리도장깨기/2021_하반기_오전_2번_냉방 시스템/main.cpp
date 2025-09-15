#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//좌상우하
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

const int MX = 20;

struct Point {
	int y;
	int x;
};

struct AirConditioner {
	Point p;
	int dir;
};

struct Node {
	Point p;
	int val;
};

bool is_wall[MX][MX][4];
int board[MX][MX];
int degree[MX][MX];
int next_degree[MX][MX];
bool visited[MX][MX];

vector<AirConditioner> aircons;
vector<Point> offices;

int n, m, k;
int ans;

void init();
void simulation();
void run(Point p, int dir);
void spread();
void decrease();

inline bool is_valid(Point& p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	simulation();

	if (ans == 100) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}

void init() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) {
				offices.push_back({ i, j });
			}
			else if (board[i][j] >= 2) {
				aircons.push_back({ i, j, board[i][j] - 2 });
			}
		}
	}

	int y, x, s;
	for (int i = 0; i < m; i++) {
		//k개의 벽 정보를 is_wall에 저장
		//0 -> (y, x) 상에 벽
		//  -> (y-1, x) 하에 벽
		//1 -> (y, x) 좌에 벽
		//  -> (y, x-1) 우에 벽
		cin >> y >> x >> s;
		y--; x--; //0-based-index
		if (s == 0) {
			is_wall[y][x][1] = true;
			is_wall[y - 1][x][3] = true;
		}
		else {
			is_wall[y][x][0] = true;
			is_wall[y][x - 1][2] = true;
		}
	}
}

void simulation() {
	while (ans < 100) {
		//1. 에어컨 런
		for (auto& acon : aircons) {
			run(acon.p, acon.dir);
		}
		//2. 공기 섞기
		spread();
		//3. 외벽 감소
		decrease();
		ans++;
		//4. 사무실 모든 곳이 k이상인지 검사
		bool flag = true;
		for (auto& p : offices) {
			if (degree[p.y][p.x] < k) {
				flag = false;
				break;
			}
		}
		if (flag) return;
	}
}


void run(Point p, int dir) {
	memset(visited, 0, sizeof(visited));

	queue<Node> Q;

	Point sp = { p.y + dy[dir], p.x + dx[dir] };

	visited[sp.y][sp.x] = true;
	degree[sp.y][sp.x] += 5;
	Q.push({sp, 5});

	Node now, next;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();

		//1. 직진
		if (!is_wall[now.p.y][now.p.x][dir]) {
			next.p = { now.p.y + dy[dir], now.p.x + dx[dir] };
			if (is_valid(next.p) && !visited[next.p.y][next.p.x]) {
				visited[next.p.y][next.p.x] = true;
				degree[next.p.y][next.p.x] += now.val - 1;
				if (now.val - 1 > 1) {
					Q.push({ next.p, now.val - 1 });
				}
			}
		}
		//2. 왼쪽 대각선
		//-45로 직진
		int tmpDir = (dir - 1 + 4) % 4;
		if (!is_wall[now.p.y][now.p.x][tmpDir]) {
			next.p = { now.p.y + dy[tmpDir], now.p.x + dx[tmpDir] };
			if (is_valid(next.p)) {
				if (!is_wall[next.p.y][next.p.x][dir]) {
					//직진
					next.p.y += dy[dir];
					next.p.x += dx[dir];
					if (is_valid(next.p) && !visited[next.p.y][next.p.x]) {
						visited[next.p.y][next.p.x] = true;
						degree[next.p.y][next.p.x] += now.val - 1;
						if (now.val - 1 > 1) {
							Q.push({ next.p, now.val - 1 });
						}
					}
				}
			}
		}

		//3. 오른쪽 대각선
		//+45로 직진
		tmpDir = (dir + 1) % 4;
		if (!is_wall[now.p.y][now.p.x][tmpDir]) {
			next.p = { now.p.y + dy[tmpDir], now.p.x + dx[tmpDir] };
			if (is_valid(next.p)) {
				//직진
				if (!is_wall[next.p.y][next.p.x][dir]) {
					next.p.y += dy[dir];
					next.p.x += dx[dir];
					if (is_valid(next.p) && !visited[next.p.y][next.p.x]) {
						visited[next.p.y][next.p.x] = true;
						degree[next.p.y][next.p.x] += now.val - 1;
						if (now.val - 1 > 1) {
							Q.push({ next.p, now.val - 1 });
						}
					}
				}
				
			}
		}
		
	}

}


void spread() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (degree[i][j] == 0) continue;

			Point np;
			for (int d = 0; d < 4; d++) {
				if (!is_wall[i][j][d]) {
					np.y = i + dy[d];
					np.x = j + dx[d];
					if (is_valid(np)) {
						int diff = degree[i][j] - degree[np.y][np.x];
						if (diff > 0) {
							next_degree[np.y][np.x] += diff / 4;
							next_degree[i][j] -= diff / 4;
						}
					}
					
				}
				
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			degree[i][j] += next_degree[i][j];
			next_degree[i][j] = 0;
		}
	}

}
void decrease() {
	for (int i = 0; i < n; i++) {
		if (degree[i][0] > 0) degree[i][0]--;
		if (degree[i][n - 1] > 0) degree[i][n - 1]--;
	}
	for (int j = 1; j < n - 1; j++) {
		if (degree[0][j] > 0) degree[0][j]--;
		if (degree[n - 1][j] > 0) degree[n - 1][j]--;
	}
}

inline bool is_valid(Point& p) {
	return p.y >= 0 && p.y < n && p.x >= 0 && p.x < n;
}
