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
void go(int idx, int cnt, long long sumY, long long sumX);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		go(0, 0, 0, 0);

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

void go(int idx, int cnt, long long sumY, long long sumX)
{
	if (cnt > N / 2) return;
	if (idx == N)
	{
		if (cnt == N / 2)
		{
			long long tmp = sumY * sumY + sumX * sumX;
			if (ans > tmp) ans = tmp;
			return;
		}
		else return;
	}
	go(idx + 1, cnt + 1, sumY - zis[idx].y, sumX - zis[idx].x);
	go(idx + 1, cnt, sumY + zis[idx].y, sumX + zis[idx].x);
}