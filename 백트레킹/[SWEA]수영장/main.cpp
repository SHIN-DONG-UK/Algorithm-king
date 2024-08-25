#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int prices[4];
int nums[12];
int ans = 1e9;

void init();
void input();
void process();
void go(int idx, int sum);

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		process();
		cout << "#" << tc << " " << ans << '\n';

	}
}

void init()
{
	ans = 1e9;
}

void input()
{
	for (int i = 0; i < 4; i++)
	{
		cin >> prices[i];
	}
	for (int i = 0; i < 12; i++)
	{
		cin >> nums[i];
	}
}

void process()
{
	// 1일짜리로 채워넣기
	for (int i = 0; i < 12; i++)
	{
		nums[i] = nums[i] * prices[0];
	}
	// 한달짜리 비교
	for (int i = 0; i < 12; i++)
	{
		nums[i] = min(nums[i], prices[1]);
	}
	// 세달짜리 비교
	go(0, 0);
	// 1년짜리랑 비교
	ans = min(prices[3], ans);
}

void go(int idx, int sum)
{
	if (idx >= 12)
	{
		if (ans > sum) ans = sum;
		return;
	}
	go(idx + 3, sum + prices[2]);
	go(idx + 1, sum + nums[idx]);
}