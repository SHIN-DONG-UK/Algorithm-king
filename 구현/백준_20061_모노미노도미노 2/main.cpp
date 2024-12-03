#include <iostream>

#define BOARD_SIZE 10

using namespace std;

int board[10][10];

int N;
int ans;

void Simulation();
void MoveBlock(int t, int y, int x);
void GetScore();
void SpecialArea();

int main()
{
	cin >> N;
	Simulation();

	cout << ans << '\n';
	int cnt = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[i][j] == 1)
				cnt++;
		}
	}
	cout << cnt << '\n';
}

void Simulation()
{
	int t, y, x;
	while (N--)
	{
		cin >> t >> y >> x;
		MoveBlock(t, y, x);
		GetScore();
		SpecialArea();
	}
}

void MoveBlock(int t, int y, int x)
{
	
	if (t == 1)
	{
		// green
		int i;
		for (i = 6; i < BOARD_SIZE; i++)
		{
			if (board[i][x] == 1)
				break;
		}
		board[i - 1][x] = 1;
		// blue
		int j;
		for (j = 6; j < BOARD_SIZE; j++)
		{
			if (board[y][j] == 1)
				break;
		}
		board[y][j - 1] = 1;
	}
	else if (t == 2)
	{
		// green
		int i;
		for (i = 6; i < BOARD_SIZE; i++)
		{
			if (board[i][x] == 1 || board[i][x + 1] == 1)
				break;
		}
		board[i - 1][x] = 1; board[i - 1][x + 1] = 1;
		// blue
		int j;
		for (j = 6; j < BOARD_SIZE; j++)
		{
			if (board[y][j] == 1)
				break;
		}
		board[y][j - 1] = 1; board[y][j - 2] = 1;

	}
	else
	{
		// green
		int i;
		for (i = 6; i < BOARD_SIZE; i++)
		{
			if (board[i][x] == 1)
				break;
		}
		board[i - 1][x] = 1; board[i - 2][x] = 1;
		// blue
		int j;
		for (j = 6; j < BOARD_SIZE; j++)
		{
			if (board[y][j] == 1 || board[y + 1][j] == 1)
				break;
		}
		board[y][j - 1] = 1; board[y + 1][j - 1] = 1;
	}
}

void GetScore()
{
	// green
	for (int i = 6; i < BOARD_SIZE; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 1)
				cnt++;
		}

		if (cnt == 4)
		{
			// 1점 획득
			ans += 1;
			// 블록 제거
			for (int j = 0; j < 4; j++)
				board[i][j] = 0;
			// 위에 있는 블록 내리기
			for (int y = i; y > 4; y--)
			{
				for (int j = 0; j < 4; j++)
				{
					board[y][j] = board[y - 1][j];
				}
			}
		}

	}
	// blue
	for (int j = 6; j < BOARD_SIZE; j++)
	{
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j] == 1)
				cnt++;
		}

		if (cnt == 4)
		{
			// 1점 획득
			ans += 1;
			// 블록 제거
			for (int i = 0; i < 4; i++)
				board[i][j] = 0;
			// 왼쪽에 있는 블록 옮기기
			for (int x = j; x > 4; x--)
			{
				for (int i = 0; i < 4; i++)
				{
					board[i][x] = board[i][x - 1];
				}
			}
		}
	}
}

void SpecialArea()
{
	// green
	int cnt = 0;
	for (int i = 4; i < 6; i++)
	{
		bool flag = false;
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	if (cnt > 0)
	{
		// 제거(끝쪽)
		for (int i = 9; i > 9 - cnt; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = 0;
			}
		}
		// 이동
		for (int i = 9; i >= 6; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = board[i - cnt][j];
			}
		}
		// 제거(특별한 공간)
		for (int i = 4; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				board[i][j] = 0;
			}
		}
	}
	// blue
	cnt = 0;
	for (int j = 4; j < 6; j++)
	{
		bool flag = false;
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j] == 1) {
				flag = true;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	if (cnt > 0)
	{
		// 제거(끝쪽)
		for (int j = 9; j > 9 - cnt; j--)
		{
			for (int i = 0; i < 4; i++)
			{
				board[i][j] = 0;
			}
		}
		// 이동
		for (int j = 9; j >= 6; j--)
		{
			for (int i = 0; i < 4; i++)
			{
				board[i][j] = board[i][j - cnt];
			}
		}
		// 제거(특별한 공간)
		for (int j = 4; j < 6; j++)
		{
			for (int i = 0; i< 4; i++)
			{
				board[i][j] = 0;
			}
		}
	}
	
}