#include <iostream>
using namespace std;

using u64 = unsigned long long;
u64 A, B;

u64 gcd(u64 a, u64 b);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> A >> B;
	if (A < B) swap(A, B);
	u64 cnt = gcd(A, B);
	for (u64 i = 0; i < cnt; i++) cout << '1';
	cout << '\n';
	return 0;
}

u64 gcd(u64 a, u64 b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}