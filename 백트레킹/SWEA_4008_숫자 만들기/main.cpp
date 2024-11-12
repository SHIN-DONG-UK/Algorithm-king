#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MAX 12
using namespace std;

// 데이터
int N;
int numbers[MAX];
int oper[4];
// 순열
vector<int> selected;
// 정답
int min_ans = 1e9;
int max_ans = -1e9;

void Init();
void Input();
int calc();
void Go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		Init();
		Input();
		Go(0);

		cout << '#' << tc << ' ' << max_ans - min_ans << '\n';
	}
}

void Init() {
	min_ans = 1e9;
	max_ans = -1e9;
	selected.clear();
}

void Input() {
	cin >> N;

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	for (int i = 0; i < N; i++)
		cin >> numbers[i];
}

void Go(int idx) {
	if (idx == N - 1) {
		int tmp = calc();
		min_ans = min(min_ans, tmp);
		max_ans = max(max_ans, tmp);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] == 0)
			continue;
		oper[i] -= 1;
		selected.push_back(i);
		Go(idx + 1);
		selected.pop_back();
		oper[i] += 1;
	}
}

int calc() {
	int rst = numbers[0];

	for (int i = 0; i < selected.size(); i++)
	{
		if (selected[i] == 0)
			rst += numbers[i + 1];
		else if (selected[i] == 1)
			rst -= numbers[i + 1];
		else if (selected[i] == 2)
			rst *= numbers[i + 1];
		else
			rst /= numbers[i + 1];
	}
	return rst;
}