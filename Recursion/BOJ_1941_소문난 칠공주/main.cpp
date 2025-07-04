#include <iostream>
#include <queue>
using namespace std;

const int N = 5;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

char arr[N*N];
int path[7];
int testMap[N][N];

int gAns;

void go(int lev, int start);
bool connectivity_check(Point sp);
void init_map();

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i * N + j];
		}
	}

	go(0, 0);

	cout << gAns << '\n';

	return 0;
}

void go(int lev, int start) {
	if (lev == 7) {
		for (int i = 0; i < 7; i++) testMap[path[i] / N][path[i] % N] = 1;
		
		int cnt = 0;
		for (int i = 0; i < 7; i++) { if (arr[path[i]] == 'S') cnt++; }

		if (cnt < 4) { init_map();  return; } //1. 이다솜파 4명 미만
		Point sp = { path[0] / N, path[0] % N };
		if (!connectivity_check(sp)) { init_map(); return; } //2. 칠공주가 연결되어 있지 않음

		gAns++;
		init_map();

		return;
	}

	for (int i = start; i < N*N; i++) {
		path[lev] = i;
		go(lev + 1, i + 1);
	}
}

void init_map() {
	for (int i = 0; i < 7; i++) testMap[path[i] / 5][path[i] % 5] = 0;
}

bool connectivity_check(Point sp) {
	bool visited[N][N] = { 0, };
	queue<Point> Q;
	Q.push(sp);
	visited[sp.y][sp.x] = 1;

	int oCnt = 1;
	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
			if (testMap[np.y][np.x] == 0) continue;
			if (visited[np.y][np.x]) continue;
			visited[np.y][np.x] = 1;
			Q.push(np);

			oCnt++;
		}
	}

	if (oCnt == 7)return true;
	return false;
}