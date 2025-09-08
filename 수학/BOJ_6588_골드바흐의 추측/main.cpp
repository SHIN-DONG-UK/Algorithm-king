//BOJ_6588_골드바흐의 추측_실버1

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MX = 1000001;
bool is_prime[MX];
vector<int> primes;

void eratosthenes() {
	for (int i = 1; i < MX; i++) {
		is_prime[i] = true;
	}
	is_prime[1] = false;

	for (int i = 2; i <= sqrt(MX); i++) {
		if (!is_prime[i]) continue;
		for (int j = 2; i * j < MX; j++) {
			is_prime[i * j] = false;
		}
	}
}

void get_vector() {
	for (int i = 1; i < MX; i++) {
		if (is_prime[i]) primes.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	eratosthenes();

	get_vector();

	int n;
	while (1) {
		cin >> n;
		if (n == 0)
			return 0;

		int limit = n;

		int l = 0; int r = primes.size();

		int mid;
		while (l <= r) {
			mid = (l + r) / 2;

			if (n / 2 < primes[mid]) {
				r = mid - 1;
			}
			else {
				limit = mid;
				l = mid + 1;
			}
		}

		bool flag = false;
		for (int i = 1; i <= limit; i++) {
			int b = n - primes[i];
			if (is_prime[b]) {
				cout << n << " = " << primes[i] << " + " << b << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	

	return 0;
}