#include <iostream>
#include <queue>
using namespace std;

int n, w, L;
queue<int> wait_queue;
int bridge[100];
int bCnt;
int wSum;

void input();
int solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();

	int ans = solve();

	cout << ans << '\n';


	return 0;
}

void input() {
	cin >> n >> w >> L;
	int tw;
	for (int i = 0; i < n; i++) {
		cin >> tw;
		wait_queue.push(tw);
	}
}

int solve() {
	int time = 0;
	int truckWeight;
	while (wait_queue.size() != 0 || bCnt != 0) {
		//1. 한 칸 밀어
		if (bridge[0] != 0) {
			bCnt--;
			wSum -= bridge[0];
		}
		for (int i = 1; i < w; i++) bridge[i - 1] = bridge[i];
		bridge[w - 1] = 0; //일단 공백을 채워넣자

		//2. 채워 넣어
		if (wait_queue.size() > 0) {
			truckWeight = wait_queue.front();
			if (wSum + truckWeight <= L) {
				wSum += truckWeight;
				bCnt++;
				bridge[w - 1] = truckWeight;
				wait_queue.pop();
			}
		}
		
		time++;
	}

	return time;
}