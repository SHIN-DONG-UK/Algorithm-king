#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T;
int N;
string arr[100000];
unordered_map<string, int> strCnt;
int ans;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		init();
		solve();
		
		cout << ans << "\n";
	}
	return 0;
}


void init() {
	strCnt.clear();
	cin >> N;

	string tmp;
	int minus = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (strCnt[tmp] < 3) {
			strCnt[tmp]++;
			arr[i] = tmp;
		}
		else {
			minus++;
		}
	}
	ans = 1e9;
	N -= minus;
}

void solve() {
	int cnt;
	for (int a = 0; a < N - 2; a++) {
		for (int b = a + 1; b < N - 1; b++) {
			for (int c = b + 1; c < N; c++) {
				cnt = 0;
				//1. AB
				for (int i = 0; i < 4; i++) {
					if (arr[a][i] != arr[b][i])
						cnt++;
				}
				//2. BC
				for (int i = 0; i < 4; i++) {
					if (arr[b][i] != arr[c][i])
						cnt++;
				}
				//3. CA
				for (int i = 0; i < 4; i++) {
					if (arr[c][i] != arr[a][i])
						cnt++;
				}
				//ans update
				if (ans > cnt)
					ans = cnt;
			}
		}
	}
}