#define _CRT_SECURE_NO_WARNINGS
#define MAX_N 40000
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

struct Ship {
	int id;
	int power;
	int rTime;
	int lastAttack;
};

struct cmp {
	bool operator()(const Ship& a, const Ship& b)const {
		if (a.power == b.power) {
			return a.id > b.id;
		}
		return a.power < b.power;
	}
};

int N;
// 1-based index
Ship arr[MAX_N + 1];
priority_queue<Ship, vector<Ship>, cmp> max_heap;
vector<Ship> vec;

// id -> index
unordered_map<int, int> hmap;

int now_t;
int ids[5];

void init();
void request(int id, int p, int r);
void replacement(int id, int pw);
void attack();

int main() {
	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	int cmd;
	while (T--) {
		now_t++;
		cin >> cmd;
		if (cmd == 100) {
			init();
		}
		else if (cmd == 200) {
			int id, p, r;
			cin >> id >> p >> r;
			request(id, p, r);
		}
		else if (cmd == 300) {
			int id, pw;
			cin >> id >> pw;
			replacement(id, pw);
		}
		else if (cmd == 400) {
			attack();
		}
		else {
			cout << "Error\n";
		}
	}
	return 0;
}

void init() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].id;
		cin >> arr[i].power;
		cin >> arr[i].rTime;
		arr[i].lastAttack = -10; // 사격 대기 상태

		hmap[arr[i].id] = i;
		max_heap.push(arr[i]);
	}
}

void request(int id, int p, int r) {
	N++;
	arr[N].id = id;
	arr[N].power = p;
	arr[N].rTime = r;
	arr[N].lastAttack = -10;
	max_heap.push(arr[N]);

	hmap[id] = N;
}

void replacement(int id, int pw) {
	int idx = hmap[id];

	if (arr[idx].power != pw) {
		arr[idx].power = pw;

		max_heap.push(arr[idx]);
	}
}

void attack() {
	int cnt = 0;
	int sum = 0;

	while (cnt < 5 && !max_heap.empty()) {
		Ship ship = max_heap.top(); max_heap.pop();

		// dummy 판단 - 공격력이 업데이트된 경우
		int idx = hmap[ship.id];
		if (ship.power != arr[idx].power) continue;

		// 사격 준비 상태인 경우만
		if (now_t - ship.lastAttack >= ship.rTime) {
			int idx = hmap[ship.id];
			arr[idx].lastAttack = now_t;
			ship.lastAttack = now_t;

			sum += ship.power;
			ids[cnt++] = ship.id;
		}
		vec.push_back(ship); // 원복용
	}

	// max heap에 원복
	for (Ship ship : vec) {
		max_heap.push(ship);
	}
	vec.clear();

	cout << sum << ' ';
	cout << cnt << ' ';
	for (int i = 0; i < cnt; i++) {
		cout << ids[i] << ' ';
	}
	cout << '\n';
}