#define MAX_N 50
#define LEFT_UP 0
#define RIGHT_UP 1
#define RIGHT_DOWN 2
#define LEFT_DOWN 3

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 상하좌우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ddy[4] = { -1,-1,1,1 };
int ddx[4] = { -1,1,1,-1 };

int dy3[4][3] = {
	{-1, -1, -1},
	{1, 1, 1,},
	{-1, 0, 1},
	{-1, 0, 1}
};
int dx3[4][3] = {
	{-1,0,1},
	{-1,0,1},
	{-1,-1,-1},
	{1,1,1}
};


struct Point {
	int y;
	int x;
};

int N, M;
int board[MAX_N][MAX_N];
int next_board[MAX_N][MAX_N];
bool mask_road[MAX_N][MAX_N];
bool mask_gaze[4][MAX_N][MAX_N];
int mask_ff[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

vector<Point> pVec[4];
Point mPos, parkPos;
int mDir;

void init();
void solve();

int maedoosa_move(); // 도달할 수 없으면 -1, 공원에 도달했으면 0, 아니면 1
void maedoosa_gaze();
void worrier_move();

// dd=대각선 index
void bfs2(int dir, Point sp, int dd);

void debug_print();
void debug_gaze(int dir);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N >> M;
	cin >> mPos.y >> mPos.x >> parkPos.y >> parkPos.x;

	int y, x;
	for (int i = 1; i <= M; i++) {
		cin >> y >> x;

		board[y][x]++;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mask_road[i][j];
		}
	}

	// 1. 공원을 시작점으로 플러드 필
	queue<Point> Q;
	Q.push(parkPos);
	mask_ff[parkPos.y][parkPos.x] = 1;

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			np.y = cp.y + dy[d];
			np.x = cp.x + dx[d];

			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
			if (mask_ff[np.y][np.x] > 0) continue;
			if (mask_road[np.y][np.x]) continue;

			mask_ff[np.y][np.x] = mask_ff[cp.y][cp.x] + 1;
			Q.push(np);
		}
	}
}

void solve() {
	// 메두사가 도달할 수 있는지 체크
	if (mask_ff[mPos.y][mPos.x] == 0) {
		cout << "-1\n";
		return;
	}

	while (true) {
		int tmp = maedoosa_move();
		if (tmp == 0) {
			cout << tmp << '\n';
			return;
		}
		maedoosa_gaze();
		worrier_move();
	}
}

// [return] 공원에 도달했으면 0, 아니면 1
int maedoosa_move() {
	// 1. 이동
	int min_val = MAX_N * MAX_N;
	int dir = -1;

	for (int d = 0; d < 4; d++) {
		int ny = mPos.y + dy[d];
		int nx = mPos.x + dx[d];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (mask_ff[ny][nx] == 0) continue;
		if (min_val > mask_ff[ny][nx]) {
			min_val = mask_ff[ny][nx];
			dir = d;
		}
	}

	if (dir == -1) return -1;

	mPos.y += dy[dir];
	mPos.x += dx[dir];

	if (parkPos.y == mPos.y && parkPos.x == mPos.x) {
		return 0;
	}
	// 메두사의 공격을 받은 전사 제거
	board[mPos.y][mPos.x] = 0;
	return 1;
}

void maedoosa_gaze() {
	memset(mask_gaze, 0, sizeof(mask_gaze));
	
	for (int d = 0; d < 4; d++) {
		pVec[d].clear();

		// 1. 일단 전사를 무시하고 시선 처리
		queue<Point> Q;
		Q.push(mPos);
		mask_gaze[d][mPos.y][mPos.x] = true;

		Point cp, np;
		while (!Q.empty()) {
			cp = Q.front(); Q.pop();
			for (int d3 = 0; d3 < 3; d3++) {
				np.y = cp.y + dy3[d][d3];
				np.x = cp.x + dx3[d][d3];

				if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
				if (mask_gaze[d][np.y][np.x]) continue;
				
				mask_gaze[d][np.y][np.x] = true;
				Q.push(np);

				if (board[np.y][np.x] > 0) {
					pVec[d].push_back(np);
				}
			}
		}
		mask_gaze[d][mPos.y][mPos.x] = false;

		// 2. 전사를 고려한 시선 처리로 수정
		for (Point& p : pVec[d]) {
			if (p.y == mPos.y) {
				// 좌
				if (p.x < mPos.x) { 
					bfs2(d, p, -1); 
				}
				// 우
				else {
					bfs2(d, p, -1);
				}
			}
			else if (p.x == mPos.x) {
				// 상
				if (p.y < mPos.y) {
					bfs2(d, p, -1);
				}
				// 하
				else {
					bfs2(d, p, -1);
				}
			}
			else {
				// 1사 = 좌상
				if (p.y < mPos.y && p.x < mPos.x) {
					bfs2(d, p, LEFT_UP);
				}
				// 2사 = 우상
				else if (p.y < mPos.y && p.x > mPos.x) {
					bfs2(d, p, RIGHT_UP);
				}
				// 3사 = 우하
				else if (p.y > mPos.y && p.x > mPos.x) {
					bfs2(d, p, RIGHT_DOWN);
				}
				// 4사 = 좌하
				else {
					bfs2(d, p, LEFT_DOWN);
				}
			}
		}
		
	}

	mDir = 0;
	// 3. 기절한 전사가 가장 많은 방향 찾기
	int max_stone = -1;
	for (int d = 0; d < 4; d++) {
		int tmp = 0;
		for (Point& p : pVec[d]) {
			if (!mask_gaze[d][p.y][p.x]) continue;
			tmp += board[p.y][p.x];
		}

		if (tmp > max_stone) {
			max_stone = tmp;
			mDir = d;
		}
	}
}

