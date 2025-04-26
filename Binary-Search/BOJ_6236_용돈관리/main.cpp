#include <iostream>
using namespace std;

int N, M;
int moneys[100000];
int sum;
int ans;

void input();
void BinarySearch();
bool check(int ul);

int main() {
	input();
	BinarySearch();
	cout << ans << '\n';
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> moneys[i];
		sum += moneys[i];
	}
}

void BinarySearch() {
	int start = 1;
	int end = sum;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;

		if (check(mid)) {
			ans = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}
}

bool check(int ul) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (ul < moneys[i]) return false;

		sum += moneys[i];
		if (sum > ul) {
			sum = moneys[i];
			count++;
		}
	}
	count++;

	if (count <= M) return true;
	else return false;
}