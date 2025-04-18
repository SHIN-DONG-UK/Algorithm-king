#include <iostream>

#define NINE 9
#define MAX_N 50
using namespace std;

int N;
int path[NINE];
int visited[NINE];
int results[MAX_N][NINE];
int ans;

void Input();
void Go(int idx);
int Calculate();

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	Input();
	Go(0);

	cout << ans << '\n';
	return 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < NINE; j++)
		{
			cin >> results[i][j];
		}
	}
	path[3] = 0;
}

void Go(int idx) {
	if (idx == 3) {
		Go(idx + 1);
		return;
	}

	if (idx == NINE) {
		int tmp = Calculate();
		if (tmp > ans)
			ans = tmp;

		return;
	}

	for (int tnum = 1; tnum < NINE; tnum++)
	{
		if (visited[tnum])
			continue;
		visited[tnum] = 1;
		path[idx] = tnum;
		Go(idx + 1);
		visited[tnum] = 0;
	}
}

int Calculate() {
	int rst = 0;
	int cur_idx = 0;

	for (int i = 0; i < N; i++)
	{
		int base[4] = {0};
		int out = 3;

		while (out > 0)
		{
			int what = results[i][path[cur_idx]];

			if (what == 0)
				out--;
			else if (what == 1) {
				rst += base[3];
				base[3] = base[2];
				base[2] = base[1];
				base[1] = 1;
			}
			else if (what == 2) {
				rst += base[3] + base[2];
				base[3] = base[1];
				base[2] = 1;
				base[1] = 0;
			}
			else if (what == 3) {
				rst += base[3] + base[2] + base[1];
				base[3] = 1;
				base[2] = 0;
				base[1] = 0;
			}
			else if (what == 4) {
				rst += base[3] + base[2] + base[1] + 1;
				base[3] = 0;
				base[2] = 0;
				base[1] = 0;
			}

			cur_idx = (cur_idx + 1) % 9;

		}
	}

	return rst;
}