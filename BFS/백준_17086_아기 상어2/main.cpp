#include <iostream>
#include <queue>
#include <algorithm>

#define MAX_NM 50
using namespace std;

struct Point {
	int y;
	int x;
};

// 상 우상 우 우하 하 좌하 좌 좌상
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

int N, M;
int map[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];
int ans;

queue<Point> q;

void Input();
void Solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Solve();

	cout << ans - 1<< '\n';
	return 0;
}

void Input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j]) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
				
		}
	}
}

void Solve() {
	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 8; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M)
				continue;
			if (visited[np.y][np.x])
				continue;
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, visited[i][j]);
		}
	}
}