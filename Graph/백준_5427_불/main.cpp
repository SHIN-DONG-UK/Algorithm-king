#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAP_SIZE 1000
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int w, h;
char map[MAP_SIZE][MAP_SIZE];
int map_fire[MAP_SIZE][MAP_SIZE];
int visited[MAP_SIZE][MAP_SIZE];
vector<Point> fire_pos_list;
Point player;

void Init();
void Input();
void GetMapFire();
void Simulation();
void Output();

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		Init();

		Input();

		GetMapFire();

		Simulation();

		Output();
		
  	}
}


void Init() {
	memset(visited, 0, sizeof(visited));
	memset(map_fire, 0, sizeof(map_fire));

	fire_pos_list.clear();
}

void Input() {
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				fire_pos_list.push_back({ i, j });
			if (map[i][j] == '@')
				player = { i,j };
		}
	}
}

void GetMapFire() {
	queue<Point> q;
	for (int i = 0; i < fire_pos_list.size(); i++)
	{
		q.push(fire_pos_list[i]);
		map_fire[fire_pos_list[i].y][fire_pos_list[i].x] = 1;
	}

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= h || np.x < 0 || np.x >= w)
				continue;
			if (map[np.y][np.x] == '#')
				continue;
			if (map_fire[np.y][np.x] > 0)
				continue;
			map_fire[np.y][np.x] = map_fire[cp.y][cp.x] + 1;
			q.push(np);
		}
	}
}

void Simulation() {
	queue<Point> q;
	q.push(player);
	visited[player.y][player.x] = 1;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= h || np.x < 0 || np.x >= w)
				continue;
			if (map[np.y][np.x] == '#')
				continue;
			if (visited[np.y][np.x] > 0)
				continue;

			// 불 때문에 못가는 곳
			if (map_fire[np.y][np.x] != 0 && map_fire[np.y][np.x] <= visited[cp.y][cp.x] + 1)
				continue;
			
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}
}

void Output() {
	int ans = 1e9;
	if (w == 1) {
		if (visited[0][0] != 0 && visited[h - 1][0] != 0)
			ans = min(visited[0][0], visited[h - 1][0]);
		else if (visited[0][0] != 0)
			ans = visited[0][0];
		else if (visited[h - 1][0] != 0)
			ans = visited[h - 1][0];
	}
	else if (h == 1) {
		if (visited[0][0] != 0 && visited[0][w-1] != 0)
			ans = min(visited[0][0], visited[0][w-1]);
		else if (visited[0][0] != 0)
			ans = visited[0][0];
		else if (visited[0][w-1] != 0)
			ans = visited[0][w-1];
	}
	else {
		for (int i = 0; i < h; i++)
		{
			if (visited[i][0] != 0) {
				if (ans > visited[i][0])
					ans = visited[i][0];
			}
			if (visited[i][w - 1] != 0) {
				if (ans > visited[i][w - 1])
					ans = visited[i][w - 1];
			}

		}
		for (int j = 0; j < w; j++)
		{
			if (visited[0][j] != 0) {
				if (ans > visited[0][j])
					ans = visited[0][j];
			}
			if (visited[h - 1][j] != 0) {
				if (ans > visited[h - 1][j])
					ans = visited[h - 1][j];
			}

		}
	}
	
	if (ans == 1e9)
		cout << "IMPOSSIBLE\n";
	else
		cout << ans << '\n';
}