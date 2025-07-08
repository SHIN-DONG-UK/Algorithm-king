#include <iostream>
#include <vector>
using namespace std;

int N;
int map[10][10];

int best[2];
vector<pair<int, int>> cells[2]; //0 : (i+j)가 짝수, 1 : (i+j)가 홀수
bool dia1[20]; bool dia2[20];

void go(int idx, int cnt, int mode);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j])
				cells[(i + j) & 1].push_back({ i, j });
		}
	}

	go(0, 0, 0);
	go(0, 0, 1);

	cout << best[0] + best[1] << '\n';

	return 0;
}

void go(int idx, int cnt, int mode) {
	if (idx == cells[mode].size()) {
		best[mode] = max(best[mode], cnt);
		return;
	}

	//p1. 앞으로 다 놓는다고 해도 최고 못넘으면 컷
	int remain = cells[mode].size() - idx;
	if (cnt + remain <= best[mode]) return;

	//p2. 대각선 컷
	int y = cells[mode][idx].first;
	int x = cells[mode][idx].second;
	int d1 = y - x + N - 1;
	int d2 = y + x;
	if (!dia1[d1] && !dia2[d2]) {
		//a1. 놓기
		dia1[d1] = dia2[d2] = true;
		go(idx + 1, cnt + 1, mode);
		dia1[d1] = dia2[d2] = false;
	}
	//a2. 놓지 않기
	go(idx + 1, cnt, mode);
}