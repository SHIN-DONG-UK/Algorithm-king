#include <iostream>
using namespace std;

int N, P;
int guitar[7][500001];
int gSize[7];
int cnt;

void init();
void solve();
void fingering(const int& n, const int& f);
void putOff(const int& n);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << cnt << '\n';

	return 0;
}

void init() {
	cin >> N >> P;
}

void solve() {
	int num, fret;
	while (N--) {
		cin >> num >> fret;
		if (gSize[num] == 0 || guitar[num][gSize[num]] < fret) {
			fingering(num, fret);
		}
		else {
			while (gSize[num] > 0 && guitar[num][gSize[num]] > fret) {
				putOff(num);
			}
			if (guitar[num][gSize[num]] == fret) {
				continue;
			}
			else {
				fingering(num, fret);
			}
			
		}
	}
}

void fingering(const int& n, const int& f) {
	guitar[n][++gSize[n]] = f;
	cnt++;
}

void putOff(const int& n) {
	guitar[n][gSize[n]--] = 0;
	cnt++;
}