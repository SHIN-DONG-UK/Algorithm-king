#define MAX_N 30

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 상 좌 우 하
int dy_move[4] = { -1,0,0,1 };
int dx_move[4] = { 0,-1,1,0 };

// 우 하 좌 상 가운데
int dy_clean[5] = { 0,1,0,-1,0 };
int dx_clean[5] = { 1,0,-1,0,0 };

// 청소할 격자 정의
// 1. 우
// 2. 하
// 3. 좌
// 4. 상
int dir_command[4][4] = {
	{3, 4, 0, 1},
	{2, 4, 0, 1},
	{3, 2, 4, 1},
	{3, 2, 4, 0}
};

struct Point {
	int y;
	int x;
};

vector<Point> robots;
int board[MAX_N + 1][MAX_N + 1];
int next_board[MAX_N + 1][MAX_N + 1];
int visited[MAX_N + 1][MAX_N + 1];

int N, K, L;

void init();
void solve();

void util_move(Point& robot);
void util_clean(Point& robot);
void util_accumulation();
void util_diffusion();
void util_output();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> K >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		Point robot = { 0,0 };
		cin >> robot.y >> robot.x;
		robots.push_back(robot);
	}
}

void solve() {
	while (L--) {
		for (Point& robot : robots) {
			util_move(robot);
		}
		for (Point& robot : robots) {
			util_clean(robot);
		}
		util_accumulation();
		util_diffusion();
		util_output();
	}
}

void util_move(Point& robot) {
	// 현재 위치에 먼지가 있으면 더 이상 이동하지 않고 종료.
	if (board[robot.y][robot.x] > 0) {
		return;
	}

	memset(visited, 0, sizeof(visited));
	// 로봇이 있는 위치들은 모두 visited 처리
	for (auto& p : robots) {
		visited[p.y][p.x] = 1e9;
	}

	// 1. 플러드필로 최단거리 기록 = O(N^2)
	queue<Point> Q;
	visited[robot.y][robot.x] = 1;
	Q.push(robot);

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front();
		Q.pop();

		for (int d = 0; d < 4; d++) {
			np.y = cp.y + dy_move[d];
			np.x = cp.x + dx_move[d];

			if(np.y <= 0 || np.y > N || np.x <= 0 || np.x > N) continue;
			if (visited[np.y][np.x] > 0) continue;
			if (board[np.y][np.x] < 0) continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			Q.push(np);
		}
	}

	// 2. 갈 수 있고 먼지가 있는 곳 중 가장 가까운 곳을 우선순위로 선택 = O(N^2)
	int dist = 1e9;
	Point next_p = { -1,-1 };

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] > 0 && visited[i][j] > 0) {
				if (dist > visited[i][j]) {
					dist = visited[i][j];
					next_p = { i,j };
				}
			}
		}
	}

	// 3. 로봇 이동 처리
	// 현재 칸도 먼지가 없고 어느 곳에도 로봇이 갈 수 없다면, next_p = {-1, -1}임
	// 이 경우에는 로봇 청소기가 가만히 있어야 하므로, 다음 조건문을 걸어야 함.
	if (next_p.y != -1 && next_p.x != -1) {
		robot = next_p;
	}
	
}

void util_clean(Point& robot) {
	// 1. 청소할 방향 탐색
	int max_sum = -1;
	int dir = -1;

	for (int d = 0; d < 4; d++) {
		int tmp_sum = 0;
		for (int k = 0; k < 4; k++) {
			int real_d = dir_command[d][k];
			int ny = robot.y + dy_clean[real_d];
			int nx = robot.x + dx_clean[real_d];
			
			if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
			
			int dust = board[ny][nx];
			if (dust < 0) continue;

			if (dust > 20) {
				tmp_sum += 20;
			}
			else {
				tmp_sum += dust;
			}
		}

		if (tmp_sum > max_sum) {
			max_sum = tmp_sum;
			dir = d;
		}
	}

	// 2. 청소 반영
	for (int k = 0; k < 4; k++) {
		int d = dir_command[dir][k];
		int ny = robot.y + dy_clean[d];
		int nx = robot.x + dx_clean[d];

		if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
		if (board[ny][nx] < 0) continue;

		if (board[ny][nx] > 20) {
			board[ny][nx] -= 20;
		}
		else {
			board[ny][nx] = 0;
		}
	}
}

void util_accumulation() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] > 0) {
				board[i][j] += 5;
			}
		}
	}
}

void util_diffusion() {
	memset(next_board, 0, sizeof(next_board));
	
	// 1. next_board에 확산되는 먼지 양을 기록
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == 0) {
				int sum = 0;
				for (int d = 0; d < 4; d++) {
					int ny = i + dy_clean[d];
					int nx = j + dx_clean[d];

					if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;

					int dust = board[ny][nx];

					if (dust > 0) {
						sum += dust;
					}
				}

				next_board[i][j] = sum / 10;
			}
		}
	}

	// 2. 실제 board에 확산된 먼지를 한번에 반영
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (next_board[i][j] > 0) {
				board[i][j] = next_board[i][j];
			}
		}
	}
}

void util_output() {
	int rst = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] > 0) {
				rst += board[i][j];
			}
		}
	}

	cout << rst << '\n';
}