#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
	int y;
	int x;
};

int N, M;
int board[100][100];
int visited[100][100];
int visited_melt[100][100];

queue<Point> melted;
vector<int> melt_log;
int cnt;

void input();
void solve();
bool meltCheese();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1) cnt++;
		}
	}

	melt_log.push_back(cnt);
}

void solve() {
	int turn = 0;
	while (meltCheese()) {
		turn++;
	}

	cout << turn << '\n';
	cout << *(melt_log.rbegin() + 1) << '\n';
}

bool meltCheese() {
	memset(visited, 0, sizeof(visited));
	memset(visited_melt, 0, sizeof(visited_melt));

	queue<Point> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	Point cp, np;
	int cnt_melt = 0;

	while (!q.empty()) {
		cp = q.front(); q.pop();
		for (int d = 0; d < 4; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
			if (visited[np.y][np.x] == 1) continue;

			if (board[np.y][np.x] == 0) {
				visited[np.y][np.x] = 1;
				q.push(np);
			}
			else {
				if (visited_melt[np.y][np.x] == 0) {
					visited_melt[np.y][np.x] = 1;
					melted.push(np);

					cnt_melt++;
				}
				
			}
		}
	}

	if (melted.empty()) return false;

	while (!melted.empty()) {
		cp = melted.front(); melted.pop();
		board[cp.y][cp.x] = 0;
	}

	melt_log.push_back(cnt-=cnt_melt);
	return true;
}