#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Point {
	int y;
	int x;
};

int N, M;
int MAP[50][50];
int visited[50][50];
int ans;

void init();
void input();
void bfs(Point sp);
void simulation();
void output(Point cp);

int main() {
	while (true) {
		init();
		input();
		if (N == 0 && M == 0) break;
		simulation();
		cout << ans << '\n';
	}
}

void init() {
	memset(visited, 0, sizeof(visited));
	ans = 0;
}
void input() {
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> MAP[i][j];
		}
	}
}

void simulation() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == 0) continue;
			if (visited[i][j] == 1) continue;
			bfs({ i,j });
			ans++;
		}
	}
}

void bfs(Point sp) {
	queue<Point> q;
	q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front();
		q.pop();

		for (int d = 0; d < 8; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
			if (MAP[np.y][np.x] == 0) continue;
			if (visited[np.y][np.x] == 1) continue;

			visited[np.y][np.x] = 1;
			q.push(np);

		}
	}
}