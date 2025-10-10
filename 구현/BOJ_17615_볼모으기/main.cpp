#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char arr[500005];
vector<int> red;
vector<int> blue;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	solve();

	return 0;
}

void init() {
	cin >> N;
	cin >> arr;
}
void solve() {
	//1. 덩어리 개수 파악
	bool flag;

	if (arr[0] == 'R') flag = true;
	else flag = false;

	int cnt = 1;
	int i = 1;

	while (i < N) {
		if (arr[i] == 'R') {
			if (flag) cnt++;
			else {
				blue.push_back(cnt);
				cnt = 1;
				flag = true;
			}
		}
		else {
			if (!flag) cnt++;
			else {
				red.push_back(cnt);
				cnt = 1;
				flag = false;
			}
		}
		i++;
	}
	
	if (flag) red.push_back(cnt);
	else blue.push_back(cnt);
	
	//2. 정답

	if (red.size() <= 1 && blue.size() <= 1) {
		cout << "0\n";
	}
	else if (red.size() == blue.size()) {
		int redNum = 0;
		int blueNum = 0;
		if (arr[0] == 'R') {
			for (int i = red.size() - 1; i >= 1; i--) {
				redNum += red[i];
			}
			for (int i = 0; i < blue.size() - 1; i++) {
				blueNum += blue[i];
			}
			
		}
		else {
			for (int i = blue.size() - 1; i >= 1; i--) {
				blueNum += blue[i];
			}
			for (int i = 0; i < red.size() - 1; i++) {
				redNum += red[i];
			}
		}

		cout << min(redNum, blueNum) << '\n';
	}
	else {
		int biggerLeft = 0;
		int biggerRight = 0;
		int smaller = 0;
		if (red.size() > blue.size()) {
			for (int i = red.size() - 1; i >= 1; i--) {
				biggerLeft += red[i];
			}
			for (int i = 0; i < red.size() - 1; i++) {
				biggerRight += red[i];
			}
			for (int i = 0; i < blue.size(); i++) {
				smaller += blue[i];
			}
		}
		else {
			for (int i = blue.size() - 1; i >= 1; i--) {
				biggerLeft += blue[i];
			}
			for (int i = 0; i < blue.size() - 1; i++) {
				biggerRight += blue[i];
			}
			for (int i = 0; i < red.size(); i++) {
				smaller += red[i];
			}
		}

		cout << min({ biggerLeft, biggerRight, smaller }) << '\n';
	}
}