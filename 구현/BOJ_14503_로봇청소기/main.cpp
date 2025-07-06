#include <iostream>
using namespace std;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int N, M;
int map[50][50];
bool cleaned[50][50];
int ry, rx;
int rd;

int gAns;

void input();
void simulation();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();

	simulation();

	cout << gAns << '\n';
	return 0;
}

void input() {
	cin >> N >> M;
	cin >> ry >> rx >> rd;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void simulation() {
	while (1) {
		if (!cleaned[ry][rx]) { 
			gAns++;  
			cleaned[ry][rx] = 1;  
		}

		bool flag = false;
		int ny, nx;
		for (int d = 0; d < 4; d++) {
			rd = (rd + 4 - 1) % 4; //반시계 90도 회전
			ny = ry + dy[rd]; nx = rx + dx[rd];

			if (map[ny][nx]) continue;
			if (cleaned[ny][nx]) continue;

			// case3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
			ry = ny; rx = nx;
			flag = true;
			break;
		}
		
		if (flag) continue;

		// case2. 청소되지 않은 빈 칸이 없는 경우
		ny = ry - dy[rd]; nx = rx - dx[rd];
		if (map[ny][nx]) break;
		ry = ny; rx = nx;
	}
}