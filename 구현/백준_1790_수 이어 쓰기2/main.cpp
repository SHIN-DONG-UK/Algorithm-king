#include <iostream>

using namespace std;

int N, k;

int GetLength(int num);

int main() {
	cin >> N >> k;
	
	int howmanytimes = 0;
	int target = -1;
	for (int i = 1; i <= N; i++)
	{
		// 몇 번째인지 계산 -> k번째가 가능한 순간 멈추고 리턴
		howmanytimes += GetLength(i);
		if (howmanytimes >= k) {
			target = i;
			break;
		}
	}

	// howmanytimes - k == target에서 뒤에서 앞으로 가야하는 횟수
	int t = howmanytimes - k;
	int ans = target;

	while (t > 0) {
		target = target / 10;
		t--;
	}

	ans = target % 10;

	cout << ans << '\n';
}

int GetLength(int num) {
	int rst = 1;
	while (num / 10 != 0) {
		rst++;
		num = num / 10;
	}
	return rst;
}