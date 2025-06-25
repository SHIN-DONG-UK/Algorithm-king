#include <iostream>
using namespace std;

int N;

bool visited_row[15];
bool visited_right_diagonal[15];
bool visited_left_diagonal[15];

int ans_cnt;

void go(int lev);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	go(0);

	cout << ans_cnt << '\n';

	return 0;
}

void go(int j) {
	if (j == N) {
		ans_cnt++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (visited_row[i]) continue;
		if (visited_right_diagonal[i - j + N - 1]) continue;
		if (visited_left_diagonal[i + j]) continue;

		visited_row[i] = visited_right_diagonal[i - j + N - 1] = visited_left_diagonal[i + j] = 1;
		go(j + 1);
		visited_row[i] = visited_right_diagonal[i - j + N - 1] = visited_left_diagonal[i + j] = 0;
	}
}