void worrier_move() {
	memset(next_board, 0, sizeof(next_board));

	int total_dist = 0;
	int total_stone = 0;
	int total_attack = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (board[y][x] == 0) continue;
			
			if (mask_gaze[mDir][y][x]) {
				total_stone += board[y][x];
				next_board[y][x] += board[y][x];
				continue;
			}

			// 1. p위치에 있는 전사들을 한 칸 이동
			Point np;
			int min_dist = abs(mPos.y - y) + abs(mPos.x - x);
			int dir = -1;
			for (int d = 0; d < 4; d++) {
				np.y = y + dy[d];
				np.x = x + dx[d];

				if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
				if (mask_gaze[mDir][np.y][np.x]) continue;
				int dist = abs(mPos.y - np.y) + abs(mPos.x - np.x);
				if (min_dist > dist) {
					min_dist = dist;
					dir = d;
				}
			}

			// 움직였다면, 메두사에 도달했는지 검사
			if (dir >= 0) {
				Point first_step = { y + dy[dir], x + dx[dir] };
				total_dist += board[y][x];

				// 메두사에 도달했으면, 소멸
				if (first_step.y == mPos.y && first_step.x == mPos.x) {
					total_attack += board[y][x];
					board[y][x] = 0;
				}
				// 그렇지 않으면, 한 칸 더 이동
				else {
					min_dist = abs(mPos.y - first_step.y) + abs(mPos.x - first_step.x);
					dir = -1;
					// 좌우상하
					for (int d = 2; d < 6; d++) {
						np.y = first_step.y + dy[d%4];
						np.x = first_step.x + dx[d%4];

						if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
						if (mask_gaze[mDir][np.y][np.x]) continue;
						int dist = abs(mPos.y - np.y) + abs(mPos.x - np.x);
						if (min_dist > dist) {
							min_dist = dist;
							dir = d % 4;
						}
					}

					// 움직였다면, 메두사에 도달했는지 검사
					if (dir >= 0) {
						Point second_step = { first_step.y + dy[dir], first_step.x + dx[dir] };
						total_dist += board[y][x];
						// 메두사에 도달했으면, 소멸
						if (second_step.y == mPos.y && second_step.x == mPos.x) {
							total_attack += board[y][x];
							board[y][x] = 0;
						}
						else {
							// 그렇지 않으면 이동 처리
							next_board[second_step.y][second_step.x] += board[y][x];
							board[y][x] = 0;
						}
					}
					// 한 칸만 이동 가능
					else {
						next_board[first_step.y][first_step.x] += board[y][x];
						board[y][x] = 0;
					}
				}
			}
			else {
				// 아예 안 움직임
				next_board[y][x] += board[y][x];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = next_board[i][j];
		}
	}

	cout << total_dist << ' ' << total_stone << ' ' << total_attack << '\n';
}


// d1=대각선 index, d2=상하좌우 index
void bfs2(int dir, Point sp, int dd) {
	if (sp.y < 0 || sp.y >= N || sp.x < 0 || sp.x >= N) {
		return;
	}

	memset(visited, 0, sizeof(visited));

	queue<Point> Q;
	Q.push(sp);
	visited[sp.y][sp.x] = true;

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		
		// 1. 대각선
		if (dd >= 0) {
			np = { cp.y + ddy[dd], cp.x + ddx[dd] };
			if (np.y >= 0 && np.y < N && np.x >= 0 && np.x < N) {
				if (!visited[np.y][np.x]) {
					visited[np.y][np.x] = true;
					Q.push(np);

					mask_gaze[dir][np.y][np.x] = false;
				}

			}
		}
		
		// 2. 정방향
		np = { cp.y + dy[dir], cp.x + dx[dir] };
		if (np.y >= 0 && np.y < N && np.x >= 0 && np.x < N) {
			if (!visited[np.y][np.x]) {
				visited[np.y][np.x] = true;
				Q.push(np);

				mask_gaze[dir][np.y][np.x] = false;
			}

		}
	}
}

void debug_print() {
	char debug_board[MAX_N][MAX_N] = {};

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mask_road[i][j]) {
				debug_board[i][j] = 'x';
			}
			else {
				debug_board[i][j] = '-';
			}

			if (i == mPos.y && j == mPos.x) {
				debug_board[i][j] = 'm';
			}
			else if (i == parkPos.y && j == parkPos.x) {
				debug_board[i][j] = 'p';
			}
			
			
		}
	}

	cout << "메두사와 공원 맵\n";
	cout << '\n';
	for (int i = 0; i < N; i++) {
		cout << debug_board[i] << '\n';
	}
	cout << '\n';
	cout << "병사 현황\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == mPos.y && j == mPos.x) {
				cout << 'm';
			}
			else {
				cout << board[i][j];
			}
			
		}
		cout << '\n';
	}
	cout << '\n';
}

void debug_gaze(int dir) {
	cout << "메두사의 시선\n";
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++) {
			if (mask_gaze[dir][i][j]) {
				cout << '1';
			}
			else {
				cout << '0';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}