#include <iostream>

#define MAX_N 5
using namespace std;

struct Point {
	int y;
	int x;
};

// 상 우 하 좌
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int N, Q;
char map[MAX_N][MAX_N];

Point st, ed;

void Input();
void Simul();
bool CanGo(Point np);

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Input();
		cout << '#' << tc << ' ';
		Simul();
	}
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'X')
				st = { i,j };
			else if (map[i][j] == 'Y')
				ed = { i,j };
		}
	}
	cin >> Q;
}

void Simul() {
	int len;
	char com;
	for (int i = 0; i < Q; i++)
	{
		cin >> len;
		
		Point cp, np;
		cp = st;
		int dir = 0;

		for (int j = 0; j < len; j++)
		{
			cin >> com;
			if (com == 'R')
				dir = (dir + 1) % 4;
			else if (com == 'L')
				dir = (dir - 1 + 4) % 4;
			else {
				np = { cp.y + dy[dir], cp.x + dx[dir] };
				if (CanGo(np)) {
					cp = np;
				}
			}

		}
		if (map[cp.y][cp.x] == 'Y')
			cout << "1 ";
		else
			cout << "0 ";

	}
	cout << '\n';
}

bool CanGo(Point np) {
	if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N || map[np.y][np.x] == 'T')
		return false;
	else
		return true;
}