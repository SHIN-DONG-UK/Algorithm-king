#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point {
	int y;
	int x;
};

struct Stair {
	int y;
	int x;
	int K;
};

struct State
{
	int eta;
	int cnt;
};

int N;
vector<Point> PERSONS;
vector<Stair> STAIRS;
int a[10];
int ans;

void init();
void input();
void go(int idx);
int simulation();

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		go(0);
		cout << "#" << tc << " " << ans << '\n';
	}
}

void init()
{
	ans = 1e9;
	PERSONS.clear();
	STAIRS.clear();
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int num;
			cin >> num;
			if (num == 1) PERSONS.push_back({ i,j });
			else if (num > 1) STAIRS.push_back({ i,j, num});
		}
	}
}

void go(int idx)
{
	if (idx == PERSONS.size()) {
		int tmp = simulation();


		if (ans > tmp) ans = tmp;
		return;
	}
	a[idx] = 0;
	go(idx + 1);
	a[idx] = 1;
	go(idx + 1);
}

bool cmp(State a, State b) {
	return a.eta > b.eta;
}

int simulation()
{
	vector<State> s1;
	vector<State> s2;
	for (int i = 0; i < PERSONS.size(); i++)
	{
		if (a[i] == 0) {
			int eta = abs(STAIRS[0].y - PERSONS[i].y) + abs(STAIRS[0].x - PERSONS[i].x);
			s1.push_back({ eta, 0 });
		}
		else {
			int eta = abs(STAIRS[1].y - PERSONS[i].y) + abs(STAIRS[1].x - PERSONS[i].x);
			s2.push_back({ eta, 0 });
		}
	}

	sort(s1.begin(), s1.end(), cmp);
	sort(s2.begin(), s2.end(), cmp);

	int time;
	if (s1.size() == 0) time = s2.back().eta;
	else if (s2.size() == 0) time = s1.back().eta;
	else time = min(s1.back().eta, s2.back().eta);

	queue<State> q;
	queue<State> q2;
	while (1)
	{
		while (!s1.empty()) {
			if (time - s1.back().eta >= 1) {
				if (q.size() == 3) break;
				State tmp = s1.back();
				s1.pop_back();
				q.push(tmp);
			}
			else break;
		}

		while (!s2.empty()) {
			if (time - s2.back().eta >= 1) {
				if (q2.size() == 3) break;
				State tmp = s2.back();
				s2.pop_back();
				q2.push(tmp);
			}
			else break;
		}

		// cnt++
		int len = q.size();
		for (int i = 0; i < len; i++)
		{
			State tmp = q.front();
			q.pop();
			tmp.cnt += 1;
			if (tmp.cnt == STAIRS[0].K) continue;
			q.push(tmp);
		}

		len = q2.size();
		for (int i = 0; i < len; i++)
		{
			State tmp = q2.front();
			q2.pop();
			tmp.cnt += 1;
			if (tmp.cnt == STAIRS[1].K) continue;
			q2.push(tmp);
		}

		time++;

		if (s1.empty() && q.empty() && s2.empty() && q2.empty()) break;
	}
	return time;
}