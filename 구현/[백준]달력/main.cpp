#include <iostream>

using namespace std;
int DAT[367];
int first = 1e9;
int last = 0;
int ans;

void input();
void process();

int main()
{
	input();
	process();
	cout << ans << '\n';

}

void input()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > last) last = a;
		if (b > last) last = b;
		if (first > a) first = a;
		if (first > b) first = b;
		for (int j = a; j <= b; j++)
		{
			DAT[j]++;
		}
	}
}

void process()
{
	int start = first;
	int end = 0;
	int height = 0;

	int i = first;
	while (i <= last + 1)
	{
		if (height < DAT[i]) height = DAT[i];
		if (DAT[i] == 0)
		{
			end = i;
			ans += (end - start) * height;
			height = 0;
			while (DAT[i] == 0 && i <= last + 1) i++;
			start = i;
		}
		else i++;
	}
	
}