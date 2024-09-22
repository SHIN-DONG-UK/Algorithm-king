#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int nums[1000000];

void init();
void input();
bool BinarySearch(int tar);
void simulation();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		input();
		simulation();
	}
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	sort(nums, nums + N);

	cin >> M;
}

void simulation() {
	int tar;
	for (int i = 0; i < M; i++)
	{
		cin >> tar;
		if (BinarySearch(tar)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
		
	}
}

bool BinarySearch(int tar) {
	int start = 0;
	int end = N-1;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;

		if (nums[mid] > tar) end = mid - 1;
		else if (nums[mid] < tar) start = mid + 1;
		else return true;
	}
	return false;
}