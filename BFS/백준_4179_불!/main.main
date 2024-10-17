#include <iostream>
#include <vector>
#include <queue>

#define MAX_MAP 1000
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
char map[MAX_MAP][MAX_MAP];
int visited_fire[MAX_MAP][MAX_MAP];
int visited[MAX_MAP][MAX_MAP];
vector<Point> fires;

int R, C;
Point Jihoon;

void Input();
void BfsFire();
int BfsJihoon();

int main() {
	Input();
	BfsFire();
	int ans = BfsJihoon();
	if (ans > 0)
		cout << ans << '\n';
	else
		cout << "IMPOSSIBLE\n";
	return 0;
}

void Input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
			if (map[i][j] == 'J') {
				Jihoon = { i, j };
				map[i][j] = '.';
			}
				
			else if (map[i][j] == 'F')
				fires.push_back({ i,j });
		}
	}
}

// 틀린 부분
// 같은 레벨에서 불이 번지는 게 동일해야 하는데, 그렇지 않게 코드를 작성함
// 
void BfsFire() {
	queue<Point> q;
	for (int i = 0; i < fires.size(); i++){
		q.push(fires[i]);
		visited_fire[fires[i].y][fires[i].x] = 1;
	}
	
	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= R || np.x < 0 || np.x >= C)
				continue;

			if (visited_fire[np.y][np.x] > 0)
				continue;
			if (map[np.y][np.x] == '#')
				continue;

			//Print(np);
			visited_fire[np.y][np.x] = visited_fire[cp.y][cp.x] + 1;
			q.push(np);
		}

	}
}

int BfsJihoon() {
	queue<Point> q;
	q.push(Jihoon);
	visited[Jihoon.y][Jihoon.x] = 1;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		if (cp.y == 0 || cp.y == R - 1 || cp.x == 0 || cp.x == C - 1)
			return visited[cp.y][cp.x];

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= R || np.x < 0 || np.x >= C)
				continue;

			if (visited[np.y][np.x] > 0)
				continue;
			if (map[np.y][np.x] == '#')
				continue;
			if (visited_fire[np.y][np.x] != 0 && visited_fire[np.y][np.x] <= visited[cp.y][cp.x] + 1)
				continue;

			//Print(np);
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}

	}

	return -1;
}