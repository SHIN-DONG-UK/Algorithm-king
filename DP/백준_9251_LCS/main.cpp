#include <iostream>
#include <algorithm>
#include <string>

#define MAX_LEN 1001
using namespace std;

string s1, s2;
int LCS[MAX_LEN][MAX_LEN];

void Input();
void Solve();
void Output();

int main() {
	Input();
	Solve();
	Output();

	return 0;
}

void Input() {
	cin >> s1 >> s2;
}

void Solve() {
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			// 같을 때
			if (s1[i - 1] == s2[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else // 다를 때
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);

			
		}
	}
}

void Output() {
	cout << LCS[s1.length()][s2.length()] << '\n';
}