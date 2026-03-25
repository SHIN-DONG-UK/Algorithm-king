#define MAX_N 100000
#define MAX_V 1e9
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Node {
	int cnt;			// 리프 노드 개수
	long long sum;			// 구간 합
	int l, r;			// 해당 노드가 담당하는 범위
	Node* left;			// 왼쪽 자식 포인터
	Node* right;		// 오른쪽 자식 포인터
};

Node memory_pool[3000005];
int unused;

unordered_map<string, int> name2value;
unordered_map<int, string> value2name;

void init();
int insert(string& name, int value);
int remove(string& name);
string mRank(int k);
long long sum(Node* now, int s, int e, int ts, int te);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;
	string cmd;
	while (Q--) {
		cin >> cmd;
		if (cmd == "init") {
			init();
		}
		else if (cmd == "insert") {
			string name;
			int value;
			cin >> name >> value;

			int rst = insert(name, value);
			cout << rst << '\n';
		}
		else if (cmd == "delete") {
			string name;
			cin >> name;

			int rst = remove(name);
			cout << rst << '\n';
		}
		else if (cmd == "rank") {
			int k;
			cin >> k;

			string rst = mRank(k);
			cout << rst << '\n';
		}
		else if (cmd == "sum") {
			int k;
			cin >> k;

			long long rst = sum(&memory_pool[0], 1, MAX_V, 1, k);
			cout << rst << '\n';
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

void init() {
	// root 노드 초기화
	unused = 0;
	Node* node = &memory_pool[unused++];
	node->cnt = 0;
	node->sum = 0;
	node->l = 1;
	node->r = MAX_V;
	node->left = nullptr;  // null
	node->right = nullptr; // null

	name2value.clear();
	value2name.clear();
}

int insert(string& name, int value) {
	if (name2value.count(name) > 0) {
		return 0;
	}

	if (value2name.count(value) > 0) {
		return 0;
	}

	name2value[name] = value;
	value2name[value] = name;

	// Dynamic Segment Tree update Logic - add
	int l = 1;
	int r = 1e9;
	Node* parent = &memory_pool[0];
	parent->cnt++;
	parent->sum += value;
	while (l <= r) {
		// leaf Node 도달
		if (l == value && r == value) {
			break;
		}
		int mid = (l + r) / 2;
		// l ~ mid는 left, mid+1~r은 right
		// left
		if (value <= mid) {
			r = mid;
			if (parent->left == nullptr) {
				Node* newNode = &memory_pool[unused++];
				parent->left = newNode;
				newNode->cnt = 1;
				newNode->sum = value;
				newNode->l = l;
				newNode->r = r;
				newNode->left = nullptr;
				newNode->right = nullptr;

				parent = newNode;
			}
			else {
				Node* tmp = parent->left;
				tmp->cnt++;
				tmp->sum += value;

				parent = tmp;
			}
		}
		// right
		else {
			l = mid + 1;
			if (parent->right == nullptr) {
				Node* newNode = &memory_pool[unused++];
				parent->right = newNode;
				newNode->cnt = 1;
				newNode->sum = value;
				newNode->l = l;
				newNode->r = r;
				newNode->left = nullptr;
				newNode->right = nullptr;

				parent = newNode;
			}
			else {
				Node* tmp = parent->right;
				tmp->cnt++;
				tmp->sum += value;

				parent = tmp;
			}
		}
	}

	return 1;
}

int remove(string& name) {
	if (name2value.count(name) == 0) {
		return 0;
	}

	int value = name2value[name];

	int l = 1;
	int r = 1e9;

	// Dynamic Segment Tree update Logic - remove
	Node* now = &memory_pool[0];
	// leaf node까지 while loop
	while (true) {
		now->cnt--;
		now->sum -= value;
		if (l == r) {
			break;
		}

		int mid = (l + r) / 2;
		if (value <= mid) {
			r = mid;
			now = now->left;
		}
		else {
			l = mid + 1;
			now = now->right;
		}
	}

	name2value.erase(name);
	value2name.erase(value);

	return value;
}

string mRank(int k) {
	if (name2value.size() < k) {
		return "None";
	}

	// seg tree traversal
	Node* now = &memory_pool[0];
	// leaf node까지 while loop
	while (!(now->l == now->r)) {
		// left가 nullptr == (k = 0)
		if (now->left == nullptr) {
			now = now->right;
		}
		else if (now->left->cnt < k) {
			k -= now->left->cnt;
			now = now->right;
		}
		else {
			now = now->left;
		}
	}

	return value2name[now->l];
}

long long sum(Node* now, int s, int e, int ts, int te) {
	if (now == nullptr) {
		return 0;
	}

	// 범위에 아예 벗어난 경우
	if (te < s || e < ts) {
		return 0;
	}

	// 범위에 완벽히 들어오는 경우
	if (ts <= s && e <= te) {
		return now->sum;
	}

	int mid = (s + e) / 2;
	long long left = sum(now->left, s, mid, ts, te);
	long long right = sum(now->right, mid + 1, e, ts, te);

	return left + right;
}
