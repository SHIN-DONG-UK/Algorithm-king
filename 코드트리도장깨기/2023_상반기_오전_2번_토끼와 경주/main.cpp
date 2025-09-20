#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <queue>
#include <stdio.h>
using namespace std;
using u64 = unsigned long long;

const int MX_R = 2000;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Rabbit {
	int id;
	int y, x; //1-based index
	int dist;
	int count;
	u64 score;
};

struct cmp {
	bool operator() (Rabbit*& lhs, Rabbit*& rhs) const {
		if (lhs->count == rhs->count) {
			if (lhs->y + lhs->x == rhs->y + rhs->x) {
				if (lhs->y == rhs->y) {
					if (lhs->x == rhs->x) {
						return lhs->id > rhs->id;
					}
					return lhs->x > rhs->x;
				}
				return lhs->y > rhs->y;
			}
			return lhs->y + lhs->x > rhs->y + rhs->x;
		}
		return lhs->count > rhs->count;
	}
};

Rabbit rabbits[MX_R + 1]; int len;
unordered_map<int, Rabbit*> idMap;
priority_queue<Rabbit*, vector<Rabbit*>, cmp> PQ;

int N, M, P;
Rabbit global_candidate;

void init();
void go_race(int K, int S);
void change_dist(int pid, int L);
void get_best();

void get_next_point(Rabbit*& now, int& dir, int& ny, int& nx);
void upper(Rabbit*& now, int& dir, int& ny, int& nx);
void lower(Rabbit*& now, int& dir, int& ny, int& nx);
void left(Rabbit*& now, int& dir, int& ny, int& nx);
void right(Rabbit*& now, int& dir, int& ny, int& nx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	//freopen("sample_input.txt", "r", stdin);

	int q;
	cin >> q;
	int cmd;
	int par1, par2;
	while (q--) {
		cin >> cmd;
		if (cmd == 100) {
			init();
		}
		else if (cmd == 200) {
			cin >> par1 >> par2;
			go_race(par1, par2);
		}
		else if (cmd == 300) {
			cin >> par1 >> par2;
			change_dist(par1, par2);
		}
		else {
			get_best();
		}
	}


	return 0;
}

void init() {
	cin >> N >> M >> P;

	int pid, d;
	for (int i = 0; i < P; i++) {
		cin >> pid >> d;
		Rabbit* pt = &rabbits[++len];
		pt->id = pid;
		pt->y = 1; pt->x = 1;
		pt->dist = d;
		pt->count = 0;
		pt->score = 0;
		//unordered_map에 저장
		idMap[pid] = pt;
		//PQ에 삽입
		PQ.push(pt);
	}
}

void go_race(int K, int S) {
	Rabbit* candidate = &global_candidate;
	candidate->id = 0;
	candidate->y = 0;
	candidate->x = 0;

	Rabbit* now;
	int ny, nx;
	int priorY, priorX;

	while (K--) {
		now = PQ.top(); PQ.pop();
		priorY = 0; priorX = 0;
		for (int d = 0; d < 4; d++) {
			get_next_point(now, d, ny, nx);

			//priorY, priorX update
			if (priorY + priorX == ny + nx) {
				if (priorY == ny) {
					if (priorX < nx) { priorY = ny; priorX = nx; }
				}
				else if (priorY < ny) { priorY = ny; priorX = nx; }
			}
			else if (priorY + priorX < ny + nx) { priorY = ny; priorX = nx; }
		}

		//rabbit* update
		now->y = priorY; now->x = priorX;

		//나머지 rabbit score updtae
		for (int i = 1; i <= len; i++) {
			if (rabbits[i].id == now->id) continue;
			rabbits[i].score += (now->y + now->x);
		}

		//candidate update
		if (candidate->y + candidate->x == now->y + now->x) {
			if (candidate->y == now->y) {
				if (candidate->x == now->x) {
					if (candidate->id < now->id) { candidate = now; }
				}
				else if (candidate->x < now->x) { candidate = now; }
			}
			else if (candidate->y < now->y) { candidate = now; }
		}
		else if (candidate->y + candidate->x < now->y + now->x) { candidate = now; }
		
		now->count++;

		PQ.push(now);
	}

	//candidate에 score + S
	candidate->score += S;
}

void change_dist(int pid, int L) {
	Rabbit* pt = idMap[pid];
	pt->dist *= L;
}

void get_best() {
	u64 maxi = 0;
	for (int i = 1; i <= len; i++) {
		if (maxi < rabbits[i].score) maxi = rabbits[i].score;
	}

	cout << maxi << '\n';
}

void get_next_point(Rabbit*& now, int& dir, int& ny, int& nx) {
	ny = now->y; nx = now->x;

	if (dir == 1 && now->y == N)
		upper(now, dir, ny, nx);
	else if (dir == 0 && now->y == 1)
		lower(now, dir, ny, nx);
	else if (dir == 3 && now->x == M)
		left(now, dir, ny, nx);
	else if (dir == 2 && now->x == 1)
		right(now, dir, ny, nx);
	else if (dir == 0)
		upper(now, dir, ny, nx);
	else if (dir == 1)
		lower(now, dir, ny, nx);
	else if (dir == 2)
		left(now, dir, ny, nx);
	else
		right(now, dir, ny, nx);
}

void upper(Rabbit*& now, int& dir, int& ny, int& nx) {
	//상
	int rem = now->dist % (2 * (N - 1));
	if (rem > now->y - 1) {
		rem -= (now->y - 1);
		if (rem > N - 1) {
			rem -= (N - 1);
			ny = N - rem;
		}
		else { ny = rem + 1; }
	}
	else { ny = now->y - rem; }
}

void lower(Rabbit*& now, int& dir, int& ny, int& nx) {
	//하
	int rem = now->dist % (2 * (N - 1));
	if (rem > N - now->y) {
		rem -= (N - now->y);
		if (rem > N - 1) {
			rem -= (N - 1);
			ny = rem + 1;
		}
		else { ny = N - rem; }
	}
	else { ny = now->y + rem; }
}

void left(Rabbit*& now, int& dir, int& ny, int& nx) {
	//좌
	int rem = now->dist % (2 * (M - 1));
	if (rem > now->x - 1) {
		rem -= (now->x - 1);
		if (rem > M - 1) {
			rem -= (M - 1);
			nx = M - rem;
		}
		else { nx = rem + 1; }
	}
	else { nx = now->x - rem; }
}

void right(Rabbit*& now, int& dir, int& ny, int& nx) {
	//우
	int rem = now->dist % (2 * (M - 1));
	if (rem > M - now->x) {
		rem -= (M - now->x);
		if (rem > M - 1) {
			rem -= (M - 1);
			nx = rem + 1;
		}
		else { nx = M - rem; }
	}
	else { nx = now->x + rem; }
}