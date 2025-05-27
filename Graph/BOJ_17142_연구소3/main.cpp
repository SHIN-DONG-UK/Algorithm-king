#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
	int y;
	int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };


int N, M;
int map[50][50];
int path[10];
vector<Point> viruses;
vector<vector<int>> all_cases;
int ans = 1e9;

void input();
void simulation();
void get_combi(int idx, int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	
	get_combi(0, 0);

	simulation();

	if (ans == 1e9) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				viruses.push_back({ i, j });
		}
	}
}

void get_combi(int idx, int start) {
	if (idx >= M) {
		vector<int> tmp;
		for (int i = 0; i < M; i++) {
			tmp.push_back(path[i]);
		}
		all_cases.push_back(tmp);
		return;
	}

	for (int i = start; i < viruses.size(); i++) {
		path[idx] = i;
		get_combi(idx + 1, i + 1);
	}
}

void simulation() {
	for (int i = 0; i < all_cases.size(); i++) {

		queue<Point> q;
		int visited[50][50] = { 0, };

		for (int& idx : all_cases[i]) {
			q.push(viruses[idx]);
			visited[viruses[idx].y][viruses[idx].x] = 1;
		}

		Point cp, np;
		while (!q.empty()) {
			cp = q.front(); q.pop();
			for (int d = 0; d < 4; d++) {
				np = { cp.y + dy[d], cp.x + dx[d] };
				if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) continue;
				if (visited[np.y][np.x] > 0) continue;
				if (map[np.y][np.x] == 1) continue;

				visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
				q.push(np);
			}
		}

		// 최솟값 갱신
		int tmp_val = 1;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (flag) break;
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0) {
					if (visited[i][j] == 0) {
						flag = true;
						tmp_val = 1e9 + 1;
						break;
					}
					else tmp_val = max(tmp_val, visited[i][j]);
				}
			}
		}

		if (ans > tmp_val - 1)
			ans = tmp_val - 1;
	}
}