#include <iostream>
using namespace std;

double X, Y;
int Z;
int ans = -1;

void input();
void BinarySearch();
bool check(int n);

int main() {
	input();
	if (Z != 100 && Z != 99) BinarySearch();
	cout << ans << '\n';
}

void input() {
	cin >> X >> Y;
	Z = (Y * 100) / X;
}

void BinarySearch() {
	int start = 0;
	int end = 1000000000;
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

bool check(int n) {
	int tmp = ((Y + n) * 100) / (X + n);
	if (tmp > Z) return true;
	else return false;
}