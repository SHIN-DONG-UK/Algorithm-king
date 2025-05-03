#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y, x;
};

int N;
int board[100][100];
int visited_get_boundary[100][100];
int visited_already_boundary[100][100];
int visited_go_bfs[100][100];

int ans = (1 << 30);

vector<vector<Point>> boundarys;

void input();
void solve();
void get_boundary(Point sp, int group_id);
void go_bfs(int curr_id, vector<Point>& boundary);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solve();

	cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	boundarys.push_back(vector<Point>()); // dummy 0번째 (섬은 1부터 시작)
}

void solve() {
	int group = 1;

	// 각 섬을 번호로 구분하고 바운더리 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && visited_get_boundary[i][j] == 0) {
				get_boundary({ i,j }, group);
				group++;
			}
		}
	}

	// 각 섬의 boundary에서 BFS 수행
	for (int i = 1; i < boundarys.size(); i++) {
		memset(visited_go_bfs, 0, sizeof(visited_go_bfs));
		go_bfs(i, boundarys[i]);
	}
}

void get_boundary(Point sp, int group_id) {
	queue<Point> q;
	vector<Point> boundary;

	q.push(sp);
	visited_get_boundary[sp.y][sp.x] = 1;
	board[sp.y][sp.x] = group_id;

	while (!q.empty()) {
		Point cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			Point np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
			if (visited_get_boundary[np.y][np.x]) continue;

			if (board[np.y][np.x] == 1) {
				visited_get_boundary[np.y][np.x] = 1;
				board[np.y][np.x] = group_id;
				q.push(np);
			}
			else {
				if (visited_already_boundary[np.y][np.x] == 0) {
					visited_already_boundary[np.y][np.x] = 1;
					boundary.push_back(np);
				}
			}
		}
	}
	boundarys.push_back(boundary);
}

void go_bfs(int curr_id, vector<Point>& boundary) {
	queue<Point> q;

	for (Point p : boundary) {
		q.push(p);
		visited_go_bfs[p.y][p.x] = 1;
	}

	while (!q.empty()) {
		Point cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++) {
			Point np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;

			// 다른 섬에 도착했는지 확인
			if (board[np.y][np.x] != 0 && board[np.y][np.x] != curr_id) {
				ans = min(ans, visited_go_bfs[cp.y][cp.x]);
				return;
			}

			if (board[np.y][np.x] == 0 && visited_go_bfs[np.y][np.x] == 0) {
				visited_go_bfs[np.y][np.x] = visited_go_bfs[cp.y][cp.x] + 1;
				q.push(np);
			}
		}
	}
}
