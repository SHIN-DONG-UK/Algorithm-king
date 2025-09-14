#include <iostream>
using namespace std;

//우하좌상
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

const int MX = 25;

int ldarr[MX * MX + 1]; int ldSize;//1-based index
int ldarr2[MX * MX + 1]; int ldSize2;//1-based index
int board[MX][MX];//0-based index

int n, m;
int score;

void init();
void solve();

void attack(int& d, int& p);
void get_monster();
void update_1darr();
bool find_1darr();
inline void get_score(int& num, int cnt);
void paring();
void update_board();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << score << '\n';
	return 0;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

void solve() {
	int d, p;
	while (m--) {
		cin >> d >> p;
		//1. 공격
		attack(d, p);
		//2. 빈 공간 채우기
		get_monster();
		update_1darr();
		//3. 연속 4이상 몬스터 삭제 및 빈 공간 채우기
		while (find_1darr()) {
			update_1darr();
		}
		//4. 짝짓기
		paring();
		update_board();
	}
}

void attack(int& d, int& p) {
	int y = n / 2;
	int x = n / 2;
	for (int i = 0; i < p; i++) {
		y += dy[d];
		x += dx[d];
		get_score(board[y][x], 1);
		board[y][x] = 0;
	}
}

void get_monster() {
	//나선 모양으로 2차원 격자에서 1차원 배열로 복사
	ldSize = 0;
	int y = n / 2;
	int x = n / 2;
	//좌 하 우 상 순서대로 탐색
	int d = 2;
	int dist = 1;
	//2번에 한 번 씩 거리가 1씩 늘어남
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < dist; j++) {
				y += dy[d];
				x += dx[d];
				if (x == -1) return;
				ldarr[++ldSize] = board[y][x];
			}
			d = (d - 1 + 4) % 4;
		}
		dist++;
	}
}

void update_1darr() {
	for (int i = 1; i <= ldSize; i++) {
		if (ldarr[i] == 0) {
			int j = i + 1;
			while (j <= ldSize && !(ldarr[j] > 0)) { j++; }
			ldarr[i] = ldarr[j];
			ldarr[j] = 0;
		}
	}
}

bool find_1darr() {
	bool flag = false;

	int prev = ldarr[1];
	int cnt = 1;

	int i = 2;
	while (i <= ldSize && ldarr[i] > 0) {
		if (prev == ldarr[i]) {
			cnt++;
		}
		else {
			if (cnt >= 4) {
				for (int j = i - cnt; j < i; j++) {
					ldarr[j] = 0;
				}
				get_score(prev, cnt);
				flag = true;
			}
			prev = ldarr[i];
			cnt = 1;
		}
		i++;
	}

	if (cnt >= 4) {
		for (int j = i - cnt; j < i; j++) {
			ldarr[j] = 0;
		}
		get_score(prev, cnt);
		flag = true;
	}

	return flag;
}

inline void get_score(int& num, int cnt) {
	score += num * cnt;
}

void paring() {
	ldSize2 = 0;
	int prev = ldarr[1];
	int cnt = 1;

	int i = 2;
	while (i <= ldSize && ldarr[i] > 0) {
		if (prev == ldarr[i]) {
			cnt++;
		}
		else {
			if (ldSize2 >= n * n - 1) break;
			ldarr2[++ldSize2] = cnt;
			if (ldSize2 >= n * n - 1) break;
			ldarr2[++ldSize2] = prev;
			
			prev = ldarr[i];
			cnt = 1;
		}
		i++;
	}
	if (ldSize2 < n * n - 1) {
		ldarr2[++ldSize2] = cnt;
	}
	
	if (ldSize2 < n * n - 1) {
		ldarr2[++ldSize2] = prev;
	}
	
}

void update_board() {
	//나선 모양으로 1차원 배열에서 2차원 격자로 복사
	int y = n / 2;
	int x = n / 2;
	//좌 하 우 상 순서대로 탐색
	int d = 2;
	int dist = 1;
	//2번에 한 번 씩 거리가 1씩 늘어남
	int idx = 1;
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < dist; j++) {
				y += dy[d];
				x += dx[d];
				if (x == -1) return;

				if (idx > ldSize2) board[y][x] = 0;
				else board[y][x] = ldarr2[idx++];
			}
			d = (d - 1 + 4) % 4;
		}
		dist++;
	}
}