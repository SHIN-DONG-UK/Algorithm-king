#include <iostream>
#include <vector>
using namespace std;

struct Attack {
	int t;
	int damage;
};

int casting_time;
int recovery_per_second;
int additional_recovery_amount;
int health;

vector<Attack> attacks;

void init();
void solve();



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> casting_time >> recovery_per_second >> additional_recovery_amount;
	cin >> health;
	int len;
	cin >> len;


	for (int i = 0; i < len; i++) {
		int t, d;
		cin >> t >> d;
		attacks.push_back({ t, d });
	}
}

void solve() {
	// t = 0
	int now_t = 0;
	int cnt = 0;
	int end_t = attacks.back().t;
	int idx = 0;
	int now_health = health;

	while (now_t < end_t) {
		now_t++;

		// attack check
		if (now_t == attacks[idx].t) {
			now_health -= attacks[idx].damage;
			idx++;
			cnt = 0;

			if (now_health <= 0) {
				cout << "-1\n";
				return;
			}

			continue;
		}
		else {
			cnt++;
		}
		
		int delta = recovery_per_second;

		if (cnt == casting_time) {
			delta += additional_recovery_amount;
			cnt = 0;
		}

		now_health += delta;

		if (now_health >= health) {
			now_health = health;
		}
	}

	cout << now_health << '\n';
}