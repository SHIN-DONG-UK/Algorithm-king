#include <iostream>
#include <vector>
using namespace std;

const int MIN_PROFICIENT = 1;
const int MAX_PROFICIENT = 100000;

int n;
long long limit;
vector<int> diffs;
vector<int> times;

void init();
int solve();

bool is_possible(int k);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	init();
	int ans = solve();

	cout << ans << '\n';

	return 0;
}

void init() {
	cin >> n;

	int diff;
	for (int i = 0; i < n; i++) {
		cin >> diff;
		diffs.push_back(diff);
	}

	int time;
	for (int i = 0; i < n; i++) {
		cin >> time;
		times.push_back(time);
	}

	cin >> limit;
}

int solve() {
	int rst = 0;

	int s = MIN_PROFICIENT;
	int e = MAX_PROFICIENT;

	int mid;
	while (s <= e) {
		mid = (s + e) / 2;

		if (is_possible(mid)) {
			rst = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	return rst;
}

bool is_possible(int k) {
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		if (diffs[i] <= k) {
			sum += times[i];
		}
		else {
			sum += (times[i - 1] + times[i]) * (diffs[i] - k) + times[i];
		}

		if (sum > limit) {
			return false;
		}
	}

	return true;
}