#include <iostream>
#include <string>
using namespace std;

double sum1, sum2;
string name, cgrade;

double point, grade;

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
	for (int i = 0; i < 20; i++) {
		cin >> name >> point >> cgrade;

		if (cgrade == "P") continue; 

		sum1 += point;

		if (cgrade == "A+") { sum2 += point * 4.5; }
		else if (cgrade == "A0") { sum2 += point * 4.0; }
		else if (cgrade == "B+") { sum2 += point * 3.5; }
		else if (cgrade == "B0") { sum2 += point * 3.0; }
		else if (cgrade == "C+") { sum2 += point * 2.5; }
		else if (cgrade == "C0") { sum2 += point * 2.0; }
		else if (cgrade == "D+") { sum2 += point * 1.5; }
		else if (cgrade == "D0") { sum2 += point * 1.0; }
	}
}

void solve() {
	cout << sum2 / sum1 << '\n';
}