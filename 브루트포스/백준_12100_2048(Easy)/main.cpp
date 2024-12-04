#include <iostream>
#include <cstring>

#define ll long long
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
ll original_board[20][20];
ll board[20][20];
int visited[20][20];
int path[5];

int N;
ll ans;

void Input();
void BruteForce(int lev, int limit);
void MoveBlock(int dir);

int main()
{
	Input();
	for (int limit = 1; limit <= 5; limit++)
		BruteForce(0, limit);

	cout << ans << '\n';

	return 0;
}

void Input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> original_board[i][j];
		}
	}
}

void BruteForce(int lev, int limit)
{
	if (lev == limit)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				board[i][j] = original_board[i][j];
			}
		}

		for (int i = 0; i < limit; i++)
			MoveBlock(path[i]);
		
		ll maxVal = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (maxVal < board[i][j])
					maxVal = board[i][j];
			}
		}

		if (maxVal > ans)
			ans = maxVal;

		return;
	}
		
	for (int d = 0; d < 4; d++)
	{
		path[lev] = d;
		BruteForce(lev + 1, limit);
	}
}

void MoveBlock(int dir)
{
	memset(visited, 0, sizeof(visited));

	if (dir == 0)
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 0)
					continue;

				int cur = i;
				int ny;
				while (true)
				{
					ny = cur + dy[dir];

					if (ny < 0)
					{
						if (cur != i)
						{
							board[cur][j] = board[i][j];
							board[i][j] = 0;
						}						
						break;
					}
					
					if (board[ny][j] > 0)
					{
						if (board[ny][j] == board[i][j])
						{
							if (visited[ny][j] == 0)
							{
								board[i][j] = 0;
								board[ny][j] *= 2;
								visited[ny][j] = 1;
							}
							else
							{
								if (cur != i)
								{
									board[cur][j] = board[i][j];
									board[i][j] = 0;
								}
							}
						}
						else
						{
							if (cur != i)
							{
								board[cur][j] = board[i][j];
								board[i][j] = 0;
							}
						}

						break;
					}
					cur = ny;
				}

			}
			
		}
	}
	else if (dir == 1)
	{
		for (int i = N-2; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				if (board[i][j] == 0)
					continue;

				int cur = i;
				int ny;
				while (true)
				{
					ny = cur + dy[dir];

					if (ny >= N)
					{
						if (cur != i)
						{
							board[cur][j] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}

					if (board[ny][j] > 0)
					{
						if (board[ny][j] == board[i][j])
						{
							if (visited[ny][j] == 0)
							{
								board[i][j] = 0;
								board[ny][j] *= 2;
								visited[ny][j] = 1;
							}
							else
							{
								if (cur != i)
								{
									board[cur][j] = board[i][j];
									board[i][j] = 0;
								}
							}
						}
						else
						{
							if (cur != i)
							{
								board[cur][j] = board[i][j];
								board[i][j] = 0;
							}
						}

						break;
					}
					cur = ny;
				}

			}

		}
	}
	else if (dir == 2)
	{
		for (int j = 1; j < N; j++)
		{
			for (int i = 0; i < N; i++)
			{
				if (board[i][j] == 0)
					continue;

				int cur = j;
				int nx;
				while (true)
				{
					nx = cur + dx[dir];

					if (nx < 0)
					{
						if (cur != j)
						{
							board[i][cur] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}

					if (board[i][nx] > 0)
					{
						if (board[i][nx] == board[i][j])
						{
							if (visited[i][nx] == 0)
							{
								board[i][j] = 0;
								board[i][nx] *= 2;
								visited[i][nx] = 1;
							}
							else
							{
								if (cur != j)
								{
									board[i][cur] = board[i][j];
									board[i][j] = 0;
								}
							}
						}
						else
						{
							if (cur != j)
							{
								board[i][cur] = board[i][j];
								board[i][j] = 0;
							}
						}

						break;
					}
					cur = nx;
				}

			}

		}
	}
	else
	{
		for (int j = N - 2; j >= 0; j--)
		{
			for (int i = 0; i < N; i++)
			{
				if (board[i][j] == 0)
					continue;

				int cur = j;
				int nx;
				while (true)
				{
					nx = cur + dx[dir];

					if (nx >= N)
					{
						if (cur != j)
						{
							board[i][cur] = board[i][j];
							board[i][j] = 0;
						}
						break;
					}

					if (board[i][nx] > 0)
					{
						if (board[i][nx] == board[i][j])
						{
							if (visited[i][nx] == 0)
							{
								board[i][j] = 0;
								board[i][nx] *= 2;
								visited[i][nx] = 1;
							}
							else
							{
								if (cur != j)
								{
									board[i][cur] = board[i][j];
									board[i][j] = 0;
								}
							}
						}
						else
						{
							if (cur != j)
							{
								board[i][cur] = board[i][j];
								board[i][j] = 0;
							}
						}

						break;
					}
					cur = nx;
				}

			}

		}
	}
}