#include <iostream>
using namespace std;

int N, M;
int lessons[100000];
int end_val;
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
		cin >> lessons[i];
		end_val += lessons[i];
	}
}

void BinarySearch() {
	int start = 1; // 주의1
	int end = end_val;
	int mid;
	while (start <= end) {
		mid = (start + end) / 2;

		if (check(mid)) {
			end = mid - 1;
			ans = mid;
		}
		else start = mid + 1;
	}
}

bool check(int ul) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (lessons[i] > ul) return false; // 주의2

		sum += lessons[i];
		if (sum > ul) {
			sum = lessons[i];
			count++;
		}
	}
	count++;

	if (count <= M) return true;
	else return false;
}