#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
bool visited[2000001];
vector<int> pos_arr;
vector<int> diff;

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
	cin >> K;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (visited[num + 1000000]) continue;
		visited[num + 1000000] = true;
		pos_arr.push_back(num);
	}
	sort(pos_arr.begin(), pos_arr.end());

	for (int i = 1; i < pos_arr.size(); i++) {
		diff.push_back(pos_arr[i] - pos_arr[i - 1]);
	}
	sort(diff.begin(), diff.end(), greater<>());

}

void solve() {
	int sum = pos_arr.back() - pos_arr.front();

	for (int i = 0; i < min(static_cast<size_t>(K - 1), diff.size()); i++) {
		sum -= diff[i];
	}

	cout << sum << '\n';
}