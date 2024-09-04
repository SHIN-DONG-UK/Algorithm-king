#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N;
string func;
string nums;
bool isRight = true;
deque<string> q;

void init();
void input();
int process();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		init();
		input();
		int tmp = process();
		if (tmp == -1) cout << "error\n";
		else
		{
			if (isRight)
			{
				cout << '[';
				if (q.size() > 0)
				{
					for (int i = 0; i < q.size() - 1; i++)
					{
						cout << q[i] << ',';
					}
					cout << q[q.size() - 1];
				}
				cout << ']' << '\n';
			}
			else
			{
				cout << '[';
				if (q.size() > 0)
				{
					for (int i = q.size() - 1; i >= 1; i--)
					{
						cout << q[i] << ',';
					}
					cout << q[0];
				}
				cout << ']' << '\n';
			}
		}
	}
	return 0;
}

void init()
{
	q.clear();
	isRight = true;

}

void input()
{
	cin >> func;
	cin >> N;
	cin >> nums;

	int st = 1;
	int en = 0;
	while (1)
	{
		en = nums.find(',', st);
		if (en == -1) break;
		q.push_back(nums.substr(st, en - st));
		st = en + 1;
	}
	// 마지막 요소를 고려하기 위함
	en = nums.find(']', st);
	if (nums.substr(st, en - st) != "")
		q.push_back(nums.substr(st, en - st));

}

int process()
{
	for (int i = 0; i < func.length(); i++)
	{
		if (func[i] == 'R') isRight = !isRight;
		else
		{
			if (q.empty()) return -1;
			if (isRight) q.pop_front();
			else q.pop_back();
		}
	}
	return 1;
}