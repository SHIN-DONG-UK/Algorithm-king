#include <iostream>
using namespace std;

int N, M;
int req[10000];
int max_val;
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
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> req[i];
		if (req[i] > max_val) max_val = req[i];
	}
	cin >> M;
}

void BinarySearch() {
	int start = 0;
	int end = max_val;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (check(mid)) {
			ans = mid;
			start = mid + 1;
		}
		else end = mid - 1;

	}
}

bool check(int ul) {
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (req[i] >= ul) sum += ul;
		else sum += req[i];
	}
	if (sum <= M) return true;
	else return false;
}