#include <iostream>
#include <vector>
using namespace std;

// 상 우상 우 우하 하 좌하 좌 좌상
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

struct Com
{
	int x;
	int y;
	int dol;
};

int N, M;
int MAP[9][9];
vector<Com> v;
int ans1, ans2;

void init();
void input();
void simulation();
bool go(int y, int x, int dol, int dir);
void print(int y, int x);

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		simulation();

		cout << "#" << tc << " " << ans1 << " " << ans2 << '\n';
	}
}

void init()
{
	v.clear();
	ans1 = 0; ans2 = 0;
}

void input()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			if (i == N / 2 && j == N / 2) MAP[i][j] = 2;
			else if (i == N / 2 && j == N / 2 + 1) MAP[i][j] = 1;
			else if (i == N / 2 + 1 && j == N / 2) MAP[i][j] = 1;
			else if (i == N / 2 + 1 && j == N / 2 + 1) MAP[i][j] = 2;
			else MAP[i][j] = 0;
		}
	}
}

void simulation()
{
	for (int i = 0; i < M; i++)
	{
		MAP[v[i].y][v[i].x] = v[i].dol;

		for (int d = 0; d < 8; d++)
		{
			int ny = v[i].y + dy[d];
			int nx = v[i].x + dx[d];
			if (ny <= 0 || ny > N || nx <= 0 || nx > N) continue;
			if (MAP[ny][nx] == 0 || MAP[ny][nx] == v[i].dol) continue;
			if(go(ny, nx, v[i].dol, d)) MAP[ny][nx] = v[i].dol == 1 ? 1 : 2;
		}
		
	}
	
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (MAP[i][j] == 1) ans1++;
			else if(MAP[i][j] == 2) ans2++;
		}
	}
}

bool go(int y, int x, int dol, int dir)
{
	//print(y, x);
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	if (ny <= 0 || ny > N || nx <= 0 || nx > N) return false;
	if (MAP[ny][nx] == 0) return false;
	if (MAP[ny][nx] == dol) return true;

	MAP[ny][nx] = dol == 1 ? 1 : 2;
	if(go(ny, nx, dol, dir)) return true;
	MAP[ny][nx] = dol == 1 ? 2 : 1;
	return false;
}

void print(int y, int x)
{
	cout << '\n';
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == y && j == x) cout << "* ";
			else cout << MAP[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}