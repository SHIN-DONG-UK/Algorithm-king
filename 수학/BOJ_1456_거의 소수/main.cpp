#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

using u64 = unsigned long long;

u64 A, B;
bool is_prime[10000005];
vector<u64> prime_numbers;
int cnt;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << cnt << '\n';

	return 0;
}

void init() {
	cin >> A >> B;

	u64 e = sqrt(B) + 1;
	
	for (int i = 1; i < e; i++) {
		is_prime[i] = true;
	}

	for (int i = 2; i < e; i++) {
		if (!is_prime[i]) continue;
		
		prime_numbers.push_back(i);

		for (int j = 2 * i; j < e; j += i) {
			is_prime[j] = false;
		}
	}
}

void solve() {
	for (u64& pnum : prime_numbers) {
		u64 tmp = pnum;

		while (tmp <= B / pnum) {
			tmp *= pnum;
			if (tmp >= A) cnt++;
		}
	}
}