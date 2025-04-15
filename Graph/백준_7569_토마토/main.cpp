#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y;
	int x;
	int z;
};

int dy[6] = { 0,0,-1,1,0,0 };
int dx[6] = { 0,0,0,0,-1,1 };
int dz[6] = { 1,-1,0,0,0,0 };

int N, M, H;
int MAP[100][100][100];
int visited[100][100][100];
int ans;
int cnt;

queue<Point> q;


void input();
void solve();
void output();

int main() {
	input();
	solve();
	if (cnt != 0) cout << -1 << '\n';
	else {
		if (ans == 0) cout << ans << '\n';
		else cout << ans - 1 << '\n';
	}
	//output();
}

void input() {
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> MAP[i][j][k];
				if (MAP[i][j][k] == 0) cnt++;
				if (MAP[i][j][k] == 1) {
					q.push({ i,j,k });
					visited[i][j][k] = 1;
				}
			}
		}
	}
}

void solve() {
	if (cnt == 0) return;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front();
		q.pop();

		for (int d = 0; d < 6; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d], cp.z + dz[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M || np.z < 0 || np.z >= H) continue;
			if (visited[np.y][np.x][np.z] > 0) continue;
			if (MAP[np.y][np.x][np.z] != 0) continue;
			visited[np.y][np.x][np.z] = visited[cp.y][cp.x][cp.z] + 1;
			q.push(np);

			// 정답 제출용
			if (visited[np.y][np.x][np.z] > ans) ans = visited[np.y][np.x][np.z];
			cnt--;
		}
		
	}
}

void output() {
	cout << '\n';
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cout << MAP[i][j][k] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	cout << '\n';
}