#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> hSet;
string strs;

bool visited[10];
int path[10];
string tictacto;

void init();
void go(int idx);
bool check();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();

	while (true) {
		cin >> strs;

		if (strs == "end") {
			break;
		}

		if (hSet.count(strs) != 0) {
			cout << "valid\n";
		}
		else {
			cout << "invalid\n";
		}
	}
	return 0;
}

void init() {
	tictacto.resize(9, '.');
	go(0);
}

void go(int idx) {
	// 1. 조기 종료
	if (check()) {
		hSet.insert(tictacto);
		return;
	}
	// 2. 조기 종료에 해당하지 않으면, 최종 상태
	if (idx == 9) {
		hSet.insert(tictacto);
		return;
	}

	// 3. 순열
	for (int i = 0; i < 9; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		//path[idx] = i; // for debug
		
		if (idx % 2 == 0) {
			tictacto[i] = 'X';
		}
		else {
			tictacto[i] = 'O';
		}
		
		go(idx + 1);
		visited[i] = false;
		tictacto[i] = '.';
	}
}

bool check() {
	// 1. 가로 검사
	for (int i = 0; i < 3; i++) {
		if (tictacto[3 * i + 0] == tictacto[3 * i + 1] && tictacto[3 * i + 1] == tictacto[3 * i + 2]) {
			if (tictacto[3 * i] != '.') {
				return true;
			}
		}
	}
	// 2. 세로 검사
	for (int j = 0; j < 3; j++) {
		if (tictacto[j] == tictacto[3 + j] && tictacto[3 + j] == tictacto[6 + j]) {
			if (tictacto[j] != '.') {
				return true;
			}
		}
	}
	// 3. 대각선 검사
	if (tictacto[0] == tictacto[4] && tictacto[4] == tictacto[8]) {
		if (tictacto[0] != '.') {
			return true;
		}
	}
	if (tictacto[2] == tictacto[4] && tictacto[4] == tictacto[6]) {
		if (tictacto[2] != '.') {
			return true;
		}
	}

	return false;
}