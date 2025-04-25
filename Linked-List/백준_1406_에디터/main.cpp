#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
	string init;
	list<char> L;

	cin >> init;
	for (auto s : init)
		L.push_back(s);

	auto cursor = L.end();

	int t;
	cin >> t;
	while (t--) {
		char op, ch;
		cin >> op;
		if (op == 'L') {
			if (cursor != L.begin())
				cursor--;
		}
		else if (op == 'D') {
			if (cursor != L.end())
				cursor++;
		}
		else if (op == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else if (op == 'P') {
			cin >> ch;
			cursor = L.insert(cursor, ch);
			cursor++;
		}
	}

	for (auto c : L)
		cout << c;
	return 0;
}