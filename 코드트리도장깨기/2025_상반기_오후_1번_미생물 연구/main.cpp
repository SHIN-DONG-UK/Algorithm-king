#define MAX_N 15
#define MAX_Q 50

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, Q;
int board[MAX_N][MAX_N];
int next_board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

struct Point {
	int y;
	int x;
};

struct Micro {
	int num;
	bool isRemoved;
	int size;
	int y1, x1;
	int w, h;
};

Micro micros[MAX_Q + 1];
vector<Micro*> ordered_vec;
int num_cnt[MAX_Q + 1];
bool adj_pair[MAX_Q + 1][MAX_Q + 1];

void input(int num, int r1, int c1, int r2, int c2);
void move_bottle();
void record_result();

bool can_move(Micro* mpt, int y, int x);
void move(Micro* mpt, int y, int x);

void debug_print();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> Q;
	int r1, c1, r2, c2;
	for (int n = 1; n <= Q; n++) {
		cin >> r1 >> c1 >> r2 >> c2;
		input(n, r1, c1, r2, c2);

		//debug_print();

		move_bottle();

		//debug_print();

		record_result();
	}

	return 0;
}

void input(int num, int r1, int c1, int r2, int c2) {
	// 기존 -> 왼쪽 위&오른쪽 아래
	int y1 = N - c2;
	int x1 = r1;
	int y2 = N - 1 - c1;
	int x2 = r2 - 1;
	// micros에 기록
	micros[num].num = num;
	micros[num].isRemoved = false;
	micros[num].y1 = y1;
	micros[num].x1 = x1;
	micros[num].h = y2 - y1 + 1;
	micros[num].w = x2 - x1 + 1;
	micros[num].size = micros[num].w * micros[num].h;


	// 용기에 기록
	for (int i = y1; i <= y2; i++) {
		for (int j = x1; j <= x2; j++) {
			int tar_num = board[i][j];
			micros[tar_num].size--; // tar_num이 0이어도 상관x
			board[i][j] = num;
		}
	}

	// 정렬용 벡터에 기록
	ordered_vec.push_back(micros + num);

	// 쪼개진 무리 찾기
	memset(visited, 0, sizeof(visited));
	memset(num_cnt, 0, sizeof(num_cnt));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;
			if (visited[i][j]) continue;

			int min_y = MAX_N;
			int min_x = MAX_N;
			int max_y = 0;
			int max_x = 0;

			queue<Point> Q;
			Q.push({ i ,j });
			visited[i][j] = true;

			Point cp, np;
			while (!Q.empty()) {
				cp = Q.front(); Q.pop();

				if (cp.y > max_y) { max_y = cp.y; }
				if (cp.x > max_x) { max_x = cp.x; }
				if (min_y > cp.y) { min_y = cp.y; }
				if (min_x > cp.x) { min_x = cp.x; }

				for (int d = 0; d < 4; d++) {
					np = { cp.y + dy[d], cp.x + dx[d] };
					if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
					if (visited[np.y][np.x]) continue;
					if (board[np.y][np.x] == board[i][j]) {
						visited[np.y][np.x] = true;
						Q.push({ np.y, np.x });
					}
				}
			}

			int cur_num = board[i][j];
			num_cnt[cur_num]++;

			// 무리의 y1, x1, width, height 업데이트
			micros[cur_num].h = max_y - min_y + 1;
			micros[cur_num].w = max_x - min_x + 1;
			micros[cur_num].y1 = min_y;
			micros[cur_num].x1 = min_x;
		}
	}

	// 쪼개진 무리 삭제
	memset(visited, 0, sizeof(visited));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cur_num = board[i][j];

			if (cur_num == 0) continue;
			if (visited[i][j]) continue; // 삭제된 곳이라 확인할 필요 없음

			if (num_cnt[cur_num] > 1) {
				queue<Point> Q;
				Q.push({ i ,j });
				visited[i][j] = true;
				board[i][j] = 0;

				Point cp, np;
				while (!Q.empty()) {
					cp = Q.front(); Q.pop();
					for (int d = 0; d < 4; d++) {
						np = { cp.y + dy[d], cp.x + dx[d] };
						if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
						if (visited[np.y][np.x]) continue;
						if (board[np.y][np.x] == cur_num) {
							visited[np.y][np.x] = true;
							Q.push({ np.y, np.x });

							board[np.y][np.x] = 0;
						}
					}
				}

				micros[cur_num].isRemoved = true;
			}
		}
	}
}

bool compare(Micro* a, Micro* b) {
	if (a->size == b->size) {
		return a->num < b->num;
	}
	return a->size > b->size;
}

void move_bottle() {
	memset(next_board, 0, sizeof(next_board));

	sort(ordered_vec.begin(), ordered_vec.end(), compare);

	for (Micro* pt : ordered_vec) {
		if (pt->isRemoved) continue;

		bool flag = false;
		for (int j = 0; j < N; j++) {
			if (flag) break;
			for (int i = N - 1; i >= 0; i--) {
				//if (next_board[i][j] > 0) continue;

				if (can_move(pt, i - pt->h + 1, j)) {
					move(pt, i - pt->h + 1, j);

					pt->y1 = i - pt->h + 1;
					pt->x1 = j;
					
					flag = true;
					break;
				}
			}
		}

		if (!flag) {
			pt->isRemoved = true;
		}
	}

	// 새로운 용기에서 실험하도록 next_board -> board 처리
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = next_board[i][j];
		}
	}
}

void record_result() {
	memset(adj_pair, 0, sizeof(adj_pair));

	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 0) continue;

			for (int d = 0; d < 4; d++) {
				int ny = i + dy[d];
				int nx = j + dx[d];
				
				if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
				if (board[ny][nx] == 0) continue;
				
				int my_num = board[i][j];
				int other_num = board[ny][nx];

				if (my_num == other_num) continue;

				if (adj_pair[my_num][other_num]) continue;

				adj_pair[my_num][other_num] = true;
				adj_pair[other_num][my_num] = true;
				sum += micros[my_num].size * micros[other_num].size;

			}
		}
	}

	cout << sum << '\n';
}

bool can_move(Micro* mpt, int y, int x) {
	for (int i = 0; i < mpt->h; i++) {
		for (int j = 0; j < mpt->w; j++) {
			if (y + i < 0 || y + i >= N || x + j < 0 || x + j >= N) return false;

			if (board[mpt->y1 + i][mpt->x1 + j] != mpt->num) continue;

			if (next_board[y + i][x + j] > 0) return false;
		}
	}
	return true;
}

// y와 x는 왼쪽 위 좌표
void move(Micro* mpt, int y, int x) {
	for (int i = 0; i < mpt->h; i++) {
		for (int j = 0; j < mpt->w; j++) {
			if (board[mpt->y1 + i][mpt->x1 + j] != mpt->num) continue;

			next_board[y + i][x + j] = mpt->num;
		}
	}
}

void debug_print() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}