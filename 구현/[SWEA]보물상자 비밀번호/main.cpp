#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N, K;
string nums;
vector<string> ans_arr;
long long ans;

void init();
void input();
void rotate();
void slice();
void check();
void process();

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
	nums.clear();
	ans_arr.clear();
}

void input()
{
	cin >> N >> K;
	cin >> nums;
}

void process()
{
	for (int i = 0; i < N/4; i++)
	{
		rotate();
		slice();
	}
	check();
}

void check()
{
	sort(ans_arr.begin(), ans_arr.end(), greater<string>());
	long long sixteen = 1;
	long long tmp = 0;
	for (int i = ans_arr[K - 1].size() - 1; i >= 0; i--)
	{
		// 16진수 -> 10진수
		char c = ans_arr[K - 1][i];
		int CtoNum = 0;
		if (c >= '0' && c <= '9') {
			CtoNum = c - '0';
		}
		else {
			CtoNum = c - 'A' + 10;
		}
		tmp += sixteen * CtoNum;
		sixteen *= 16;
	}
	ans = tmp;
}

void slice()
{
	for (int i = 0; i < N; i+=N/4)
	{
		string sub = nums.substr(i, N / 4);
		// 검사하기
		int j;
		for (j = 0; j < ans_arr.size(); j++)
		{
			if (ans_arr[j] == sub)
				break;
		}
		if (j == ans_arr.size()) ans_arr.push_back(sub);
	}
}

void rotate()
{
	int tmp = nums[N - 1];
	for (int i = N-1; i >= 1; i--)
	{
		nums[i] = nums[i - 1];
	}
	nums[0] = tmp;
}