#include <iostream>
#include <queue>
using namespace std;

int dy[6] = { -2,-2,0,0,2,2 };
int dx[6] = { -1,1,-2,2,-1,1 };

const int MX = 200;

struct Point {
	int y;
	int x;
};


int N;
int arr[MX][MX];
int visited[MX][MX];

Point sp, ep;

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
	cin >> sp.y >> sp.x >> ep.y >> ep.x;
}

void solve() {
	queue<Point> Q;
	Q.push(sp);
	visited[sp.y][sp.x] = 1;

	Point cp, np;
	while (!Q.empty()) {
		cp = Q.front(); Q.pop();
		for (int d = 0; d < 6; d++) {
			np = { cp.y + dy[d], cp.x + dx[d] };
			if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= N) 
				continue;
			if (visited[np.y][np.x] > 0)
				continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			Q.push(np);

			if (np.y == ep.y && np.x == ep.x) {
				cout << visited[cp.y][cp.x] << '\n';
				return;
			}
		}
	}

	cout << "-1\n";
	return;
}
