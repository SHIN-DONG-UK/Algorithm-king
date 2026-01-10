#include <iostream>
#include <vector>
using namespace std;

const long long fact[21] = {
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600,
	6227020800,
	87178291200,
	1307674368000,
	20922789888000,
	355687428096000,
	6402373705728000,
	121645100408832000,
	2432902008176640000
};

int N, mode;
long long k;
int path[21];
vector<int> numbers;
int arr[21];

void init();
void go(int depth, long long left, long long right);
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
	for (int i = 1; i <= N; i++) {
		numbers.push_back(i);
	}
	cin >> mode;
	if (mode == 1) {
		cin >> k;
	}
	else {
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
	}
	
}

void solve() {
	int depth = 1;
	long long left = fact[0];
	long long right = fact[N];

	while (depth <= N) {
		long long l = left - 1;
		long long r;

		for (int j = 1; j <= N - depth + 1; j++) {
			l += 1;
			r = left - 1 + j * fact[N - depth];

			if (mode == 1) {
				if (l <= k && k <= r) {
					//i번째 수를 선택하고 다음 depth로 넘어감
					path[depth] = numbers[j - 1];
					numbers.erase(numbers.begin() + j - 1);

					left = l; right = r; depth++;
					break;
				}
			}
			else {
				if (numbers[j - 1] == arr[depth]) {
					numbers.erase(numbers.begin() + j - 1);

					left = l; right = r; depth++;
					break;
				}
			}

			l = r;

		}
	}

	if (mode == 1) {
		for (int i = 1; i <= N; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
	}
	else {
		cout << left << '\n';
	}
}