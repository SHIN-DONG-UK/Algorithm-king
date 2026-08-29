#include <iostream>
#include <deque>
#include <vector>

using namespace std;

struct Point {
	int r;
	int c;

	bool operator==(const Point& other) const {
		return r == other.r && c == other.c;
	}
};

const int INF = 1e9;

int m, n;
int h, w;
vector<vector<int>> board;
vector<vector<int>> compressed_board1;
vector<vector<int>> compressed_board2;

int len_drops;

vector<int> answer;


void init();
vector<int> solve();

void printv2(vector<vector<int>>& v2);

int main() {
	cout.tie(0);

	init();
	printv2(board);

	vector<int> ans = solve();

	for (auto& n : ans) {
		cout << n << ' ';
	}
	cout << '\n';

	return 0;
}

void init() {
	cin >> m >> n;
	cin >> h >> w;
	board.resize(m, vector<int>(n, INF));
	compressed_board1.resize(m - h + 1, vector<int>(n, INF));
	compressed_board2.resize(m - h + 1, vector<int>(n - w + 1, INF));
	
	cin >> len_drops;

	int r, c;
	for (int i = 0; i < len_drops; i++) {
		cin >> r >> c;
		board[r][c] = i + 1;
	}
}

vector<int> solve() {
	vector<int> rst;

	// 1. 높이 방향으로 압축
	for (int j = 0; j < n; j++) {
		// 1-1. deque init
		deque<Point> dq;
		for (int i = 0; i < h; i++) {
			if (dq.empty()) {
				dq.push_back({i, j});
			}
			else {
				while (!dq.empty()) {
					Point p = dq.back();

					if (board[p.r][p.c] > board[i][j]) {
						dq.pop_back();
					}
					else {
						break;
					}
				}

				dq.push_back({ i, j });
			}
			
		}
		Point current_min_point = dq.front();
		compressed_board1[0][j] = board[current_min_point.r][current_min_point.c];

		// 1-2. update deque
		for (int i = h; i < m; i++) {
			Point expired_point = { i - h, j };
			if (dq.front() == expired_point) {
				dq.pop_front();
			}

			while (!dq.empty()) {
				Point p = dq.back();

				if (board[p.r][p.c] > board[i][j]) {
					dq.pop_back();
				}
				else {
					break;
				}
			}

			dq.push_back({ i, j });
			Point current_min_point = dq.front();
			compressed_board1[i - h + 1][j] = board[current_min_point.r][current_min_point.c];
		}
	}

	printv2(compressed_board1);

	// 2. 너비 방향으로 압축
	for (int i = 0; i < m - h + 1; i++) {
		deque<Point> dq;
		// 1-1. deque init
		for (int j = 0; j < w; j++) {
			if (dq.empty()) {
				dq.push_back({ i, j });
			}
			else {
				while (!dq.empty()) {
					Point p = dq.back();

					if (compressed_board1[p.r][p.c] > compressed_board1[i][j]) {
						dq.pop_back();
					}
					else {
						break;
					}
				}

				dq.push_back({ i, j });
			}
			
		}
		Point current_min_point = dq.front();
		compressed_board2[i][0] = compressed_board1[current_min_point.r][current_min_point.c];

		// 1-2. update deque
		for (int j = w; j < n; j++) {
			Point expired_point = { i, j - w };
			if (dq.front() == expired_point) {
				dq.pop_front();
			}

			while (!dq.empty()) {
				Point p = dq.back();

				if (compressed_board1[p.r][p.c] > compressed_board1[i][j]) {
					dq.pop_back();
				}
				else {
					break;
				}
			}

			dq.push_back({ i, j });
			Point current_min_point = dq.front();
			compressed_board2[i][j - w + 1] = compressed_board1[current_min_point.r][current_min_point.c];
		}
	}

	printv2(compressed_board2);
	// 3. 압축된 배열을 돌면서 최댓값 갱신
	int max_num = 0;
	Point p;

	for (int i = 0; i < m - h + 1; i++) {
		for (int j = 0; j < n - w + 1; j++) {
			if (compressed_board2[i][j] > max_num) {
				max_num = compressed_board2[i][j];
				p = { i, j };
			}
		}
	}

	rst.push_back(p.r);
	rst.push_back(p.c);

	return rst;
}

void printv2(vector<vector<int>>& v2) {
	cout << '\n';
	for (auto& v : v2) {
		for (auto& n : v) {
			if (n == INF) {
				cout << ". ";
			}
			else {
				cout << n << ' ';
			}
		}
		cout << '\n';
	}
	cout << '\n';
}