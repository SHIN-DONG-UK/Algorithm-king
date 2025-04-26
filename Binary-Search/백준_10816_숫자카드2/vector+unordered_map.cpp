#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int N, M;
vector<int> cards;
unordered_map<int, int> CardCount;

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
		int tmp;
		cin >> tmp;
		cards.push_back(tmp);
		CardCount[tmp]++;
	}

	sort(cards.begin(), cards.end());

	cin >> M;
}

void simulation() {
	int tar;
	int idx;

	for (int i = 0; i < M; i++)
	{
		cin >> tar;
		idx = BinarySearch(tar);
		if (idx >= 0) cout << CardCount[cards[idx]] << ' ';
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