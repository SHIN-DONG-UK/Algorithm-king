#include <iostream>
using namespace std;

int N;
bool visited[105];
int aList[105];
int ans;

void init();
void solve();
bool dfs(int now, int start, bool flag, int cnt);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N;

	int to;
	for (int from = 1; from <= N; from++) {
		cin >> to;
		aList[from] = to;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		// 판정이 끝난 노드는 더 이상 방문하지 않는다
		if (visited[i]) continue;
		dfs(i, i, false, 0);
	}

	cout << ans << '\n';

	for (int i = 1; i <= N ; i++) {
		if (visited[i]) {
			cout << i << '\n';
		}
	}
	
}

bool dfs(int now, int start, bool flag, int cnt) {
	if (flag && now == start) {
		ans += cnt;
		return true;
	}

	if (visited[now]) {
		return false;
	}

	visited[now] = true;
	if(dfs(aList[now], start, true, cnt + 1)) return true;
	visited[now] = false;

	return false;
}