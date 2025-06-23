#include <iostream>
using namespace std;
using ull = unsigned long long;

ull A, B, C;

ull pow(ull A, ull B, ull C);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> A >> B >> C;
	
	ull ans = pow(A, B, C);

	cout << ans << '\n';

	return 0;
}

ull pow(ull A, ull B, ull C) {
	if (B == 1) 
		return A % C;

	ull tmp = pow(A, B / 2, C) % C;

	if (B % 2 == 0)
		return (tmp * tmp) % C;
	else
		return ((tmp * tmp) % C * A % C) % C;
}