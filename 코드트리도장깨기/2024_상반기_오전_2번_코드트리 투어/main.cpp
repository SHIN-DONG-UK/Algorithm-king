#define MAX_N 2000
#define MAX_ID 30000
#define INF 1e9
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
	int n;
	int dist;
};

struct Item {
	int n;
	int dist;

	bool operator < (const Item& other) const {
		return other.dist < dist;
	}
};

struct Product {
	int revenue;
	int dest;
	bool alive;
};

struct SortedNode {
	int profit;
	int id;

	bool operator < (const SortedNode& other) const {
		if (other.profit == profit) {
			return other.id < id;
		}
		return other.profit > profit;
	}
};

int N, M;

vector<Edge> adjList[MAX_N];
int best[MAX_N];
priority_queue<SortedNode> sorted_list;
Product product_list[MAX_ID + 1];

void init();
void add_product(int id, int revenue, int dest);
void remove_product(int id);
int get_best();
void modify(int s);

void dijkstra(int start);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;
	while (Q--) {
		int cmd;
		cin >> cmd;

		if (cmd == 100) {
			init();
		}
		else if (cmd == 200) {
			int id, revenue, dst;
			cin >> id >> revenue >> dst;
			add_product(id, revenue, dst);
		}
		else if (cmd == 300) {
			int id;
			cin >> id;
			remove_product(id);
		}
		else if (cmd == 400) {
			int rst = get_best();
			cout << rst << '\n';
		}
		else if (cmd == 500) {
			int s;
			cin >> s;
			modify(s);
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

void init() {
	cin >> N >> M;
	int v, u, w;
	for (int i = 0; i < M; i++) {
		cin >> v >> u >> w;
		adjList[v].push_back({ u, w });
		adjList[u].push_back({ v, w });
	}
	dijkstra(0);
}

void add_product(int id, int revenue, int dest) {
	product_list[id].revenue = revenue;
	product_list[id].dest = dest;
	product_list[id].alive = true;

	int profit = revenue - best[dest];
	sorted_list.push({ profit, id });
}

void remove_product(int id) {
	product_list[id].alive = false;
}

int get_best() {
	while (!sorted_list.empty()) {
		SortedNode top = sorted_list.top(); sorted_list.pop();

		if (!product_list[top.id].alive) {
			continue;
		}
		if (top.profit == INF) {
			continue;
		}
		if (top.profit < 0) {
			return -1;
		}

		product_list[top.id].alive = false;
		return top.id;
	}
	return -1;
}

void modify(int s) {
	// 1. sorted list 초기화
	while (!sorted_list.empty()) {
		sorted_list.pop();
	}
	// 2. best 배열 초기화
	dijkstra(s);
	// 3. sorted list 새로 생성
	for (int id = 1; id <= MAX_ID; id++) {
		if (!product_list[id].alive) {
			continue;
		}

		Product pd = product_list[id];
		int profit = pd.revenue - best[pd.dest];
		sorted_list.push({ profit, id });
	}
}

void dijkstra(int start) {
	// 1. best init
	for (int i = 0; i < N; i++) {
		best[i] = INF;
	}

	priority_queue<Item> PQ;
	best[start] = 0;
	PQ.push({ start, 0 });

	while (!PQ.empty()) {
		Item top = PQ.top(); PQ.pop();

		// dummy 무시
		if (best[top.n] < top.dist) continue;

		for (Edge e : adjList[top.n]) {
			int nDist = top.dist + e.dist;

			if (nDist < best[e.n]) {
				best[e.n] = nDist;
				PQ.push({ e.n, nDist });
			}
		}
	}
}