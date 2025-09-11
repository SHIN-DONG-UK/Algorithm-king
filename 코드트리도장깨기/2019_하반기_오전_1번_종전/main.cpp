#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

const int MX = 100;

int ddy[4] = { -1,-1,1,1 }; //우상, 좌상, 좌하, 우하
int ddx[4] = { 1,-1,-1,1 };

int dy[4] = { -1,1,0,0 }; //상, 하, 좌, 우
int dx[4] = { 0,0,-1,1 };

struct Length {
	int l1; //짝수번째 변 길이
	int l2; //홀수번쨉 변 길이
};

struct Point {
	int y;
	int x;
};

int n;
int board[MX][MX];
bool draw_board[MX][MX];
bool visited[MX][MX];
int sum;
int ans;

vector<Length> lengths;

void init();
void solve();
void draw(Point p, Length& len, bool flag);
int bfs(Point sp, int by, int bx, bool (*fp)(Point&, int&, int&));

bool is_valid0(Point& p, int& y, int& x);
bool is_valid1(Point& p, int& y, int& x);
bool is_valid2(Point& p, int& y, int& x);
bool is_valid3(Point& p, int& y, int& x);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	solve();

	cout << ans << '\n';
	return 0;
}

void init() {
	sum = 0;
	ans = 1e9;

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			sum += board[i][j];
			draw_board[i][j] = false;
		}
	}

	lengths.clear();
	int limit = n * sqrt(2);
	for (int a = 1; a <= limit; a++) {
		for (int b = 1; b <= limit; b++) {
			lengths.push_back({ a, b });
		}
	}

}


void solve() {
	for (int i = 2; i < n; i++) {
		for (int j = 1; j < n-1; j++) {
			for (auto& len : lengths) {
				if (j + len.l1 >= n || j - len.l2 < 0 || i - len.l1 - len.l2 < 0) continue;
				int tmp_sum = sum;
				//1. 경계 표시
				draw({ i, j }, len, true);
				
				//2. 인구수 합 각각 구한다
				int mini = 1e9;
				int maxi = 0;
				int tmp;
				//2번 부족 인구수
				tmp = bfs({ 0,0 }, i - len.l2, j + len.l1 - len.l2, &is_valid0);
				tmp_sum -= tmp;
				if (tmp > maxi) maxi = tmp;
				if (tmp < mini) mini = tmp;
				//3번 부족 인구수
				tmp = bfs({ 0, n - 1 }, i - len.l1, j + len.l1 - len.l2, &is_valid1);
				tmp_sum -= tmp;
				if (tmp > maxi) maxi = tmp;
				if (tmp < mini) mini = tmp;
				//4번 부족 인구수
				tmp = bfs({ n - 1,0 }, i - len.l2, j, &is_valid2);
				tmp_sum -= tmp;
				if (tmp > maxi) maxi = tmp;
				if (tmp < mini) mini = tmp;
				//5번 부족 인구수
				tmp = bfs({ n - 1,n - 1 }, i - len.l1, j, &is_valid3);
				tmp_sum -= tmp;
				if (tmp > maxi) maxi = tmp;
				if (tmp < mini) mini = tmp;
				//1번 부족 인구수
				if (tmp_sum > maxi) maxi = tmp_sum;
				if (tmp_sum < mini) mini = tmp_sum;
				//3. ans update
				if (ans > maxi - mini)
					ans = maxi - mini;

				//4. 그렸던거 지우기
				draw({ i, j }, len, false);
			}
		}
	}
}

void draw(Point p, Length& len, bool flag) {
	for (int d = 0; d < 4; d++) {
		if (d % 2 == 0) {
			for (int k = 0; k < len.l1; k++) {
				p.y += ddy[d];
				p.x += ddx[d];
				draw_board[p.y][p.x] = flag;
			}
		}
		else {
			for (int k = 0; k < len.l2; k++) {
				p.y += ddy[d];
				p.x += ddx[d];
				draw_board[p.y][p.x] = flag;
			}
		}
	}
}

int bfs(Point sp, int by, int bx, bool (*is_valid)(Point&, int&, int&)) {
	int rst = 0;
	memset(visited, 0, sizeof(visited));

	queue<Point> Q;
	rst += board[sp.y][sp.x];
	Q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (is_valid(np, by, bx)) {
				if (draw_board[np.y][np.x]) continue;
				if (visited[np.y][np.x]) continue;
				visited[np.y][np.x] = true;
				Q.push(np);

				rst += board[np.y][np.x];
			}
		}
		
	}

	return rst;
}

bool is_valid0(Point& p, int& y, int& x) {
	return p.y >= 0 && p.y < y && p.x >= 0 && p.x <= x;
}
bool is_valid1(Point& p, int& y, int& x) {
	return p.y >= 0 && p.y <= y && p.x > x && p.x < n;
}
bool is_valid2(Point& p, int& y, int& x) {
	return p.y >= y && p.y < n && p.x >= 0 && p.x < x;
}
bool is_valid3(Point& p, int& y, int& x) {
	return p.y > y && p.y < n && p.x >= x && p.x < n;
}