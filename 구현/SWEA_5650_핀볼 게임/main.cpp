#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define MAX 100
using namespace std;

struct Point {
	int y;
	int x;
};

// 상 하 좌 우
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int map[MAX+2][MAX+2];
int ans;

int Reflected[6][4] = {
	{0,},
	{1, 3, 0, 2},
	{3, 0, 1, 2},
	{2, 0, 3, 1},
	{1, 2, 3, 0},
	{1, 0, 3, 2}
};

Point wormholes[5][2];

void Init();
void Input();
void Solve();
int Simul(Point sp, int dir);
void Print(Point cp);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Init();
		Input();
		Solve();
		cout << '#' << tc << ' ' << ans << '\n';
	}

	return 0;
}

void Init() {
	memset(wormholes, 0, sizeof(wormholes));
	ans = 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i <= N + 1; i++)
	{
		map[i][0] = 5;
		map[i][N + 1] = 5;
	}

	for (int j = 0; j <= N+1; j++)
	{
		map[0][j] = 5;
		map[N + 1][j] = 5;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 6) {
				if (wormholes[map[i][j] - 6][0].y == 0)
					wormholes[map[i][j] - 6][0] = { i, j };
				else
					wormholes[map[i][j] - 6][1] = { i, j };
				
			}
		}
	}
}

void Solve() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (map[i][j] == 0) {
				for (int d = 0; d < 4; d++)
				{
					int tmp = Simul({ i, j }, d);
					if (tmp > ans)
						ans = tmp;
				}
			}
		}
	}
}

int Simul(Point sp, int d) {
	int cnt = 0;

	Point cp = sp;
	Point np;
	int dir = d;
	while (true) {
		//Print(cp);
		np = { cp.y + dy[dir], cp.x  + dx[dir] };
		if (map[np.y][np.x] == 0)
			cp = np; // 전진
		// 벽
		else if (map[np.y][np.x] >= 1 && map[np.y][np.x] <= 5) {
			dir = Reflected[map[np.y][np.x]][dir];
			cp = np;
			cnt++;
		}
		// 웜홀 이동
		else if (map[np.y][np.x] >= 6 && map[np.y][np.x] <= 10) {
			if (wormholes[map[np.y][np.x] - 6][0].y == np.y && wormholes[map[np.y][np.x] - 6][0].x == np.x)
				cp = wormholes[map[np.y][np.x] - 6][1];
			else
				cp = wormholes[map[np.y][np.x] - 6][0];
		}
		
		if (map[np.y][np.x] == -1)
			return cnt;
		else if (np.y == sp.y && np.x == sp.x)
			return cnt;
	}
	
	return cnt;
}

void Print(Point cp) {
	cout << '\n';
	for (int i = 0; i <= N+1; i++)
	{
		for (int j = 0; j <= N+1; j++)
		{
			if (cp.y == i && cp.x == j)
				cout << "* ";
			else
				cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}