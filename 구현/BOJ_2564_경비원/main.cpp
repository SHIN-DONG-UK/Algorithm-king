#include <iostream>
#include <vector>
using namespace std;

struct Store {
	int dir;
	int pos;
};

int width, height;
int k;
int ddir, dpos;
vector<Store> stores;
int ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> width >> height;
	cin >> k;

	int dir, pos;
	for (int i = 0; i < k; i++) {
		cin >> dir >> pos;
		stores.push_back({ dir, pos });
	}
	cin >> ddir >> dpos;
}

void solve() {
	if (ddir == 1) {
		for (auto& s : stores) {
			if (s.dir == 1) { ans += abs(s.pos - dpos); }
			else if (s.dir == 2) ans += min(dpos + height + s.pos, (width - dpos) + height + (width - s.pos));
			else if (s.dir == 3) { ans += dpos + s.pos; }
			else { ans += (width - dpos) + s.pos; }
		}
	}
	else if (ddir == 2) {
		for (auto& s : stores) {
			if (s.dir == 1) ans += min(dpos + height + s.pos, (width - dpos) + height + (width - s.pos)); 
			else if (s.dir == 2) { ans += abs(s.pos - dpos); }
			else if (s.dir == 3) { ans += dpos + (height -s.pos); }
			else { ans += (width - dpos) + (height - s.pos); }
		}
	}
	else if (ddir == 3) {
		for (auto& s : stores) {
			if (s.dir == 1) { ans += dpos + s.pos; }
			else if (s.dir == 2) { ans += (height - dpos) + s.pos; }
			else if (s.dir == 3) { ans += abs(dpos - s.pos); }
			else ans += min(dpos + width + s.pos, (height - dpos) + width + (height - s.pos));
		}
	}
	else {
		for (auto& s : stores) {
			if (s.dir == 1) { ans += dpos + (width - s.pos); }
			else if (s.dir == 2) { ans += (height - dpos) + (width - s.pos); }
			else if (s.dir == 3) ans += min(dpos + width + s.pos, (height - dpos) + width + (height - s.pos)); 
			else { ans += abs(dpos - s.pos); }
		}
	}
}