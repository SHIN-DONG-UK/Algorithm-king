#include <iostream>
#include <vector>

#define MAX_N 10
#define MAX_K 5
using namespace std;

struct Point {
	int y;
	int x;
};

// 상우하좌
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int c[4] = { 0,1,2,1 };
int N, K;

char map[MAX_N][MAX_N];
vector<Point> trees;
int path[MAX_K];
int visited[MAX_N][MAX_N];

Point startPos;
Point endPos;
int ans = 1e9;

void Init();
void Input();
void Go(int lev, int start);
void GoPath(int y, int x, int dir, int cnt);

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Init();
		Input();
		Go(0, 0);
		
		if(ans == 1e9)
			cout << '#' << tc << ' ' << -1 << '\n';
		else
			cout << '#' << tc << ' ' << ans << '\n';
	}
	
	return 0;
}

void Init()
{
	ans = 1e9;
	trees.clear();
}

void Input() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')
				trees.push_back({ i,j });
			else if (map[i][j] == 'Y')
				endPos = { i, j };
			else if (map[i][j] == 'X')
				startPos = { i, j };
		}
	}

	if (K > trees.size())
		K = trees.size();
}

void Go(int idx, int start) {
	if (idx == K) {
		// 나무 제거
		for (int i = 0; i < K; i++)
			map[trees[path[i]].y][trees[path[i]].x] = 'G';
		
		visited[startPos.y][startPos.x] = 1;
		GoPath(startPos.y, startPos.x, 0, 0);
		visited[startPos.y][startPos.x] = 0;

		// 원복
		for (int i = 0; i < K; i++)
			map[trees[path[i]].y][trees[path[i]].x] = 'T';
		return;
	}

	for (int i = start; i < trees.size(); i++)
	{
		path[idx] = i;
		Go(idx + 1, i + 1);
	}
}

void GoPath(int y, int x, int dir, int cnt) {
	if (y == endPos.y && x == endPos.x) {
		if (ans > cnt)
			ans = cnt;
		return;
	}

	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[(dir + i) % 4];
		nx = x + dx[(dir + i) % 4];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (map[ny][nx] == 'T')
			continue;

		visited[ny][nx] = 1;
		GoPath(ny, nx, (dir + i) % 4, cnt + c[i] + 1);
		visited[ny][nx] = 0;
	}
}