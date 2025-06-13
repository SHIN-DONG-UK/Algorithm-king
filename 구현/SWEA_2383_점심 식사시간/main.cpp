#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
};

struct Stair {
	Point p;
	int len;
};

//[input]
int N;
int h_cnt;
Point hlist[10]; //사람 위치 인덱싱
Stair st[2];

void init();
int getTime(vector<int>& v, int len);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();

		cin >> N;
		int num;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> num;
				if (num == 1) {
					hlist[h_cnt] = { i, j };
					h_cnt++;
				}
				else if (num > 1) {
					if (st[0].len == 0) {
						st[0].p = { i,j };
						st[0].len = num;
					}
					else {
						st[1].p = { i,j };
						st[1].len = num;
					}
				}
			}
		}

		int ans = 1e9;
		//[Brute-Force]
		for (int tmp = 0; tmp < (1 << h_cnt); tmp++) {
			vector<int> st0;
			vector<int> st1;
			for (int i = 0; i < h_cnt; i++) {
				//[implementation]
				int idx = (h_cnt - 1) - i;

				if ((tmp & (1 << i)) == 0) {
					// 현재 idx가 0번 계단에 배정
					int minute = abs(st[0].p.y - hlist[idx].y) + abs(st[0].p.x - hlist[idx].x);
					st0.push_back(minute);
				}
				else {
					// 현재 idx가 1번 계단에 배정
					int minute = abs(st[1].p.y - hlist[idx].y) + abs(st[1].p.x - hlist[idx].x);
					st1.push_back(minute);
				}
			}
			//오름차순 정렬
			sort(st0.begin(), st0.end());
			sort(st1.begin(), st1.end());

			int a = getTime(st0, st[0].len);
			int b = getTime(st1, st[1].len);

			ans = min(ans, max(a, b));
		}

		cout << '#' << tc << ' ' << ans - 1 << '\n';
	}
	
	return 0;
}

void init() {
	h_cnt = 0;
	memset(st, 0, sizeof(st));
}

int getTime(vector<int>& v, int len) {
	if (v.empty()) return 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> wait;

	for (int& t : v)
		wait.push(t + 1); // 계단 입구에서 대기 1분

	int time = 0;
	while (!wait.empty() || !pq.empty()) {
		while (!pq.empty() && pq.top() <= time)
			pq.pop();

		while (!wait.empty() && wait.front() <= time && pq.size() < 3) {
			pq.push(time + len);
			wait.pop();
		}

		time++; // ++하고 끝나기 때문에 최종 -1을 해줘야 함
	}
	return time;
}