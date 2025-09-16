#include <iostream>
#include <algorithm>
using namespace std;

const int MX = 100;

//하우
int dy[2] = { 1,0 };
int dx[2] = { 0,1 };

int n, k;
int board[MX + 1][MX + 1];
int next_board[MX + 1][MX + 1];

int ans;

void init();
void simulation();

void step1();
void step2(int& row, int& col);
void step3(int& row, int& col);
void step4(int& row, int& col);
bool check();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	simulation();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> board[n][i];
	}
}

void simulation() {
	while (!check()) {
		step1();
		int sy = 0; int sx = 0;
		step2(sy, sx);
		step3(sy, sx);
		step4(sy, sx);
		step3(sy, sx);

		ans++;
	}
}

void step1() {
	int mini = 1e9;
	for (int i = 0; i < n; i++) {
		if (mini > board[n][i]) mini = board[n][i];
	}
	for (int i = 0; i < n; i++) {
		if (mini == board[n][i]) board[n][i]++;
	}
}

void step2(int& srow, int& scol) {
	for (int i = 0; i < n; i++) {
		board[n - 1][i] = board[n][i];
	}

	//반죽 접기
	board[n - 2][1] = board[n - 1][0];
	board[n - 1][0] = 0;

	int stdCol = 1;
	int width = 1; int height = 2;

	//next좌상단 == (n-1-width, stdCol+width)
	while (n - (stdCol+width) >= height) {
		int nextY = n - 1 - width;
		int nextX = stdCol + width;
		for (int j = stdCol; j < stdCol + width; j++) {
			for (int i = n - 1; i > n - 1 - height; i--) {
				board[nextY + j - stdCol][nextX + n - 1 - i] = board[i][j];
				board[i][j] = 0;
			}
		}

		stdCol += width;
		if (width == height) height++;
		else width++;
	}

	//최종 모양의 좌상단, 범위
	srow = n - height;
	scol = stdCol;
}

void step3(int& row, int& col) {
	//(row, col)을 시작으로 도우를 눌러준다
	for (int i = row; i < n; i++) {
		for (int j = col; j < n; j++) {
			if (board[i][j] == 0) continue;

			int ny, nx;

			for (int d = 0; d < 2; d++) {
				ny = i + dy[d];
				nx = j + dx[d];
				if (ny < row || ny > n - 1 || nx < col || nx > n - 1) continue;
				if (board[ny][nx] == 0) continue;

				int t;
				if (board[i][j] > board[ny][nx]) {
					t = (board[i][j] - board[ny][nx]) / 5;
					next_board[i][j] -= t;
					next_board[ny][nx] += t;
				}
				else {
					t = (board[ny][nx] - board[i][j]) / 5;
					next_board[i][j] += t;
					next_board[ny][nx] -= t;
				}
			}

		}
	}

	//next_board의 값을 board에 반영해준다
	for (int i = row; i < n; i++) {
		for (int j = col; j < n; j++) {
			board[i][j] += next_board[i][j];
			next_board[i][j] = 0;
		}
	}

	int index = 0;
	//1차원 배열에 돌려놓는다
	for (int j = col; j < n; j++) {
		for (int i = n - 1; i >= row; i--) {
			if (board[i][j] == 0) continue;
			board[n][index++] = board[i][j];
			board[i][j] = 0;
		}
	}
}

void step4(int& row, int& col) {
	//1. n-1행으로 복사
	for (int i = 0; i < n; i++) {
		board[n - 1][i] = board[n][i];
	}
	//1. n/2만큼 접기
	int half = n / 2;
	for (int j = half - 1; j >= 0; j--) {
		board[n - 2][n - j - 1] = board[n - 1][j];
		board[n - 1][j] = 0;
	}

	//2. n/4만큼 접기
	int quarter = n / 4;
	for (int i = n - 1; i >= n - 2; i--) {
		for (int j = half + quarter - 1; j >= half; j--) {
			board[2 * n - 5 - i][2 * (half + quarter) - 1 - j] = board[i][j];
			board[i][j] = 0;
		}
	}

	row = n - 4;
	col = half + quarter;
}

bool check() {
	int mini = 1e9;
	int maxi = 0;
	for (int j = 0; j < n; j++) {
		if (mini > board[n][j]) mini = board[n][j];
		if (maxi < board[n][j]) maxi = board[n][j];
	}
	
	if (maxi - mini > k) return false;
	
	return true;
}