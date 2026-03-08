#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

int N, M;
int cnt_light;

struct Light {
	int id;
	int x;
	bool isRemoved;
};

struct cmp {
	bool operator() (const Light* a, const Light* b) const {
		return a->x < b->x;
	}
};

struct Node {
	Light* left;
	Light* right;
	int dist;

	bool operator<(const Node &other) const {
		if (other.dist == dist) {
			return other.left->x < left->x;
		}
		return dist < other.dist;
	}
};

int arr[100000];
Light pool_light[200001];
priority_queue<Node> PQ;
set<int> ordered_pos; // 위치 순서
unordered_map<int, Light*> hmap; // 위치 -> light

void init(int n, int m, int arr[]);
void add();
void pop(int D);
int get_minumum_power();

bool check(int rr);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q, cmd;

	cin >> Q;
	while (Q--) {
		cin >> cmd;
		if (cmd == 100) {
			int n, m;
			cin >> n >> m;
			for (int i = 0; i < m; i++) {
				cin >> arr[i];
			}

			init(n, m, arr);
		}
		else if (cmd == 200) {
			add();
		}
		else if (cmd == 300) {
			int D;
			cin >> D;
			pop(D);
		}
		else if (cmd == 400) {
			int rr = get_minumum_power();
			cout << rr << '\n';
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

void init(int n, int m, int arr[]) {
	N = n; M = m;
	cnt_light = M;

	for (int i = 1; i <= M; i++) {
		Light* newLight = &pool_light[i];
		newLight->id = i;
		newLight->x = arr[i - 1];
		newLight->isRemoved = false;

		ordered_pos.insert(newLight->x);
		hmap[newLight->x] = newLight;
	}

	for (int i = 1; i <= M - 1; i++) {
		Node newNode;
		newNode.left = &pool_light[i];
		newNode.right = &pool_light[i + 1];
		newNode.dist = abs(pool_light[i].x - pool_light[i + 1].x);

		PQ.push(newNode);
	}
}
void add() {
	Node top;
	while (1) {
		top = PQ.top(); PQ.pop();
		if (!top.left->isRemoved && !top.right->isRemoved) break;
	}

	Light* newLight = &pool_light[++cnt_light];
	newLight->id = cnt_light;
	newLight->x = (top.left->x + top.right->x + 1) / 2;
	newLight->isRemoved = false;
	
	ordered_pos.insert(newLight->x);
	hmap[newLight->x] = newLight;

	Node node1;
	node1.left = top.left;
	node1.right = newLight;
	node1.dist = node1.right->x - node1.left->x;
	PQ.push(node1);

	Node node2;
	node2.left = newLight;
	node2.right = top.right;
	node2.dist = node2.right->x - node2.left->x;
	PQ.push(node2);
}

void pop(int D) {
	pool_light[D].isRemoved = true;
	int x = pool_light[D].x;
	hmap.erase(x);

	auto it = ordered_pos.find(x);

	if (it != ordered_pos.begin() && it != prev(ordered_pos.end())) {
		int left_pos = *prev(it);
		int right_pos = *next(it);

		Node newNode;
		newNode.left = hmap[left_pos];
		newNode.right = hmap[right_pos];
		newNode.dist = newNode.right->x - newNode.left->x;
		PQ.push(newNode);
	}
	ordered_pos.erase(it);
}

int get_minumum_power() {
	int rst = -1;
	int left = 1; int right = N;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (check(mid)) {
			right = mid - 1;
			rst = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return rst;
}

bool check(int rr) {
	Node top;
	while (1) {
		top = PQ.top(); PQ.pop();
		if (!top.left->isRemoved && !top.right->isRemoved) break;
	}
	PQ.push(top);

	// 1. 사이가 가장 먼 애들이 안되면 false
	if (top.right->x - top.left->x > rr) return false;

	// 2. 가장 왼쪽 가로등이 1까지 커버 안되면 false
	int pos;
	Light* light;
	while (1) {
		pos = *ordered_pos.begin();
		light = hmap[pos];
		if (light->isRemoved) {
			ordered_pos.erase(ordered_pos.begin());
		}
		else {
			break;
		}
	}

	if (light->x - 1 > rr/2) return false;

	// 3. 가장 오른쪽 가로등이 N까지 커버 안되면 false
	while (1) {
		pos = *ordered_pos.rbegin();
		light = hmap[pos];
		if (light->isRemoved) {
			ordered_pos.erase(--(ordered_pos.end()));
		}
		else {
			break;
		}
	}
	if (N - light->x > rr/2) return false;

	return true;
}