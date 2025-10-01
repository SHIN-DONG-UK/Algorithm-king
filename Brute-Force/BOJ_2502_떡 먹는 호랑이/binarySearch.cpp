#include <iostream>
using namespace std;

int D, K;
int arr[31];

void init();
void solve();
void exec(const int& A, const int& B);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> D >> K;
}

void solve() {
	for (int a = 1; a <= 100'000; a++) {
		int bl = a; int br = 100'000;
		int bmid;
		while (bl <= br) {
			bmid = (bl + br) / 2;

			exec(a, bmid);

			if (arr[D] == K) {
				cout << a << '\n';
				cout << bmid << '\n';
				return;
			}

			if (arr[D] > K) { br = bmid - 1; }
			else { bl = bmid + 1; }
		}
	}
}

void exec(const int& A, const int& B) {
	arr[1] = A;
	arr[2] = B;
	for (int i = 3; i <= D; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
}