#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

const int MX = 100'000;


struct Box {
	int num;
	Box* prev;
	Box* next;
};

Box pool[MX + 1];
Box* Head[MX + 1];
Box* Tail[MX + 1];
int bboxCnt[MX + 1];
vector<int> tmpArr[MX + 1];

int n, m;

void init();
void all_move(int&, int&);
void front_swap(int&, int&);
void mod_box(int&, int&);
void get_info_box(int&);
void get_info_belt(int&);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("sample_input.txt", "r", stdin);

	int q;
	cin >> q;

	int com;
	while (q--) {
		cin >> com;
		
		int num1, num2;
		if (com == 100) {
			init();
		}
		else if (com == 200) {
			cin >> num1 >> num2;
			all_move(num1, num2);
		}
		else if (com == 300) {
			cin >> num1 >> num2;
			front_swap(num1, num2);
		}
		else if (com == 400) {
			cin >> num1 >> num2;
			mod_box(num1, num2);
		}
		else if (com == 500) {
			cin >> num1;
			get_info_box(num1);
		}
		else {
			cin >> num1;
			get_info_belt(num1);
		}
	}
	return 0;
}

void init() {
	cin >> n >> m;

	int bnum;
	for (int i = 1; i <= m; i++) {
		cin >> bnum;
		tmpArr[bnum].push_back(i);
		pool[i].num = i;
		pool[i].prev = nullptr;
		pool[i].next = nullptr;
	}

	for (int i = 1; i <= m; i++) {
		if (tmpArr[i].empty()) continue;
		
		for (int j = 0; j < tmpArr[i].size() - 1; j++) {
			int& now = tmpArr[i][j];
			int& nxt = tmpArr[i][j + 1];
			pool[now].next = &pool[nxt];
		}
		for (int j = tmpArr[i].size() - 1; j > 0; j--) {
			int& now = tmpArr[i][j];
			int& prv = tmpArr[i][j - 1];
			pool[now].prev = &pool[prv];
		}

		if (tmpArr[i].size() == 1) {
			Head[i] = Tail[i] = &pool[tmpArr[i][0]];
		}
		else {
			Head[i] = &pool[tmpArr[i][0]];
			Tail[i] = &pool[tmpArr[i].back()];
		}

		bboxCnt[i] = tmpArr[i].size();
	}


}

void all_move(int& m_src, int& m_dst) {
	if (m_src == 5030) { 
		cout << "hi\n";
	};

	if (bboxCnt[m_src] > 0) {
		//swap
		//케이스 쪼개줘야 함
		//m_dst가 비어있는 경우 vs 아닌 경우
		if (bboxCnt[m_dst] == 0) {
			Head[m_dst] = Head[m_src];
			Tail[m_dst] = Tail[m_src];
			bboxCnt[m_dst] += bboxCnt[m_src];
			bboxCnt[m_src] = 0;
			Head[m_src] = Tail[m_src] = nullptr;
		}
		else {
			Head[m_dst]->prev = Tail[m_src];
			Tail[m_src]->next = Head[m_dst];
			Head[m_dst] = Head[m_src];
			bboxCnt[m_dst] += bboxCnt[m_src];
			bboxCnt[m_src] = 0;
			Head[m_src] = Tail[m_src] = nullptr;
		}
		
	}
	cout << bboxCnt[m_dst] << '\n';
}

