#define MAX_NUM 100000
#include <iostream>
using namespace std;

int T, n, cnt;
int arr[MAX_NUM + 1];       // 1-based index
bool visited[MAX_NUM + 1];  // 방문
bool done[MAX_NUM + 1];	    // 처리 완료

void dfs(int cur);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cnt = 0; // init
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			visited[i] = 0; done[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		cout << n - cnt << '\n';
	}

	return 0;
}

void dfs(int cur) {
	visited[cur] = 1;
	int next = arr[cur];
	if (!visited[next]) {
		dfs(next);
	}
	else if (!done[next]) {
		// 처음 만난 회색 -> 사이클의 시작
		// for문으로 사이클을 돌면서 크기 세기
		for (int i = next; i != cur; i = arr[i])
			cnt++;
		cnt++; // 자기 자신도 카운트
	}
	done[cur] = 1; // 되돌아가면서 처리완료
	return;
}