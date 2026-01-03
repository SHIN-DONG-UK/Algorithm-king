#include <iostream>
using namespace std;

struct Point {
	int x;
	int y;
};

Point p1, p2, p3;

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
	cin >> p1.x >> p1.y;
	cin >> p2.x >> p2.y;
	cin >> p3.x >> p3.y;
}

void solve() {
	Point v1 = { p2.x - p1.x, p2.y - p1.y };
	Point v2 = { p3.x - p2.x, p3.y - p2.y };

	int val = v1.x * v2.y - v1.y * v2.x;
	if (val == 0) {
		cout << "0\n";
	}
	else if (val > 0) {
		cout << "1\n";
	}
	else {
		cout << "-1\n";
	}
}