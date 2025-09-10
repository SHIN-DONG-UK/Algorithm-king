#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MX = 10005;

struct Node {
	int dist;
	int num1;
	int num2;
};

int V, E;
vector<Node> edges;

int p[MX];
int find(int x);
bool uni(int u, int v);

void init();
bool compare(Node& a, Node& b);
int solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	int ans = solve();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> V >> E;

	int dist, num1, num2;
	for (int i = 0; i < E; i++) {
		cin >> num1 >> num2 >> dist;
		edges.push_back({ dist, num1, num2 });
	}

	sort(edges.begin(), edges.end(), compare);
	
	memset(p, -1, sizeof(int) * (V + 1));
}

bool compare(Node& a, Node& b) {
	return a.dist < b.dist;
}

int find(int x) {
	if (p[x] < 0) {
		return x;
	}
	return p[x] = find(p[x]);
}

bool uni(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return false;

	if (p[u] > p[v]) 
		swap(u, v);

	if (p[u] == p[v])
		p[u]--;

	p[v] = u;
	return true;
}

int solve() {
	int rst = 0;
	for (auto& edge : edges) {
		if (uni(edge.num1, edge.num2))
			rst += edge.dist;
	}

	return rst;
}