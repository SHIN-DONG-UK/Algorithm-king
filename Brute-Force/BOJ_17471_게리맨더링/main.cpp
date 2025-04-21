#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_N 10
using namespace std;

int N;
vector<int> graph[MAX_N];
int team[MAX_N];
int cost[MAX_N];
int visited[MAX_N];
int ans = 1e9;

void Init();
void Input();
void Go(int idx);
int Check(int start, int g);

int main() {
	Input();

	Go(0);

	if (ans != 1e9)
		cout << ans << '\n';
	else
		cout << "-1\n";
	return 0;
}

void Init() {
	memset(visited, 0, sizeof(visited));
	ans = 1e9;
	for (int i = 0; i < MAX_N; i++)
		graph[i].clear();
}

void Input() {
	cin >> N;
	
	for (int i = 0; i < N; i++)
		cin >> cost[i];

	for (int i = 0; i < N; i++)
	{
		int len;
		cin >> len;
		for (int j = 0; j < len; j++)
		{
			int tmp;
			cin >> tmp;
			graph[i].push_back(tmp-1);
		}
	}
	
	


}

void Go(int idx) {
	if (idx == N) {
		// team 배열에 A 지역구와 B 지역구가 표시되어 있음
		// A 지역구 : 0
		// B 지역구 : 1
		int startA, flagA = 0;
		for (startA = 0; startA < N; startA++) {
			if (team[startA] == 0) {
				flagA = 1;
				break;
			}
		}
		// A 지역구가 없는 경우
		if (!flagA)
			return;

		int startB, flagB = 0;
		for (startB = 0; startB < N; startB++) {
			if (team[startB] == 1) {
				flagB = 1;
				break;
			}
		}
		// B 지역구가 없는 경우
		if (!flagB)
			return;

		int A = Check(startA, 0);
		if (A == -1)
			return;
		int B = Check(startB, 1);
		if (B == -1)
			return;

		int tmp = abs(A - B);
		if (ans > tmp)
			ans = tmp;

		return;
	}

	team[idx] = 1;
	Go(idx + 1);
	team[idx] = 0;
	Go(idx + 1);
}

int Check(int start, int g) {
	int rst = 0;
	memset(visited, 0, sizeof(visited));

	queue<int> q;
	q.push(start);
	visited[start] = 1;

	int cur, next;
	while (!q.empty()) {
		cur = q.front(); q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			next = graph[cur][i];

			if (visited[next] == 1)
				continue;

			if (team[next] == g) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}

	// 모두 연결되었는지 검사
	for (int i = 0; i < N; i++)
	{
		if (team[i] == g) {
			if (visited[i] == 0)
				return -1;
			else
				rst += cost[i];
		}
	}
	return rst;
}