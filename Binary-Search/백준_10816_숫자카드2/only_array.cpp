#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int cards[500000];
int DAT[20000002];

void input();
void simulation();
int BinarySearch(int tar);

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
		DAT[cards[i]+10000000]++;
	}

	sort(cards, cards + N);

	cin >> M;
}

void simulation() {
	int tar;
	int idx;

	for (int i = 0; i < M; i++)
	{
		cin >> tar;
		idx = BinarySearch(tar);
		if (idx >= 0) cout << DAT[cards[idx] + 10000000] << ' ';
		else cout << "0 ";

	}
}

int BinarySearch(int tar) {
	int start = 0;
	int end = N;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (cards[mid] > tar) end = mid - 1;
		else if (cards[mid] < tar) start = mid + 1;
		else return mid;
	}
	
	return -1;
}