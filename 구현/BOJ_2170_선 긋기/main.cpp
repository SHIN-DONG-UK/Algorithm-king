#include <iostream>
#include <algorithm>
using namespace std;

struct Point {
	int x;
	int y;
};

int N;
Point points[1000005];
long long t;
long long ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

bool compare(const Point& a, const Point& b) {
	return a.x < b.x;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}

	sort(points, points + N, compare);
}

void solve() {
	ans += points[0].y - points[0].x;
	t = points[0].y;

	for (int i = 1; i < N; i++) {
		if (t >= points[i].x) {
			if (t < points[i].y) {
				ans += points[i].y - t;
				t = points[i].y;
			}
		}
		else {
			ans += points[i].y - points[i].x;
			t = points[i].y;
		}
	}

	cout << ans << '\n';
}