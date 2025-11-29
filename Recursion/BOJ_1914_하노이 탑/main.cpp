#include <iostream>
#include <string>
using namespace std;

int N;

void init();
void print_cnt();
string multiplyBy2(const string& num);
void hanoi(int k, int from, int to, int via);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	print_cnt();
	if (N <= 20) {
		hanoi(N, 1, 3, 2);
	}
	
	return 0;
}

void init() {
	cin >> N;
}

void hanoi(int k, int from, int to, int by) {
	if (k == 0) {
		return;
	}

	hanoi(k - 1, from, by, to);
	cout << from << ' ' << to << '\n';
	hanoi(k - 1, by, to, from);
}

string multiplyBy2(const string& num) {
	string result = "";
	int carry = 0;

	for (int i = num.size() - 1; i >= 0; i--) {
		int digit = (num[i] - '0') * 2 + carry;
		carry = digit / 10;
		digit %= 10;
		result = char(digit + '0') + result;
	}

	if (carry > 0) {
		result = char(carry + '0') + result;
	}

	return result;
}

void print_cnt() {
	string value = "1";
	for (int i = 0; i < N; i++) {
		value = multiplyBy2(value);
	}
	value.back() -= 1;

	cout << value << '\n';
}