#include <iostream>
using namespace std;

const int MX = 10;
int board[MX + 1][MX + 1];
int row_cnt[MX];
int col_cnt[MX];

int k;
int score, rem;

void init();
void simulation();
void mprint(int t, int y, int x);

inline void move_1x1(int sy, int sx);
inline void move_1x2(int sy, int sx);
inline void move_2x1(int sy, int sx);
inline void draw_row(int y, int cnt);
inline void draw_col(int x, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	simulation();

	int sum = 0;
	for (int i = 0; i < MX; i++) {
		sum += row_cnt[i];
		sum += col_cnt[i];
	}

	cout << score << '\n';
	cout << sum << '\n';

	return 0;
}

void init() {
	for (int i = 0; i < MX; i++) {
		board[i][10] = 1;
	}
	for (int j = 0; j < MX; j++) {
		board[10][j] = 1;
	}
}
void simulation() {
	cin >> k;

	int t, y, x;
	while (k--) {
		cin >> t >> y >> x;
		if (t == 1) {
			move_1x1(y, x);
			if (col_cnt[4] > 0 && col_cnt[5] > 0) {
				draw_col(MX - 1, 2);
			}
			else if (col_cnt[5] > 0) {
				draw_col(MX - 1, 1);
			}
			if (row_cnt[4] > 0 && row_cnt[5] > 0) {
				draw_row(MX - 1, 2);
			}
			else if (row_cnt[5] > 0) {
				draw_row(MX - 1, 1);
			}

			
		}
		else if (t == 2) {
			move_1x2(y, x);
			if (col_cnt[4] > 0 && col_cnt[5] > 0) {
				draw_col(MX - 1, 2);
			}
			else if (col_cnt[5] > 0) {
				draw_col(MX - 1, 1);
			}
			if (row_cnt[4] > 0 && row_cnt[5] > 0) {
				draw_row(MX - 1, 2);
			}
			else if (row_cnt[5] > 0) {
				draw_row(MX - 1, 1);
			}
		}
		else {
			move_2x1(y, x);
			if (col_cnt[4] > 0 && col_cnt[5] > 0) {
				draw_col(MX - 1, 2);
			}
			else if (col_cnt[5] > 0) {
				draw_col(MX - 1, 1);
			}
			if (row_cnt[4] > 0 && row_cnt[5] > 0) {
				draw_row(MX - 1, 2);
			}
			else if (row_cnt[5] > 0) {
				draw_row(MX - 1, 1);
			}
		}

		//mprint(t, y, x);
	}
}

inline void move_1x1(int sy, int sx) {
	//1. 빨간색으로 이동
	int x = 3;
	int nx;
	while (1) {
		nx = x + 1;
		if (board[sy][nx] == 1) {
			board[sy][x] = 1;
			col_cnt[x]++;
			if (col_cnt[x] == 4) {
				score++;
				draw_col(x, 1);
			}
			break;
		}
		x = nx;
	}
	//2. 노란색으로 이동
	int y = 3;
	int ny;
	while (1) {
		ny = y + 1;
		if (board[ny][sx] == 1) {
			board[y][sx] = 1;
			row_cnt[y]++;
			if (row_cnt[y] == 4) {
				score++;
				draw_row(y, 1);
			}
			break;
		}
		y = ny;
	}
}
inline void move_1x2(int sy, int sx) {
	//1. 빨간색으로 이동
	int x = 3;
	int nx;
	while (1) {
		nx = x + 1;
		if (board[sy][nx] == 1) {
			board[sy][x] = board[sy][x - 1] = 1;
			col_cnt[x]++;
			col_cnt[x - 1]++;
			if (col_cnt[x] == 4 && col_cnt[x - 1] == 4) {
				score += 2;
				draw_col(x, 2);
			}
			else if (col_cnt[x] == 4) {
				score++;
				draw_col(x, 1);
			}
			else if (col_cnt[x - 1] == 4) {
				score++;
				draw_col(x - 1, 1);
			}

			break;
		}
		x = nx;
	}
	//2. 노란색으로 이동
	int y = 3;
	int ny;
	while (1) {
		ny = y + 1;
		if (board[ny][sx] == 1 || board[ny][sx + 1] == 1) {
			board[y][sx] = board[y][sx + 1] = 1;
			row_cnt[y] += 2;
			
			if (row_cnt[y] == 4) {
				score++;
				draw_row(y, 1);
			}
			break;
		}
		y = ny;
	}
}
inline void move_2x1(int sy, int sx) {
	//1. 빨간색으로 이동
	int x = 3;
	int nx;
	while (1) {
		nx = x + 1;
		if (board[sy][nx] == 1 || board[sy+1][nx] == 1) {
			board[sy][x] = board[sy + 1][x] = 1;
			col_cnt[x] += 2;
			if (col_cnt[x] == 4) {
				score++;
				draw_col(x, 1);
			}
			break;
		}
		x = nx;
	}
	//2. 노란색으로 이동
	int y = 3;
	int ny;
	while (1) {
		ny = y + 1;
		if (board[ny][sx] == 1) {
			board[y][sx] = board[y - 1][sx] = 1;
			row_cnt[y]++;
			row_cnt[y - 1]++;
			if (row_cnt[y] == 4 && row_cnt[y - 1] == 4) {
				score += 2;
				draw_row(y, 2);
			}
			else if (row_cnt[y] == 4) {
				score++;
				draw_row(y, 1);
			}
			else if (row_cnt[y - 1] == 4) {
				score++;
				draw_row(y - 1, 1);
			}
			break;
		}
		y = ny;
	}
}

inline void draw_row(int y, int cnt) {
	for (int i = y; i >= 4 + cnt; i--) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = board[i - cnt][j];
			board[i - cnt][j] = 0;
		}
		row_cnt[i] = row_cnt[i - cnt];
	}
	for (int i = 0; i < cnt; i++) {
		row_cnt[4 + i] = 0;
	}
}

inline void draw_col(int x, int cnt) {
	for (int j = x; j >= 4 + cnt; j--) {
		for (int i = 0; i < 4; i++) {
			board[i][j] = board[i][j - cnt];
			board[i][j - cnt] = 0;
		}
		col_cnt[j] = col_cnt[j - cnt];
	}
	for (int j = 0; j < cnt; j++) {
		col_cnt[4 + j] = 0;
	}
}

void mprint(int t, int y, int x) {
	int y1 = -1;
	int x1 = -1;
	int y2 = -1;
	int x2 = -1;
	if (t == 1) {
		y1 = y; x1 = x;
	}
	else if (t == 2) {
		y1 = y; x1 = x;
		y2 = y; x2 = x + 1;
	}
	else {
		y1 = y; x1 = x;
		y2 = y + 1; x2 = x;
	}
	cout << '\n';
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			if (i == y1 && j == x1) {
				cout << "* ";
			}
			else if (i == y2 && j == x2) {
				cout << "* ";
			}
			else {
				cout << board[i][j] << ' ';
			}
			
		}
		cout << '\n';
	}
	cout << '\n';
}