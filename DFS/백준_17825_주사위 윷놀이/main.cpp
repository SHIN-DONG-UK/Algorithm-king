#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 게임판은 33개의 노드로 이루어 짐
// 0번 노드를 시작점
// 32번 노드를 도착점이라고 하자
// 또한 인접 리스트 방식으로 그래프를 구현하자
vector<int> board[33];
int cost[33];
// i번 말이 몇 번 노드에 있는지 저장하고 있는 배열
int piecepos[4];
// 몇 칸 가야 하는지 기록되어 있는 배열
int steps[10];
int path[10];

bool finish;
int tmpScore;
int maxScore;

void Input();
void BruteForce(int lev);
void Dfs(int lev, int limit, int cur, int piece);

int main()
{
	Input();
	BruteForce(0);
	
	cout << maxScore << '\n';

	return 0;
}

void Input()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> steps[i];
	}
	board[0].push_back(1);
	board[1].push_back(2);
	board[2].push_back(3);
	board[3].push_back(4);
	board[4].push_back(5);

	// blue
	board[5].push_back(6);  // 0 red
	board[5].push_back(31); // 1 blue

	board[6].push_back(7);
	board[7].push_back(8);
	board[8].push_back(9);
	board[9].push_back(10);

	// blue
	board[10].push_back(11); // 0 red
	board[10].push_back(28); // 1 blue
	
	board[11].push_back(12);
	board[12].push_back(13);
	board[13].push_back(14);
	board[14].push_back(15);

	// blue
	board[15].push_back(16); // 0 red
	board[15].push_back(26); // 1 blue
	

	board[16].push_back(17);
	board[17].push_back(18);
	board[18].push_back(19);
	board[19].push_back(23);
	board[20].push_back(21);
	board[21].push_back(22);
	board[22].push_back(23);
	board[23].push_back(32);
	board[26].push_back(25);
	board[25].push_back(24);
	board[24].push_back(20);
	board[28].push_back(27);
	board[27].push_back(20);
	board[31].push_back(30);
	board[30].push_back(29);
	board[29].push_back(20);
	for (int i = 1; i <= 19; i++)
	{
		cost[i] = 2 * i;
	}
	cost[20] = 25;
	cost[21] = 30;
	cost[22] = 35;
	cost[23] = 40;
	cost[24] = 26;
	cost[25] = 27;
	cost[26] = 28;
	cost[27] = 24;
	cost[28] = 22;
	cost[29] = 19;
	cost[30] = 16;
	cost[31] = 13;
}

void BruteForce(int lev)
{
	if (lev == 10) {
		memset(piecepos, 0, sizeof(piecepos));

		finish = false;
		tmpScore = 0;

		int piece, step;
		for (int i = 0; i < 10; i++)
		{
			piece = path[i];
			// 도착 칸에 있는 말 고르면 안됨
			if (piecepos[piece] == 32)
				return;
			step = steps[i];

			int cur = piecepos[piece];
			if (cur == 5 || cur == 10 || cur == 15)
				Dfs(1, step, board[cur][1], piece);
			else
				Dfs(0, step, cur, piece);
			

			// 해당 케이스는 안됨
			if (finish)
				return;
		}

		if (tmpScore > maxScore)
			maxScore = tmpScore;
		
		return;
	}
		
	for (int i = 0; i < 4; i++)
	{
		path[lev] = i;
		BruteForce(lev + 1);
 	}
}

void Dfs(int lev, int limit, int cur, int piece)
{
	if (finish)
		return;

	// 즉시 종료
	if (cur == 32)
	{
		piecepos[piece] = cur;
		return;
	}
	// step번 이동
	if (lev == limit) {
		for (int i = 0; i < 4; i++)
		{
			if (i == piece)
				continue;
			if (cur == piecepos[i]) {
				finish = true;
				return; // 이 말 선택하면 안됨
			}
		}

		piecepos[piece] = cur;
		tmpScore += cost[cur];
		return;
	}
	
	Dfs(lev + 1, limit, board[cur][0], piece);

}