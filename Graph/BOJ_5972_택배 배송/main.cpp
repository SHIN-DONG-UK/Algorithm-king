#define MAX_N 50000
#define INF 1e9

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
	int to, dist;
};

struct Item {
	int n, dist;

	bool operator<(const Item& other) const {
		return this->dist > other.dist;
	}
};

int N, M;
vector<Edge> adjList[MAX_N + 1];
int best[MAX_N + 1];

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	solve();

	cout << best[N] << '\n';

	return 0;
}


void init() {
	cin >> N >> M;
	
	int from, to, dist;
	for (int i = 0; i < M; i++) {
		cin >> from >> to >> dist;
		adjList[from].push_back({ to, dist });
		adjList[to].push_back({ from, dist });
	}

	for (int i = 1; i <= N; i++) {
		best[i] = INF;
	}
	best[1] = 0;
}

void solve() {
	priority_queue<Item> PQ;
	for (auto& e : adjList[1]) {
		PQ.push({ e.to, e.dist });
		best[e.to] = e.dist;
	}

	while (!PQ.empty()) {
		Item item = PQ.top(); PQ.pop();

		// dummy 컷
		if (best[item.n] < item.dist) continue;

		for (auto& e : adjList[item.n]) {
			int ndist = item.dist + e.dist;
			if (best[e.to] > ndist) {
				best[e.to] = ndist;

				PQ.push({ e.to, ndist });
			}
		}
	}
}