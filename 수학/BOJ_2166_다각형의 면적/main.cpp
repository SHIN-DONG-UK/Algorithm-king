#include <iostream>
#include <iomanip>
using namespace std;

struct Point {
	double x, y;
};

int N;
Point pts[100005];

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
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> pts[i].x >> pts[i].y;
	}
}

void solve() {
	double sum = 0;
	for (int i = 0; i < N - 1; i++) {
		sum += (pts[i].x * pts[i + 1].y - pts[i].y * pts[i + 1].x);
	}

	sum += (pts[N - 1].x * pts[0].y - pts[N - 1].y * pts[0].x);

	if (sum > 0) sum /= 2.0;
	else sum /= -2.0;

	cout << fixed << setprecision(1) << sum  << '\n';
}