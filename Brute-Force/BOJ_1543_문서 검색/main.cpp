#include <iostream>
#include <string>
using namespace std;

string docs; int d_size;
string word; int w_size;
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
	getline(cin, docs);
	getline(cin, word);

	d_size = docs.size();
	w_size = word.size();
}

void solve() {
	int i = 0;
	while (i < d_size) {
		bool flag = true;
		for (int j = 0; j < w_size; j++) {
			if (i + j >= d_size) return;

			if (docs[i + j] != word[j]) {
				flag = false;
				break;
			}
		}

		if (flag) {
			i += w_size;
			cnt++;
		}
		else {
			i++;
		}

	}
}