#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <stdio.h>
using namespace std;

struct Box {
	int ID;
	int W;
	Box* prev;
	Box* next;
	int belt;
	bool is_removed;
};

Box pool[100000];
unordered_map<int, Box*> idMap;
Box* Head[11];
Box* Tail[11];
bool is_broken[11];

int n, m;


void init();
void unloading(int);
void remove(int);
void check(int);
void breakdown(int);

void modify_bnum(int, int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("sample_input.txt", "r", stdin);

	int q;
	int func, val;
	cin >> q;
	while (q--) {
		cin >> func;
		if (func == 100) {
			init();
		}
		else if (func == 200) {
			cin >> val;
			unloading(val);
		}
		else if (func == 300) {
			cin >> val;
			remove(val);
		}
		else if (func == 400) {
			cin >> val;
			check(val);
		}
		else {
			cin >> val;
			breakdown(val);
		}
	}

	return 0;
}

void init() {
	cin >> n >> m;

	int bnum = 1;
	int id, w;
	for (int i = 0; i < n; i++) {
		cin >> id;
		pool[i].ID = id;
		idMap[id] = &pool[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> w;
		pool[i].W = w;
	}

	for (int i = 0; i < m; i++) {
		Head[i + 1] = &pool[i * n / m];
		Tail[i + 1] = &pool[(i + 1) * (n / m) - 1];

		for (int j = 0; j < n/m; j++) {
			int idx = i * n / m + j;
			Box* pt = &pool[idx];
			pt->prev = idx == i * (n / m) ? nullptr : &pool[idx - 1];
			pt->next = idx == (i + 1) * (n / m) - 1 ? nullptr : &pool[idx + 1];
			pt->belt = i + 1;
			pt->is_removed = false;
		}
	}
}

void unloading(int w_max) {
	long long rst = 0;
	for (int i = 1; i <= m; i++) {
		if (is_broken[i]) continue;
		if (Head[i]->W <= w_max) {
			Box* pt = Head[i];
			if (pt->next != nullptr) {
				Head[i] = pt->next;
				Head[i]->prev = nullptr;
			}

			pt->next = nullptr;
			pt->is_removed = true;

			//rst update
			rst += pt->W;
		}
		else {
			Box* pt = Head[i];
			if (pt->next != nullptr) {
				Head[i] = pt->next;
				Head[i]->prev = nullptr;
			}
			Tail[i]->next = pt;
			pt->prev = Tail[i];
			pt->next = nullptr;
			Tail[i] = pt;
			
		}
	}
	cout << rst << '\n';
	return;
}
void remove(int r_id) {
	if (idMap.count(r_id) == 0) {
		cout << "-1\n";
		return;
	}
	Box* pt = idMap[r_id];
	if (pt->is_removed) {
		cout << "-1\n";
		return;
	}

	pt->is_removed = true;
	//1. pt가 Head인 경우
	if (Head[pt->belt]->ID == pt->ID) {
		//사이즈가 1보다 큰 경우
		if (pt->next != nullptr) {
			Head[pt->belt] = pt->next;
			Head[pt->belt]->prev = nullptr;
		}
		pt->next = nullptr;
		pt->is_removed = true;
	}
	//2. pt가 Tail인 경우
	else if (Tail[pt->belt]->ID == pt->ID) {
		//사이즈가 1보다 큰 경우
		if (pt->prev != nullptr) {
			Tail[pt->belt] = pt->prev;
			Tail[pt->belt]->next = nullptr;
		}
		pt->prev = nullptr;
		pt->is_removed = true;
	}
	//3. 그 외
	else {
		pt->prev->next = pt->next;
		pt->next->prev = pt->prev;
		pt->next = pt->prev = nullptr;
		pt->is_removed = true;
	}

	cout << r_id << '\n';
	return;
}

void check(int f_id) {
	if (idMap.count(f_id) == 0) {
		cout << "-1\n";
		return;
	}

	Box* pt = idMap[f_id];
	if (pt->is_removed) {
		cout << "-1\n";
		return;
	}
	//1. pt가 Head인 경우
	if (Head[pt->belt]->ID == pt->ID) {
		// -> 아무것도 하지 않음
	}
	//2. pt가 Tail인 경우
	else if (Tail[pt->belt]->ID == pt->ID) {
		//사이즈가 1보다 큰 경우(1이면 아무것도 하지 않음)
		if (pt->prev != nullptr) {
			Tail[pt->belt] = pt->prev;
			Tail[pt->belt]->next = nullptr;

			Head[pt->belt]->prev = pt;
			pt->next = Head[pt->belt];
			pt->prev = nullptr;
			Head[pt->belt] = pt;
		}
	}
	//3. 그 외
	else {
		Head[pt->belt]->prev = Tail[pt->belt];
		Tail[pt->belt]->next = Head[pt->belt];

		Tail[pt->belt] = pt->prev;
		Tail[pt->belt]->next = nullptr;

		Head[pt->belt] = pt;
		pt->prev = nullptr;
	}

	cout << pt->belt << '\n';
}

void breakdown(int b_num) {
	if (is_broken[b_num]) {
		cout << "-1\n";
		return;
	}

	is_broken[b_num] = true;

	bool flag = false;
	for (int i = b_num + 1; i <= m; i++) {
		if (!is_broken[i]) {
			flag = true;
			modify_bnum(b_num, i);
			Head[b_num]->prev = Tail[i];
			Tail[i]->next = Head[b_num];
			Tail[i] = Tail[b_num];
			break;
		}
	}

	if (!flag) {
		for (int i = 1; i < b_num; i++) {
			if (!is_broken[i]) {
				modify_bnum(b_num, i);
				Head[b_num]->prev = Tail[i];
				Tail[i]->next = Head[b_num];
				Tail[i] = Tail[b_num];
				break;
			}
		}
	}
	cout << b_num << '\n';
	return;
}

void modify_bnum(int belt, int dst) {
	Box* now = Head[belt];

	while (now != nullptr) {
		now->belt = dst;
		now = now->next;
	}
}