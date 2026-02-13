#include <iostream>
#include <algorithm>
using namespace std;

struct Pool {
	int s, e;
};

int N, L;
Pool water_pool[10000];
int ans_cnt;

void init();
void solve();
bool compare(Pool& a, Pool& b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans_cnt << '\n';
	return 0;
}

bool compare(Pool& a, Pool& b) {
	return a.s < b.s;
}

void init() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> water_pool[i].s >> water_pool[i].e;
	}
	sort(water_pool, water_pool + N, compare);
}

void solve() {
	int last_covered = water_pool[0].s;
	for (int i = 0; i < N; i++) {
		if (last_covered > water_pool[i].e) continue;
		else if (last_covered > water_pool[i].s) {
			int tmp = water_pool[i].e - last_covered;
			if (tmp % L == 0) { 
				ans_cnt += tmp / L; 
				last_covered = last_covered + L * (tmp / L);
			}
			else { 
				ans_cnt += tmp / L + 1; 
				last_covered = last_covered + L * (tmp / L + 1);
			}
		}
		else {
			int tmp = water_pool[i].e - water_pool[i].s;
			if (tmp % L == 0) {
				ans_cnt += tmp / L;
				last_covered = water_pool[i].s + L * (tmp / L);
			}
			else {
				ans_cnt += tmp / L + 1;
				last_covered = water_pool[i].s + L * (tmp / L + 1);
			}
		}
	}
}