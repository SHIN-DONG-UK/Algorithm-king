#include <iostream>
#include <vector>
using namespace std;

using u64 = unsigned long long;
const int ARRSIZE = 13;

int N;
int vec[ARRSIZE]; int mSize;

void init();
void solve();
void output();

u64 compose();
void decompose(const u64& num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	output();

	return 0;
}

void init() {
	cin >> N;
	vec[++mSize] = 1;
}

void solve() {
	u64 tmp = 0;
	for (int i = 2; i <= N; i++) {
		tmp = compose();

		tmp *= i;

		decompose(tmp);
	}
}

void output() {
	for (int i = 5; i >= 1; i--) {
		cout << vec[i];
	}
	cout << '\n';
}

u64 compose() {
	u64 rst = 0;
	while (mSize > 0) {
		rst *= 10;
		rst += vec[mSize--];
	}
	return rst;
}

void decompose(const u64& num) {
	u64 now = num;
	int tmp;

	bool flag = false;

	while (now != 0) {
		tmp =  now % 10;

		if (!flag) {
			if (tmp == 0) { 
				//cout << "끝자리가 0이라서 vec에 저장하지 않음\n";
			}
			else { 
				flag = true;
				//cout << "처음으로 0이 아니라서 flag를 true로 함\n";
			}
		}
		if(flag) { vec[++mSize] = tmp; }

		now /= 10;

		if (mSize == ARRSIZE - 1) { return; }
	}
}