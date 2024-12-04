#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Shark
{
	int r, c, s, d, z;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,1,-1 };
vector<Shark> shark_info_vector;
int board[101][101];
int next_board[101][101];
int catched[10001];

int R, C, M;
int ans;

void Input();
void Simulation();
void CatchShark(int idx);
void MoveShark();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Simulation();

	cout << ans << '\n';
	return 0;
}

void Input()
{	
	shark_info_vector.push_back({ -1,-1,-1 }); // 쓰레기값
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 1; i <= M; i++)
	{
		cin >> r >> c >> s >> d >> z;
		board[r][c] = i;
		shark_info_vector.push_back({ r,c,s,d,z });
	}
}

void Simulation()
{
	int j = 1;
	while (j <= C)
	{
		CatchShark(j);
		MoveShark();
		j++;
	}
}

void CatchShark(int idx)
{
	for (int i = 1; i <= R; i++)
	{
		if (board[i][idx] > 0)
		{
			ans += shark_info_vector[board[i][idx]].z;
			catched[board[i][idx]] = 1;
			board[i][idx] = 0;
			
			break;
		}
	}
}

void MoveShark()
{
	for (int curNum = 1; curNum <= M; curNum++)
	{
		if (catched[curNum] == 1)
			continue;
		// 1회 이동 횟수 t = C - 1
		// 이동 속도를 t로 나눈 몫이 짝수면 현위치와 방향 그대로
		// 양 끝 위치에서는 사실 방향이 중요하지 않음
		// 이 사실을 근거로 일단 짝수만큼 횟수를 차감하고,
		// 부족하거나 넘치는 양을 직접 반복문으로 구현
		int t;
		Shark shark = shark_info_vector[curNum];
		if (shark.d == 1 || shark.d == 2)
			t = R - 1;
		else
			t = C - 1;
		
		int m = shark.s / t;
		int n = shark.s % t;

		if (m % 2 == 0)
		{
			// over -> 나머지만큼 추가로 이동
			// 상하
			if (shark.d == 1 || shark.d == 2)
			{
				if (shark.r == 1)
				{
					shark.r += n;
					shark.d = 2;
				}
				else if (shark.r == R)
				{
					shark.r -= n;
					shark.d = 1;
				}
				else
				{
					int ny;
					for (int k = 0; k < n; k++)
					{
						ny = shark.r + dy[shark.d - 1];
						if (ny == 0)
						{
							ny = 2;
							shark.d = 2;
						}
							
						else if (ny == R + 1)
						{
							ny = R - 1;
							shark.d = 1;
						}
						shark.r = ny;
					}
				}
			}
			// 우좌
			else
			{
				if (shark.c == 1)
				{
					shark.c += n;
					shark.d = 3;
				}
				else if (shark.c == C)
				{
					shark.c -= n;
					shark.d = 4;
				}
				else
				{
					int nx;
					for (int k = 0; k < n; k++)
					{
						nx = shark.c + dx[shark.d - 1];
						if (nx == 0)
						{
							nx = 2;
							shark.d = 3;
						}

						else if (nx == C + 1)
						{
							nx = C - 1;
							shark.d = 4;
						}
						shark.c = nx;
					}
				}
			}
		}
		else
		{
			// under -> 부족한만큼 반대로 이동
			// 반대 ? -> 현재 방향에서 반대
			// 상하
			n = t - n;
			if (shark.d == 1 || shark.d == 2)
			{
				if (shark.r == 1)
				{
					shark.r += n; // 일치
					shark.d = 1; // m이 짝수이면 2, 홀수이면 1
				}
				else if (shark.r == R)
				{
					shark.r -= n; // 일치
					shark.d = 2; // m이 짝수이면 1, 홀수이면 2
				}
				else
				{
					int ny;
					for (int k = 0; k < n; k++)
					{
						ny = shark.r - dy[shark.d - 1]; // m이 짝수이면 +, 홀수이면 -
						if (ny == 0)
						{
							ny = 2;
							shark.d = 1; // m이 짝수이면 2, 홀수이면 1
						}

						else if (ny == R + 1)
						{
							ny = R - 1;
							shark.d = 2; // m이 짝수이면 1, 홀수이면 2
						}
						shark.r = ny;
					}
				}
			}
			// 우좌
			else
			{
				if (shark.c == 1)
				{
					shark.c += n;
					shark.d = 4; // m이 짝수이면 3, 홀수이면 4
				}
				else if (shark.c == C)
				{
					shark.c -= n;
					shark.d = 3; // m이 짝수이면 4, 홀수이면 3
				}
				else
				{
					int nx;
					for (int k = 0; k < n; k++)
					{
						nx = shark.c - dx[shark.d - 1]; // m이 짝수이면 +, 홀수이면 -
						if (nx == 0)
						{
							nx = 2;
							shark.d = 4; // m이 짝수면 3, 홀수면 4
						}

						else if (nx == C + 1)
						{
							nx = C - 1;
							shark.d = 3; // m이 짝수면 4, 홀수면 3
						}
						shark.c = nx;
					}
				}
			}
		}
		shark_info_vector[curNum] = shark; // 업데이트

	}
	
	memset(next_board, 0, sizeof(next_board));

	Shark shark;
	for (int i = 1; i <= M; i++)
	{
		if (catched[i] == 1)
			continue;
		shark = shark_info_vector[i];
		if (next_board[shark.r][shark.c] > 0)
		{
			if (shark.z > shark_info_vector[next_board[shark.r][shark.c]].z)
			{
				catched[next_board[shark.r][shark.c]] = 1;
				next_board[shark.r][shark.c] = i;
			}
			else
				catched[i] = 1;
		}
		else
			next_board[shark.r][shark.c] = i;
	}
	// 실제 맵에 반영
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			board[i][j] = next_board[i][j];
		}
	}
}

