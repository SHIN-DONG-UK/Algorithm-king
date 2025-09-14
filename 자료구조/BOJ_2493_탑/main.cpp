#include <iostream>
using namespace std;

const int MX = 500'000;


int N;
int mstack[MX + 1]; int mSize;
int indexArr[MX + 1];

void init();
void solve();

int top();
void push(int num, int index);
void pop();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> N;
}

void solve() {
	int height;

	cin >> height;
	push(height, 1);

	for (int i = 2; i <= N; i++) {
		cin >> height;
		while (height > top() && mSize > 0) {
			pop();
		}
		push(height, i);
	}
}

void push(int num, int index) {
	mstack[++mSize] = num;
	indexArr[mSize] = index;
	cout << indexArr[mSize - 1] << ' ';
}

void pop() {
	if (mSize > 0) {
		mSize--;
	}
}

int top() {
	if (mSize > 0) return mstack[mSize];
	else return -1;
}