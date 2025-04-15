#include <iostream>
#include <queue>
#include <cstring>

#define MAX_N 20
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int ans;

Point babyshark_pos;
int babyshark_size = 2;
int cnt;

void Input();
void FindFishes();
int EatFish();

int main() {
	Input();

	while (true) {
		memset(visited, 0, sizeof(visited));

		FindFishes();
		int tmp = EatFish();
		if (tmp < 0)
			break;
	}
	
	cout << ans << '\n';
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			// get babyshark pos
			if (map[i][j] == 9) {
				babyshark_pos = { i,j };
				map[i][j] = 0;
			}
				
		}
	}
}

void FindFishes() {
	queue<Point> q;
	visited[babyshark_pos.y][babyshark_pos.x] = 1;
	q.push(babyshark_pos);

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N)
				continue;
			if (visited[np.y][np.x] > 0)
				continue;
			if (map[np.y][np.x] > babyshark_size)
				continue;
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}
}

int EatFish() {
	int min_dist = 1e9;
	Point min_pos;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 0 || map[i][j] >= babyshark_size)
				continue;
			// 이 부분 안넣어놨었네 ㄷㄷㄷ;;
			if (visited[i][j] == 0)
				continue;
			if (min_dist > visited[i][j]) {
				min_dist = visited[i][j];
				min_pos = { i, j };
			}
					
			
		}
	}

	if (min_dist != 1e9) {
		ans += (min_dist - 1);

		map[min_pos.y][min_pos.x] = 0;

		babyshark_pos = min_pos;

		cnt++;
		if (cnt == babyshark_size) {
			babyshark_size++;
			cnt = 0;
		}

		return 0;
	}
	else
		return -1;

}