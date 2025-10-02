#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pole {
	int pos;
	int height;
};

int N;
vector<Pole> poles;
int gMax, gIdx;
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

bool compare(const Pole& a, const Pole& b) {
	return a.pos < b.pos;
}

void init() {
	cin >> N;
	int pos, height;
	for (int i = 0; i < N; i++) {
		cin >> pos >> height;
		poles.push_back({ pos, height });
	}

	sort(poles.begin(), poles.end(), compare);

	for (int i = 0; i < N; i++) {
		if (gMax < poles[i].height) {
			gMax = poles[i].height;
			gIdx = i;
		}
	}
}

void solve() {
	int prev_height = poles[0].height;
	int prev_pos = poles[0].pos;

	for (int i = 1; i <= gIdx; i++) {
		if (prev_height <= poles[i].height) {
			//갱신
			ans += prev_height * (poles[i].pos - prev_pos);
			prev_height = poles[i].height;
			prev_pos = poles[i].pos;
		}
	}

	prev_height = poles.back().height;
	prev_pos = poles.back().pos;

	for (int i = poles.size() - 2; i >= gIdx; i--) {
		if (prev_height <= poles[i].height) {
			//갱신
			ans += prev_height * (prev_pos - poles[i].pos);
			prev_height = poles[i].height;
			prev_pos = poles[i].pos;
		}
	}

	ans += gMax;
}