#include <iostream>
#include <cstring>
using namespace std;

struct Point 
{
	int y;
	int x;
};

int N;
int visited[20];
Point zis[20];
long long ans;

void init();
void input();
void go(int idx, int start);

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		go(0, 0);

		cout << "#" << tc << " " << ans << '\n';
	}
}

void init()
{
	memset(visited, 0, sizeof(visited));
	ans = 80000000001;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		zis[i] = { a,b };
	}
}

void go(int idx, int start)
{
	if (idx == N / 2) {
		long long y = 0;
		long long x = 0;
		for (int i = 0; i < N; i++)
		{
			if (visited[i] == 1) {
				y += zis[i].y;
				x += zis[i].x;
			}
			else {
				y -= zis[i].y;
				x -= zis[i].x;
			}
		}
		long long tmp = y * y + x * x;
		if (ans > tmp) ans = tmp;
		return;
	}

	for (int i = start; i < N; i++)
	{
		if (visited[i] == 1) continue;
		visited[i] = 1;
		go(idx + 1, i + 1);
		visited[i] = 0;
	}
}