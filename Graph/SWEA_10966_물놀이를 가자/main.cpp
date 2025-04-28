#include <iostream>
#include <queue>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point
{
	int y;
	int x;
};

int N, M;
int MAP[1001][1001];
int ans;

void init();
void process();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		process();

		cout << "#" << tc << " " << ans << '\n';
	}
}

void init()
{
	ans = 0;
}

void process()
{
	cin >> N >> M;
	queue<Point> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char ch;
			cin >> ch;
			if (ch == 'W')
			{
				MAP[i][j] = 0;
				q.push({ i,j });
			}
			else MAP[i][j] = -1;
		}
	}

	Point np, cp;
	while (!q.empty())
	{
		cp = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
			if (MAP[np.y][np.x] != -1) continue;
			MAP[np.y][np.x] = MAP[cp.y][cp.x] + 1;
			ans += MAP[np.y][np.x];
			q.push(np);
		}
	}
}