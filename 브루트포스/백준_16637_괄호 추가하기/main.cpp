#include <iostream>
#include <algorithm>

#define MAX 19
#define PLUS 10
#define MINUS 11
#define MUL	12
using namespace std;

int N;
int arr[MAX];
int check[MAX];
int ans = -2147483648;

void Input();
void Go(int idx);
void Calculate();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();
	if (N >= 3) {
		Go(1);
		cout << ans << '\n';
	}
	else
		cout << arr[0] << '\n';
	return 0;
}

void Input() {
	cin >> N;

	char tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp >= '0' && tmp <= '9')
			arr[i] = tmp - '0';
		else {
			if (tmp == '+')
				arr[i] = PLUS;
			else if (tmp == '-')
				arr[i] = MINUS;
			else
				arr[i] = MUL;

		}
	}
		
	
}

void Go(int idx) {
	if (idx >= N) {
		Calculate();
		return;
	}
	
	check[idx] = 1;
	Go(idx + 4);
	check[idx] = 0;
	Go(idx + 2);
}

void Calculate() {
	int tmp[MAX] = { 0 };
	for (int i = 0; i < N; i++)
		tmp[i] = arr[i];

	int val;
	// 괄호 계산
	for (int i = 1; i < N; i+=2)
	{
		if (check[i]) {
			if (tmp[i] == PLUS) {
				val = tmp[i - 1] + tmp[i + 1];
				tmp[i + 1] = val;
				tmp[i - 1] = val;
			}
				
			else if (tmp[i] == MINUS) {
				val = tmp[i - 1] - tmp[i + 1];
				tmp[i + 1] = val;
				tmp[i - 1] = val;
			}
			else {
				val = tmp[i - 1] * tmp[i + 1];
				tmp[i + 1] = val;
				tmp[i - 1] = val;
			}
				
		}
	}
	int rst = tmp[0];
	// 왼쪽에서 오른쪽 누적
	for (int i = 1; i < N; i += 2)
	{
		if (!check[i]) {
			if (tmp[i] == PLUS)
				rst += tmp[i + 1];
			else if (tmp[i] == MINUS)
				rst -= tmp[i + 1];
			else
				rst *= tmp[i + 1];
		}
	}

	ans = max(rst, ans);
}