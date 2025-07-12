#include <iostream>
#include <vector>
using namespace std;

struct Command {
	int d;
	int s;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int ddy[4] = { 0,1,0,-1 };
int ddx[4] = { -1,0,1,0 };


int N, M;
int board[50][50];
int explodedCnts[4];

int marbleArr[2500];
int curMarbleCnt;

Command commands[100];

void input();
void simulation();

void destroy_marble(Command& com);
void copy_and_shift();
int explode_marble(); //return : 폭발한 구슬 총 개수
void change_marble();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	
	simulation();

	int ans = 0;
	for (int n= 1; n <= 3; n++)
		ans += n * explodedCnts[n];

	cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) curMarbleCnt++;
		}
	}
	int d, s;
	for (int i = 0; i < M; i++) {
		cin >> d >> s;
		commands[i] = { d - 1, s };
	}
}

void simulation() {
	for (int i = 0; i < M; i++) {
		Command com = commands[i];
		//1. 구슬 파괴
		destroy_marble(com);
		//2. 구슬 이동
		copy_and_shift();
		//3. 구슬 폭발
		while (int cnt = explode_marble()) {
			//shift
			vector<int> tmp;
			for (int i = 0; i < curMarbleCnt; i++) {
				if (marbleArr[i] == 0) continue;
				tmp.push_back(marbleArr[i]);
			}
			for (int i = 0; i < tmp.size(); i++) {
				marbleArr[i] = tmp[i];
			}
			curMarbleCnt -= cnt;
			marbleArr[curMarbleCnt] = -1; //실제 끝 표시
		}
		//4. 구슬 변화
		change_marble();
	}
}

void destroy_marble(Command& com) {
	int y = N / 2; int x = N / 2;
	for (int k = 0; k < com.s; k++) {
		y += dy[com.d]; x += dx[com.d];

		if (board[y][x] != 0) curMarbleCnt--;
		board[y][x] = 0;
	}
}

void copy_and_shift() {
	int idx = 0;
	int k = 1;
	
	int y = N / 2; int x = N / 2;
	int dir = 0;

	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				y += ddy[dir]; x += ddx[dir];
				if (board[y][x] == 0) continue;
				

				marbleArr[idx] = board[y][x];
				idx++;

				if (idx >= curMarbleCnt) {
					marbleArr[idx] = -1; //실제 끝 표시
					return;
				}
			}
			dir = (dir + 1) % 4;
		}
		k++;
	}
}

int explode_marble() {
	int cnt = 1;
	int rst = 0;

	for (int i = 0; i < curMarbleCnt; i++) {
		if (marbleArr[i] == marbleArr[i + 1])
			cnt++;
		else {
			if (cnt >= 4) {
				explodedCnts[marbleArr[i]] += cnt;
				for (int j = i; j > i - cnt; j--) marbleArr[j] = 0;
				rst += cnt;
			}
			cnt = 1;
		}
	}
	return rst;
}

void change_marble() {
	vector<int> tmp;
	int cnt = 1;

	for (int i = 0; i < curMarbleCnt; i++) {
		if (marbleArr[i] == marbleArr[i + 1])
			cnt++;
		else {
			tmp.push_back(cnt);
			tmp.push_back(marbleArr[i]);
			cnt = 1;
		}
	}
	
	if (tmp.size() == 0) return;

	// arr to board
	int idx = 0;
	int k = 1;
	int y = N / 2; int x = N / 2;
	int dir = 0;
	while (1) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				y += ddy[dir]; x += ddx[dir];

				board[y][x] = tmp[idx];
				idx++;

				if (idx >= N * N - 1) {
					curMarbleCnt = N * N - 1;
					return;
				}
				else if (idx >= tmp.size()) {
					curMarbleCnt = tmp.size();
					return;
				}
			}
			dir = (dir + 1) % 4;
		}
		k++;
	}
}