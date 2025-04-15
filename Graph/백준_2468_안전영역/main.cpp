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

int N;
int MAP[100][100];
int visited[100][100];
int ans;
int highest;

void input();
void simulation();
void bfs(Point sp, int limit);

int main() {
	input();
	simulation();

	cout << ans << '\n';
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> MAP[i][j];
			if (MAP[i][j] > highest) highest = MAP[i][j];
		}
	}
}

void simulation() {
	for (int height = 0; height < highest; height++)
	{
		memset(visited, 0, sizeof(visited));
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (MAP[i][j] <= height) continue;
				if (visited[i][j] == 1) continue;
				bfs({ i,j }, height);
				count++;
			}
		}

		if (count > ans) ans = count;
	}
}

void bfs(Point sp, int limit) {
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
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
			if (MAP[np.y][np.x] <= limit) continue;
			if (visited[np.y][np.x] == 1) continue;

			visited[np.y][np.x] = 1;
			q.push(np);
		}
	}
}