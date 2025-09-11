#include <iostream>
#include <vector>
using namespace std;

const int MX = 1'000'000;

int N;
int arr[MX];

vector<int> decreasing;
vector<int> ans;

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

	int num;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	decreasing.push_back(arr[N - 1]);
	ans.push_back(-1);

	for (int i = N - 2; i >= 0; i--) {
		while (!decreasing.empty() && decreasing.back() <= arr[i]) {
			decreasing.pop_back();
		}

		decreasing.push_back(arr[i]);

		if (decreasing.size() == 1) {
			ans.push_back(-1);
		}
		else {
			int size = decreasing.size();
			ans.push_back(decreasing[size - 2]);
		}
	}

	for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
		cout << *it << ' ';
	}
	cout << '\n';


}