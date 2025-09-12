#include <iostream>
using namespace std;

int T;
int x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> x >> y;
		const int dist = y - x;

		int n = 1;
		int rem = dist;
		int cnt = 0;
		while (1) {
			if (rem - n * 2 >= 0) {
				rem -= n * 2;
				cnt += 2;
			}
			else if (rem - n >= 0) {
				rem -= n;
				cnt += 1;
			}
			else {
				break;
			}

			n++;
		}
		cnt = rem == 0 ? cnt : cnt + 1;
		cout << cnt << '\n';
	}
	return 0;
}