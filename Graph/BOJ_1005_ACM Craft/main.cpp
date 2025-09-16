#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MX = 1000;

int T;
int N, K;
int W;

int D[MX + 1];
int sum[MX + 1];
vector<int> adjList[MX + 1];
int indegree[MX + 1];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();

		cout << sum[W] << '\n';
	}
	return 0;
}

void init() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> D[i];
		sum[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		adjList[i].clear();
		indegree[i] = 0;
	}

	int from, to;
	for (int i = 0; i < K; i++) {
		cin >> from >> to;
		adjList[from].push_back(to);
		indegree[to]++;
	}
	cin >> W;
}

void solve() {
	queue<int> Q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
			sum[i] = D[i];
		}
	}

	int now;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();

		for (auto& next : adjList[now]) {
			indegree[next]--;
			sum[next] = max(sum[next], D[next] + sum[now]);

			if (indegree[next] == 0) {
				Q.push(next);
				if (next == W) return;
			}
		}
	}
}