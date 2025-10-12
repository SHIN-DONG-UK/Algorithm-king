#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> adjList[50001];
int visited[50001];

void init();
int solve();
void output(int& longest);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	
	int longest = solve();

	output(longest);

	return 0;
}

void init() {
	cin >> N >> M;

	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		//bidirectional
		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}
}

int solve() {
	queue<int> Q;
	Q.push(1);
	visited[1] = 1;

	int now;
	int longest = 0;
	while (!Q.empty()) {
		now = Q.front(); Q.pop();
		for (auto& next : adjList[now]) {
			if (visited[next] > 0) continue;
			visited[next] = visited[now] + 1;
			Q.push(next);

			if (visited[next] > longest) longest = visited[next];
		}
	}

	return longest;
}

void output(int& longest) {
	int cnt = 0;
	bool flag = false;
	int num = -1;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == longest) {
			cnt++;
			if (!flag) {
				num = i;
				flag = true;
			}
		}
	}

	cout << num << ' ' << longest - 1 << ' ' << cnt << '\n';
}