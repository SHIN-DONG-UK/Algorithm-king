#include <iostream>
#include <cstring>

#define MAX_N 100000
#define VISITED 1
#define CLOSED 10
#define NOT_CLOSED 100

using namespace std;

int n;
int map[MAX_N + 1];
int state[MAX_N + 1];
int ans;

void Init();
void Input();
void Run(int x);

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		
		Init();
		
		Input();

		for (int i = 1; i <= n; i++) {
			if (state[i] == CLOSED || state[i] == NOT_CLOSED)
				continue;
			Run(i);
		}

		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_CLOSED)
				ans++;
		}

		cout << ans << '\n';
	}
}
void Init() {
	ans = 0;
	memset(state, 0, sizeof(state));
}

void Input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> map[i];
}

void Run(int x) {
	// 처음은 방문하지 않은 노드
	int cur = x;
	while (true){
		state[cur] = VISITED;
		cur = map[cur];
		// 1번 케이스
		if (state[cur] == NOT_CLOSED || state[cur] == CLOSED) {
			cur = x;
			while (state[cur] == VISITED) {
				state[cur] = NOT_CLOSED;
				cur = map[cur];
			}
			return;
		}

		// 2번 케이스
		if (state[cur] == VISITED && cur != x) {
			while (state[cur] != CLOSED) {
				state[cur] = CLOSED;
				cur = map[cur];
			}
			cur = x;
			while (state[cur] != CLOSED) {
				state[cur] = NOT_CLOSED;
				cur = map[cur];
			}
			return;
		}

		// 3번 케이스
		if (state[cur] == VISITED && cur == x) {
			while (state[cur] != CLOSED) {
				state[cur] = CLOSED;
				cur = map[cur];
			}
			return;
		}
			
	}
}