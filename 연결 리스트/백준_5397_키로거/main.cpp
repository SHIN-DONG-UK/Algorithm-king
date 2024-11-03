#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	int T;	
	cin >> T;
	
	while (T--) {
		string init;
		cin >> init;
		
		list<char> L;
		auto cursor = L.begin();
		
		for (auto s : init) {
			if (s == '<') {
				if (cursor != L.begin())
					cursor--;
			}
			else if (s == '>') {
				if (cursor != L.end())
					cursor++;
			}
			else if (s == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else
				L.insert(cursor, s);
		}

		for (auto s : L)
			cout << s;
		cout << '\n';

	}
}