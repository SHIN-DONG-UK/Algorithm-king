#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N;
int map[20][20];

Point pshark;
int sshark = 2;
int cnt;

int ans;

void input();
int bfs(Point sp);
void print();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	while (1) {
		int a = bfs(pshark);
		//print();
		if (a == 0) break;
		else ans += a;
	}
	cout << ans << '\n';

	return 0;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				pshark = { i,j };
				map[i][j] = 0;
			}
		}
	}
}

int bfs(Point sp) {
	int visited[20][20] = { 0, };

	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N)
				continue;
			if (visited[np.y][np.x] > 0)
				continue;
			if (map[np.y][np.x] > sshark)
				continue;
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}

	Point target;
	int min_dist = 1e9;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= sshark || map[i][j] == 0)
				continue;
			if (visited[i][j] == 0)
				continue;
			if (min_dist > visited[i][j]) {
				min_dist = visited[i][j];
				target = { i,j };
			}
		}
	}

	if (min_dist == 1e9) {
		// 먹을 수 있는게 없음
		return 0;
	}
	else {
		map[target.y][target.x] = 0;
		cnt++;
		if (cnt == sshark) {
			cnt = 0;
			sshark++;
		}
		pshark = target;
	}
	return min_dist - 1;
}

void print() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}