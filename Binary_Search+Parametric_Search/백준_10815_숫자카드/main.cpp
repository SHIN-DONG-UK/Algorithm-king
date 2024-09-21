#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int cards[500000];

void input();
void simulation();
bool BinarySearch(int tar);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	simulation();
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	sort(cards, cards + N);

	cin >> M;
}

void simulation() {
	int tar;
	for (int i = 0; i < M; i++)
	{
		cin >> tar;
		if (BinarySearch(tar)) cout << "1 ";
		else cout << "0 ";
	}
	cout << '\n';
}

bool BinarySearch(int tar) {
	int start = 0;
	int end = N - 1;
	int mid;

	while (start <= end) {
		mid = (start + end) / 2;

		if (cards[mid] > tar) end = mid - 1;
		else if (cards[mid] < tar) start = mid + 1;
		else return true;
	}
	return false;
}
