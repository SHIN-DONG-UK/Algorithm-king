#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int map[100][100];
int visited[100][100];
//int visited_boundary[100][100];
vector<vector<Point>> islands;

void Input();
void GetIsland();
void BFS(Point sp, int num);
int GetMindist();
int CalcDist(Point* a, Point* b);

int main() {
	Input();
	GetIsland();
	int ans = GetMindist();

	cout << ans << '\n';

	return 0;

}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
}

void GetIsland() {
	int num = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (visited[i][j] == 0 && map[i][j] == 1) {
				BFS({ i,j }, num);
				num++;
			}
			
		}
	}
	// 결과 : islands 좌표 구성
}

void BFS(Point sp, int num) {
	vector<Point> island;
	queue<Point> q;
	q.push(sp);
	island.push_back(sp);
	visited[sp.y][sp.x] = num;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++){
			np = { cp.y + dy[d], cp.x + dx[d] };

			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N)
				continue;
			/*
			if (visited_boundary[cp.y][cp.x] == 0 && map[np.y][np.x] == 0) {
				// 경계만 island에 담기
				visited_boundary[cp.y][cp.x] = 1;
				island.push_back(cp);
			}*/

			if (visited[np.y][np.x] == 0 && map[np.y][np.x] == 1) {
				visited[np.y][np.x] = num;
				q.push(np);
				island.push_back(np);
			}
			
		}
	}
	islands.push_back(island);
}

int GetMindist() {
	int rst = 1e9;
	int tmp;
	for (int i = 0; i < islands.size() - 1; i++)
	{
		for (int j = i+1; j < islands.size(); j++)
		{
			for (int m = 0; m < islands[i].size(); m++)
			{
				for (int n = 0; n < islands[j].size(); n++)
				{
					tmp = CalcDist(&islands[i][m], &islands[j][n]);
					if (rst > tmp)
						rst = tmp;
				}
			}
		}
	}
	return rst - 1;
}

int CalcDist(Point* a, Point* b) {
	return abs(a->y - b->y) + abs(a->x - b->x);
}