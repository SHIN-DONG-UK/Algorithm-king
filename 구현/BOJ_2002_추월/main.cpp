#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N;
unordered_map<string, int> hmap;
int arr[1000];
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
	cin >> N;
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		hmap[tmp] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		int value = hmap[tmp];
		arr[i] = value;
	}
}

void solve() {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) {
				ans++;
				break;
			}
		}
	}
}