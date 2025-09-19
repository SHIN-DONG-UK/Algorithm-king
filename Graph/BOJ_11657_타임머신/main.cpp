#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const int INF = 1e9;

struct Edge {
	int u, v;
	int dist;
};

int N, M;
vector<Edge> edges;
ll best[501];

void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	solve();

	return 0;
}

void input() {
	cin >> N >> M;
	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edges.push_back({ A,B,C });
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		best[i] = 1e9;
	}
	best[1] = 0;

	//V-1의 최단거리 갱신을 수행
	for (int i = 1; i <= N-1; i++) {
		bool flag = false;
		for (auto& e : edges) {
			if (best[e.u] != INF && best[e.v] > best[e.u] + e.dist) {// 현재 정점(u)를 거쳐 (v)로 가는게 더 짧으면 갱신
				best[e.v] = best[e.u] + e.dist;
				flag = true;
			}
		}

		if (!flag) break;//조기종료
	}

	bool isNegativeCycle = false;
	//더 갱신되는지 확인
	for (auto& e : edges) {
		if (best[e.u] != INF && best[e.v] > best[e.u] + e.dist) {
			isNegativeCycle = true;
			break;
		}
	}

	if (isNegativeCycle) {
		cout << "-1\n";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (best[i] == 1e9) {
				cout << "-1\n";
			}
			else {
				cout << best[i] << '\n';
			}
		}
	}
}