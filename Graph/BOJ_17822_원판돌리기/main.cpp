#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct Point
{
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int board[51][51];
int removed[51][51];
int visited[51][51];
int storage[51];
int storage_removed[51];

int N, M, K;
int sum;

void Input();
void Simulation();
void Rotate(int num, int dir, int k);
void RemoveSame();

int main()
{
	Input();
	Simulation();

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (removed[i][j])
				continue;
			sum += board[i][j];
		}
	}
	cout << sum << '\n';

	return 0;
}

void Input()
{
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}
}

void Simulation()
{
	int x, d, k;
	for (int t = 0; t < K; t++)
	{
		cin >> x >> d >> k;
		// x의 배수 원판 다 회전
		for (int num = x; num <= N; num += x)
		{
			Rotate(num, d, k);
		}
		// 제거
		RemoveSame();
	}
}

void Rotate(int num, int dir, int k)
{
	int step = k;
	if (dir == 1)
		step *= -1;
	int next;
	for (int i = 0; i < M; i++)
	{
		next = (i + step + M) % M + 1;
		storage[next] = board[num][i + 1];
		storage_removed[next] = removed[num][i + 1];
	}
	for (int i = 1; i <= M; i++)
	{
		board[num][i] = storage[i];
		removed[num][i] = storage_removed[i];
	}
}

void RemoveSame()
{
	memset(visited, 0, sizeof(visited));

	bool flag = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visited[i][j])
				continue;
			if (removed[i][j])
				continue;

			queue<Point> q;
			q.push({ i ,j });
			visited[i][j] = 1;
			
			Point cp, np;
			while (!q.empty())
			{
				cp = q.front(); q.pop();
				for (int d = 0; d < 4; d++)
				{
					np = { cp.y + dy[d], cp.x + dx[d] };
					// 양 끝 원판에서 인접하는 것은 하나
					if (np.y <= 0 || np.y > N)
						continue;
					// 좌우로는 Ring 자료구조
					// np 보정
					if (np.x == 0)
						np.x = M;
					else if (np.x == M + 1)
						np.x = 1;
					if (visited[np.y][np.x] == 1)
						continue;
					if (board[np.y][np.x] != board[i][j])
						continue;
					if (removed[np.y][np.x] == 1)
						continue;
					visited[np.y][np.x] = 1;
					q.push(np);

					removed[np.y][np.x] = 1;
					removed[i][j] = 1;
					flag = true;
				}
			}
		}
	}
	double mean = 0;
	double cnt = 0;
	if (!flag)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (removed[i][j])
					continue;
				mean += board[i][j];
				cnt++;
			}
		}
		mean /= cnt;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (removed[i][j])
					continue;
				if (board[i][j] > mean)
					board[i][j] -= 1;
				else if (board[i][j] < mean)
					board[i][j] += 1;
			}
		}
	}
}