#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
	int y;
	int x;
	bool flag;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char MAP[1001][1001];
int visited[1001][1001];
int visited_broken[1001][1001];

void input();
void bfs();
void output();

int main() {
	input();
	bfs();
	//output();

	if (visited[N - 1][M - 1] == 0 && visited_broken[N - 1][M - 1] == 0) cout << -1 << '\n';
	else if (visited[N - 1][M - 1] == 0) cout << visited_broken[N - 1][M - 1] << '\n';
	else if (visited_broken[N - 1][M - 1] == 0) cout << visited[N - 1][M - 1] << '\n';
	else cout << min(visited[N - 1][M - 1], visited_broken[N - 1][M - 1]) << '\n';
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> MAP[i];
	}
}

void bfs() {
	queue<Node> q;
	q.push({0, 0, 0});
	visited[0][0] = 1;
	visited_broken[0][0] = 1;

	Node cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			next = { cur.y + dy[d], cur.x + dx[d], cur.flag };
			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
			if (MAP[next.y][next.x] == '1') {
				if (cur.flag == true) continue;
				else {
					if (visited_broken[next.y][next.x] > 0) continue;
					next.flag = true;
					visited_broken[next.y][next.x] = visited[cur.y][cur.x] + 1; // flag = false : visited에 기록되어 있음
					q.push(next);
				}
			}
			else {
				if (cur.flag == true) {
					if (visited_broken[next.y][next.x] > 0) continue;
					visited_broken[next.y][next.x] = visited_broken[cur.y][cur.x] + 1;
					q.push(next);
				}
				else {
					// visited에 기록해야 함
					if (visited[next.y][next.x] > 0) continue;
					visited[next.y][next.x] = visited[cur.y][cur.x] + 1;
					q.push(next);
				}
			}
		}
	}
}

void output() {
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';

	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << visited_broken[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}