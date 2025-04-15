#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct Point {
	int y;
	int x;
};

// 초반에 내부 빈공간 한 번 인식해 놔야 함
// 
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N, M;
int map[102][102]; // 치즈 1, 빈 공간 0, 내부 빈공간 2 <- 내가 찾아야 하는 거
int outer_map[102][102];
int visited[102][102];

vector<Point> v;

void Input();
void TurnOff();
bool Melting();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();

	int t = 0;

	TurnOff();

	while (Melting()) {
		TurnOff();
		t++;
	}
	
	cout << t << '\n';
	return 0;
}

void Input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}
}

bool Melting() {
	// 치즈가 있는 위치 찾기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1) {
				int ny, nx;
				int cnt = 0;
				for (int d = 0; d < 4; d++)
				{
					ny = i + dy[d]; nx = j + dx[d];
					if (outer_map[ny][nx] == -1 && map[ny][nx] == 0)
						cnt++;
				}
				if (cnt >= 2)
					v.push_back({ i, j });
			}
		}
	}
	if (v.size() == 0)
		return false;
	// 치즈 지우기
	for (int i = 0; i < v.size(); i++)
	{
		Point cp = v[i];
		map[cp.y][cp.x] = 0;
	}
	v.clear();
	return true;
}

void TurnOff() {
	memset(visited, 0, sizeof(visited));
	memset(outer_map, 0, sizeof(outer_map));

	queue<Point> q;
	visited[0][0] = 1;
	outer_map[0][0] = -1;
	q.push({ 0,0 });

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N + 2 || np.x < 0 || np.x >= M + 2)
				continue;
			if (map[np.y][np.x] == 1)
				continue;
			if (visited[np.y][np.x])
				continue;
			visited[np.y][np.x] = 1;
			outer_map[np.y][np.x] = -1;
			q.push(np);
		}
	}
}