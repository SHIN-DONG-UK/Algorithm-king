#include <iostream>
#include <queue>
#include <cstring>

#define MAP_SIZE 30
using namespace std;

struct Point {
	int z;
	int y;
	int x;
};

// 북 남 서 동 상 하
int dz[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dx[6] = { 0,0,-1,1,0,0 };
int L, R, C;
char map[MAP_SIZE][MAP_SIZE][MAP_SIZE];
int visited[MAP_SIZE][MAP_SIZE][MAP_SIZE];
Point player;
Point pos_exit;

void Init();
void Input();
void Simulation();

int main() {
	while (1) {
		Init();

		Input();

		if (L == 0 && R == 0 && C == 0)
			break;

		Simulation();

		if (visited[pos_exit.z][pos_exit.y][pos_exit.x] == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << visited[pos_exit.z][pos_exit.y][pos_exit.x] << " minute(s).\n";
	}
}

void Init() {
	memset(visited, -1, sizeof(visited));
}

void Input() {
	cin >> L >> R >> C;
	for (int z = 0; z < L; z++)
	{
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				cin >> map[z][i][j];
				if (map[z][i][j] == 'S')
					player = { z,i,j };
				if (map[z][i][j] == 'E')
					pos_exit = { z,i,j };
			}
		}
	}
}
void Simulation() {
	queue<Point> q;
	q.push(player);
	visited[player.z][player.y][player.x] = 0;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 6; d++)
		{
			np = { cp.z + dz[d], cp.y + dy[d], cp.x + dx[d] };
			if (np.z < 0 || np.z >= L || np.y < 0 || np.y >= R || np.x < 0 || np.x >= C)
				continue;
			if (map[np.z][np.y][np.x] == '#')
				continue;
			if (visited[np.z][np.y][np.x] >= 0)
				continue;

			visited[np.z][np.y][np.x] = visited[cp.z][cp.y][cp.x] + 1;
			q.push(np);
		}
	}
}