void front_swap(int& m_src, int& m_dst) {
	if (m_src == 5030) { 
		cout << "hi\n"; 
	};

	if (bboxCnt[m_src] == 0 && bboxCnt[m_dst] == 0) {
		//아무것도 안함
	}
	else if (bboxCnt[m_src] == 0) {
		if (bboxCnt[m_dst] == 1) {
			Head[m_src] = Tail[m_src] = Head[m_dst];
			Head[m_dst] = Tail[m_dst] = nullptr;
			bboxCnt[m_src] = bboxCnt[m_dst];
			bboxCnt[m_dst] = 0;
		}
		else {
			Box* pt = Head[m_dst];
			Head[m_dst] = Head[m_dst]->next;
			Head[m_dst]->prev = nullptr;
			bboxCnt[m_dst]--;
			Head[m_src] = Tail[m_src] = pt;
			pt->prev = pt->next = nullptr;
			bboxCnt[m_src]++;
		}
		
	}
	else if (bboxCnt[m_dst] == 0) {
		if (bboxCnt[m_src] == 1) {
			Head[m_dst] = Tail[m_dst] = Head[m_src];
			Head[m_src] = Tail[m_src] = nullptr;
			bboxCnt[m_dst] = bboxCnt[m_src];
			bboxCnt[m_src] = 0;
		}
		else {
			Box* pt = Head[m_src];
			Head[m_src] = Head[m_src]->next;
			Head[m_src]->prev = nullptr;
			bboxCnt[m_src]--;
			Head[m_dst] = Tail[m_dst] = pt;
			pt->prev = pt->next = nullptr;
			bboxCnt[m_dst]++;
		}
		
	}
	else {
		//둘 다 1인경우
		if (bboxCnt[m_src] == 1 && bboxCnt[m_dst] == 1) {
			Box* pt = Head[m_src];
			Head[m_src] = Tail[m_src] = Head[m_dst];
			Head[m_dst] = Tail[m_dst] = pt;
		}
		//둘 중 하나가 1인 경우
		else if (bboxCnt[m_src] == 1) {
			Box* pt = Head[m_dst];
			Head[m_src]->next = Head[m_dst]->next;
			Head[m_dst]->next->prev = Head[m_src];
			Head[m_dst] = Head[m_src];

			Head[m_src] = Tail[m_src] = pt;
			Head[m_src]->next = Head[m_src]->prev = nullptr;
		}
		else if (bboxCnt[m_dst] == 1) {
			Box* pt = Head[m_src];
			Head[m_dst]->next = Head[m_src]->next;
			Head[m_src]->next->prev = Head[m_dst];
			Head[m_src] = Head[m_dst];

			Head[m_dst] = Tail[m_dst] = pt;
			Head[m_dst]->next = Head[m_dst]->prev = nullptr;
		}
		//둘 다 1이 아닌 경우
		else {
			Head[m_src]->next->prev = Head[m_dst];
			Head[m_dst]->next = Head[m_src]->next;
			Head[m_dst]->next->prev = Head[m_src];
			Head[m_src]->next = Head[m_dst]->next;
			//swap
			Box* pt = Head[m_src];
			Head[m_src] = Head[m_dst];
			Head[m_dst] = pt;
		}
	}
	cout << bboxCnt[m_dst] << '\n';
}

void mod_box(int& m_src, int& m_dst) {
	if (m_src == 5030) { 
		cout << "hi\n";
	};

	if (bboxCnt[m_src] > 1) {
		int tmp = bboxCnt[m_src] / 2;
		//find tail(tail은 옮겨야하는 마지막 박스 다음임)
		Box* tail = Head[m_src];
		int k = tmp;
		while (--k) { tail = tail->next; }
		Box* head = Head[m_src];
		//liking update
		//케이스 쪼개줘야 함
		//dst가 비어있는 경우 vs 아닌경우
		tail->next->prev = nullptr;
		Head[m_src] = tail->next;
		if (bboxCnt[m_dst] == 0) {
			tail->next = nullptr;
			Head[m_dst] = head;
			Tail[m_dst] = tail;
		}
		else {
			tail->next = Head[m_dst];
			Head[m_dst]->prev = tail;
			Head[m_dst] = head;
		}
		//count update
		bboxCnt[m_src] -= tmp;
		bboxCnt[m_dst] += tmp;
	}

	cout << bboxCnt[m_dst] << '\n';
}

void get_info_box(int& p_num) {
	Box* pt = &pool[p_num];
	int a = pt->prev == nullptr ? -1 : pt->prev->num;
	int b = pt->next == nullptr ? -1 : pt->next->num;

	cout << a + 2 * b << '\n';
}

void get_info_belt(int& b_num) {
	if (bboxCnt[b_num] == 0) cout << "-3\n";
	else {
		int a = Head[b_num]->num;
		int b = Tail[b_num]->num;
		int c = bboxCnt[b_num];
		cout << a + 2 * b + 3 * c << '\n';
	}
}