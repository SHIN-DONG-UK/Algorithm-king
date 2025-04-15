#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

int N, M, K;
int MAP[50][50];
int visited[50][50];
int ans;

void init();
void input();
void bfs(Point sp);
void simulation();

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		simulation();
		cout << ans << '\n';
	}
}

void init() {
	memset(MAP, 0, sizeof(MAP));
	memset(visited, 0, sizeof(visited));
	ans = 0;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		MAP[y][x] = 1;
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
		
		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
			if (visited[np.y][np.x] == 1) continue;
			if (MAP[np.y][np.x] == 0) continue;
			
			visited[np.y][np.x] = 1;
			q.push(np);
		}
	}
}