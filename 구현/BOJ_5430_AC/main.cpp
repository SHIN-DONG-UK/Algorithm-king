#define LEFT 0
#define RIGHT 1
#include <iostream>
#include <string>
#include <deque>
using namespace std;

string func;
int n;
string nums;
bool dir;

void input(deque<string>& dq);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		deque<string> dq;
		input(dq);
		bool is_error = false;

		for (char c : func) {
			if (c == 'R') dir = !dir;
			else if (c == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					is_error = true;
					break;
				}

				if (dir == LEFT) dq.pop_front();
				else if (dir == RIGHT) dq.pop_back();
			}
		}

		if (is_error) continue;

		// 출력
		cout << '[';
		while (dq.size() > 1) {
			if (dir == LEFT) {
				cout << dq.front() << ',';
				dq.pop_front();
			}
			else if(dir == RIGHT) {
				cout << dq.back() << ',';
				dq.pop_back();
			}
		}
		if (!dq.empty()) {
			if (dir == LEFT) {
				cout << dq.front();
				dq.pop_front();
			}
			else if (dir == RIGHT) {
				cout << dq.back();
				dq.pop_back();
			}
		}
		cout << "]\n";
	}
	return 0;
}

void input(deque<string>& dq) {
	cin >> func;
	cin >> n;
	cin >> nums;
	dir = LEFT;

	int st = 1; // '[' 제외
	int en = 0;
	while (1) {
		en = nums.find(',', st);
		if (en == -1) break;
		dq.push_back(nums.substr(st, en - st));
		st = en + 1;
	}
	// 마지막 요소 고려
	en = nums.find(']', st);
	if (nums.substr(st, en - st) != "")
		dq.push_back(nums.substr(st, en - st));
}