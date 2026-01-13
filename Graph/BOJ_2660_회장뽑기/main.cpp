#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


int N;
vector<int> adjList[51];
int dist[51];
int visited[51];
int min_val;

vector<int> ans_arr;

void init();
void solve();
void output();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();
	output();

	return 0;
}

void init() {
	min_val = 1e9;

	cin >> N;
	int from, to;
	while (1) {
		cin >> from >> to;
		if (from == -1 && to == -1) {
			return;
		}

		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}
	
}

void solve() {
	for (int i = 1; i <= N; i++) {
		memset(visited, 0, sizeof(visited));

		queue<int> Q;
		
		visited[i] = 1;
		Q.push(i);

		int l_max = 1;

		int now;
		while (!Q.empty()) {
			now = Q.front(); Q.pop();
			for (auto& nxt : adjList[now]) {
				if (visited[nxt]) continue;
				visited[nxt] = visited[now] + 1;
				Q.push(nxt);

				if (l_max < visited[nxt]) {
					l_max = visited[nxt];
				}
			}
		}

		dist[i] = l_max - 1;
		if (min_val > dist[i]) {
			min_val = dist[i];
		}
	}

}

void output() {
	for (int i = 1; i <= N; i++) {
		if (min_val == dist[i]) {
			ans_arr.push_back(i);
		}
	}

	cout << min_val << ' ' << ans_arr.size() << '\n';
	for (auto& a : ans_arr) {
		cout << a << ' ';
	}
	cout << '\n';
}