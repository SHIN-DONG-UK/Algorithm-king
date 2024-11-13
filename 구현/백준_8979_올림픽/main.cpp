#include <iostream>
#include <algorithm>

#define MAX_N 1000
using namespace std;

struct Nation {
	int num;
	int gold;
	int silver;
	int bronze;
};

int N, K;
Nation arr[MAX_N];

void Input();
int Solve();

int main() {
	Input();
	int rank = Solve();

	cout << rank << '\n';
	return 0;
}

void Input() {
	cin >> N >> K;
	int num;
	int cnt;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i].num = num;
		cin >> cnt;
		arr[i].gold = cnt;
		cin >> cnt;
		arr[i].silver = cnt;
		cin >> cnt;
		arr[i].bronze = cnt;
	}
}

bool compare(Nation a, Nation b) {
	if (a.gold != b.gold)
		return a.gold > b.gold;
	else if (a.silver != b.silver)
		return a.silver > b.silver;
	return a.bronze > b.bronze;
}

int Solve() {
	sort(arr, arr + N, compare);
	
	int cnt = 0;
	for (int i = 0; i < N-1; i++) {
		if (arr[i].num == K) {
			while (true) {
				if (arr[i].gold != arr[i - 1].gold || arr[i].silver != arr[i - 1].silver || arr[i].bronze != arr[i - 1].bronze)
					return i + 1;
				i--;
			}
			
		}
	}
}