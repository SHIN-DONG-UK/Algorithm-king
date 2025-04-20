#include <iostream>
using namespace std;

int N;
int arr[22][22];
int path[5];
int ans;

void input();
void BruteForce(int lev);
void move(int board[22][22], int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	BruteForce(0);

	cout << ans << '\n';
	return 0;
}

void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i <= N + 1; i++) {
		arr[i][0] = -1;
		arr[i][N + 1] = -1;
	}
	for (int j = 0; j <= N + 1; j++) {
		arr[0][j] = -1;
		arr[N + 1][j] = -1;
	}
}

// 0:상 1:하 2:좌 3:우
void BruteForce(int lev) {
	if (lev == 5) {
		int board[22][22] = { 0, };
		for (int i = 0; i <= N + 1; i++) {
			for (int j = 0; j <= N + 1; j++) {
				board[i][j] = arr[i][j];
			}
		}

		for (int i = 0; i < 5; i++)
			move(board, path[i]);

		int tmp = 0;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j] > tmp)
					tmp = board[i][j];
			}
		}

		if (tmp > ans)
			ans = tmp;

		return;
	}
	for (int i = 0; i < 4; i++)
	{
		path[lev] = i;
		BruteForce(lev + 1);
	}
}

void move(int board[22][22], int dir)
{
	int visited[22][22] = { 0, };

	if (dir == 0) {
		//상
		for (int i = 2; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int ny = i;
				if (board[i][j] > 0) {
					while (1) {
						ny--;
						if (board[ny][j] == board[i][j]) {
							if (visited[ny][j] == 0) {
								board[ny][j] += board[i][j];
								board[i][j] = 0;
								visited[ny][j] = 1;
								break;
							}
							
						}
						if (board[ny][j] == -1 || board[ny][j] > 0) {
							if (ny + 1 == i)
								break;
							board[ny + 1][j] = board[i][j];
							board[i][j] = 0;
							break;
						}
						
					}
				}
			}
		}
	}
	else if (dir == 1) {
		//하
		for (int i = N - 1; i >= 1; i--) {
			for (int j = 1; j <= N; j++) {
				int ny = i;
				if (board[i][j] > 0) {
					while (1) {
						ny++;
						if (board[ny][j] == board[i][j]) {
							if (visited[ny][j] == 0) {
								board[ny][j] += board[i][j];
								board[i][j] = 0;
								visited[ny][j] = 1;
								break;
							}
						}
						if (board[ny][j] == -1 || board[ny][j] > 0) {
							if (ny - 1 == i)
								break;
							board[ny - 1][j] = board[i][j];
							board[i][j] = 0;
							break;
						}

					}
				}
			}
		}
	}
	else if (dir == 2) {
		//좌
		for (int j = 2; j <= N; j++) {
			for (int i = 1; i <= N; i++) {
				int nx = j;
				if (board[i][j] > 0) {
					while (1) {
						nx--;
						if (board[i][nx] == board[i][j]) {
							if (visited[i][nx] == 0) {
								board[i][nx] += board[i][j];
								board[i][j] = 0;
								visited[i][nx] = 1;
								break;
							}
						}
						if (board[i][nx] == -1 || board[i][nx] > 0) {
							if (nx + 1 == j)
								break;
							board[i][nx + 1] = board[i][j];
							board[i][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else {
		//우
		for (int j = N - 1; j >= 1; j--) {
			for (int i = 1; i <= N; i++) {
				int nx = j;
				if (board[i][j] > 0) {
					while (1) {
						nx++;
						if (board[i][nx] == board[i][j]) {
							if (visited[i][nx] == 0) {
								board[i][nx] += board[i][j];
								board[i][j] = 0;
								visited[i][nx] = 1;
								break;
							}
							
						}
						if (board[i][nx] == -1 || board[i][nx] > 0) {
							if (nx - 1 == j)
								break;
							board[i][nx - 1] = board[i][j];
							board[i][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
}