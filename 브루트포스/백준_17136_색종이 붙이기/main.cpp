#include <iostream>

#define MAX_N 10
using namespace std;

int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int rem[6];
int ans = 1e9;
int ALL;

void Input();
bool ColorPaper(int y, int x, int num, int flag);
void Go(int y, int x, int cnt, int lev);

int main() {
	Input();
	Go(0, 0, 0, 0);

	ans = ans == 1e9 ? -1 : ans;
	cout << ans << '\n';
	return 0;
}

void Input() {
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 1)
				ALL++;
		}
	}

	for (int i = 1; i <= 5; i++)
		rem[i] = 5;
	
}

bool ColorPaper(int y, int x, int num, int flag) {
	if (flag) {
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				int ny = y + i;
				int nx = x + j;

				if (ny < 0 || ny >= MAX_N || nx < 0 || nx >= MAX_N)
					return false;

				else if (map[ny][nx] == 0)
					return false;

				else if (visited[ny][nx] == 1)
					return false;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			visited[y + i][x + j] = flag;
		}
	}
	return true;
}

void Go(int y, int x, int cnt, int lev) {
	if (cnt == ALL) {
		if (ans > lev)
			ans = lev;
		return;
	}
	
	for (int i = 0; i < MAX_N; i++)
	{
		for (int j = 0; j < MAX_N; j++)
		{
			if (map[i][j] == 0)
				continue;

			if (visited[i][j] == 1)
				continue;

			// 덮어야 할 1을 찾음
			for (int num = 1; num <= 5; num++) {
				if (rem[num] == 0)
					continue;
				
				if (ColorPaper(i, j, num, 1)) {
					rem[num]--;
					Go(i, j, cnt + (num*num), lev + 1);
					rem[num]++; // 원복
					ColorPaper(i, j, num, 0); // 원복
					
				}
				
			}
			return; // 이 부분이 없어서 시간초과남
			// 종이를 붙일 위치를 찾았으면 return해줘야 함
		}
	}
}