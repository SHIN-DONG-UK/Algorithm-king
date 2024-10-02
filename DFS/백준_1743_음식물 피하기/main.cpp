#include <iostream>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int N, M, K;
int MAP[101][101];
int visited[101][101];
int cnt;
int max_val;
Point np;

void input();
void simulation();
void dfs(Point cp);

int main() {
	input();
	simulation();
	cout << max_val << '\n';
}

void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int r, c;
		cin >> r >> c;
		MAP[r][c] = 1;
	}
}

void dfs(Point cp) {
	for (int d = 0; d < 4; d++)
	{
		np = { cp.y + dy[d], cp.x + dx[d] };
		if (np.y < 1 || np.y > N || np.x < 1 || np.x > M) continue;
		if (visited[np.y][np.x] == 1) continue;
		if (MAP[np.y][np.x] == 0) continue;

		cnt++;
		visited[np.y][np.x] = 1;
		dfs(np);
	}
}

void simulation() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (MAP[i][j] == 1) {
				if (visited[i][j] == 1) continue;
				cnt = 0;
				
				dfs({ i, j });

				if (cnt > max_val) max_val = cnt;
			}
		}
	}
}