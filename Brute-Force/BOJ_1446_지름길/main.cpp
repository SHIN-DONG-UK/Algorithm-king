#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ShortCut {
	int start;
	int end;
	int dist;
};

int N, D;
vector<ShortCut> vec;
bool chk[12];
int ans;

void init();
void go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	go(0);

	cout << ans << '\n';

	return 0;
}

bool compare(const ShortCut& a, const ShortCut& b) {
	return a.start < b.start;
}

void init() {
	cin >> N >> D;
	int s, e, d;
	for (int i = 0; i < N; i++) {
		cin >> s >> e >> d;
		vec.push_back({ s,e,d });
	}
	sort(vec.begin(), vec.end(), compare);
	ans = 1e9;
}

void go(int idx) {
	if (idx == N) {
		int tmpDist = 0;
		int last = 0;
		for (int i = 0; i < N; i++) {
			if (chk[i]) {
				if (tmpDist == 0) {
					if (vec[i].end > D) return;
					tmpDist = vec[i].start + vec[i].dist;
					last = vec[i].end;
				}
				else {
					if (vec[i].start < last)
						return;
					else if (vec[i].end > D)
						return;
					else {
						tmpDist += (vec[i].start - last) + vec[i].dist;
						last = vec[i].end;
					}
				}
			}
		}
		if (last < D)
			tmpDist += D - last;

		if (ans > tmpDist) {
			ans = tmpDist;
		}
		return;
	}
	chk[idx] = true;
	go(idx + 1);
	chk[idx] = false;
	go(idx + 1);
}