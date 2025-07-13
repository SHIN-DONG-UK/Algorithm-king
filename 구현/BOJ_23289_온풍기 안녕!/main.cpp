#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int blowDirection[5][3][2] = {
	{{-1,-1}, {-1,-1}, {-1,-1}},
	{{3,1}, {0,1}, {4,1}},
	{{3,2}, {0,2}, {4,2}},
	{{2,3}, {0,3}, {1,3}},
	{{2,4}, {0,4}, {1,4}}
};

struct Point {
	int y;
	int x;
};

struct Heater {
	Point p;
	int dir;
};

struct Node {
	Point p;
	int temp;
};

int R, C, K;
int room[21][21];
bool wall[21][21][5];
vector<Heater> heaters;
vector<Point> investi;

int gAns;

void input();
void simulation();

void blow_wind();
void control_temp();
void decrease_temp();
bool inspect_cells();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();

	simulation();

	cout << gAns << '\n';

	return 0;
}

void input() {
	cin >> R >> C >> K;

	int tmp;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> tmp;
			if (tmp == 0) continue;
			else if (tmp == 5) investi.push_back({ i, j });
			else heaters.push_back({ i,j,tmp });
		}
	}

	int y, x, t;
	cin >> tmp;
	for (int i = 0; i < tmp; i++) {
		cin >> y >> x >> t;
		if (t == 0) {
			wall[y][x][3] = true;
			wall[y - 1][x][4] = true;
		}
		else {
			wall[y][x][1] = true;
			wall[y][x + 1][2] = true;
		}
	}
}

void simulation() {
	while (!inspect_cells() && gAns <= 100) {
		//1. 온풍기 바람
		blow_wind();
		//2. 온도 조절
		control_temp();
		//3. 온도 감소
		decrease_temp();

		gAns++;
	}
}

void blow_wind() {
	for (Heater& heater : heaters) {
		bool visited[21][21] = { 0, };
		queue<Node> Q;
		
		Point sp = { heater.p.y + dy[heater.dir], heater.p.x + dx[heater.dir] };
		room[sp.y][sp.x] += 5;

		visited[sp.y][sp.x] = 1;
		Q.push({ sp, 4 });

		Point np;
		while (!Q.empty()) {
			Node node = Q.front(); Q.pop();
			
			for (int i = 0; i < 3; i++) {
				bool flag = false;
				np = node.p;
				for (int j = 0; j < 2; j++) {
					int targetDir = blowDirection[heater.dir][i][j];
					if (wall[np.y][np.x][targetDir]) {
						flag = true;
						break;
					}
					np.y += dy[targetDir];
					np.x += dx[targetDir];
				}
				if (flag) continue;
				if (np.y <= 0 || np.y > R || np.x <= 0 || np.x > C) continue;
				if (visited[np.y][np.x]) continue;

				room[np.y][np.x] += node.temp;
				visited[np.y][np.x] = 1;
				if (node.temp == 1) continue;

				Q.push({ np, node.temp - 1 });
			}
		}
	}
}

void control_temp() {
	int next_room[21][21] = { 0, };

	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (room[y][x] == 0) continue;

			int remainder = room[y][x];
			for (int d = 1; d <= 4; d++) {
				if (wall[y][x][d]) continue;

				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny <= 0 || ny > R || nx <= 0 || nx > C) continue;

				int cTemp = room[y][x];
				int nTemp = room[ny][nx];

				if (cTemp > nTemp) {
					int val = (cTemp - nTemp) / 4;
					next_room[ny][nx] += val;
					remainder -= val;
				}
			}
			next_room[y][x] += remainder;
		}
	}

	//원래 맵으로 복사
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			room[i][j] = next_room[i][j];
		}
	}
}

void decrease_temp() {
	for (int i = 1; i <= R; i++) {
		if (room[i][1] >= 1) room[i][1]--;
		if (room[i][C] >= 1) room[i][C]--;
	}
	for (int j = 2; j <= C - 1; j++) {
		if (room[1][j] >= 1) room[1][j]--;
		if (room[R][j] >= 1) room[R][j]--;
	}
}

bool inspect_cells() {
	for (Point& p : investi)
		if (room[p.y][p.x] < K)
			return false;
	return true;
}