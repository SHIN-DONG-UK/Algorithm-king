#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int pos[1001];
int ans;

void input();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	solve();

	cout << ans << '\n';
	return 0;
}

void input() {
	cin >> N >> L;

	int p;
	for (int i = 0; i < N; i++)
	{
		cin >> p;
		pos[p] = 1;
	}
}

void solve() {
	int i = 1;
	while (i <= 1000) {
		if (pos[i] == 0)
			i++;
		else {
			ans++;
			i += L;
		}
	}
}