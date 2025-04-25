#include <iostream>
#include <list>
using namespace std;

int main() {
	int N, k;
	cin >> N >> k;

	list<int> L;
	for (int i = 1; i <= N; i++)
		L.push_back(i);
	auto cursor = L.begin();

	cout << '<';
	while (L.size()) {
		for (int i = 1; i < k; i++) {
			cursor++;
			if (cursor == L.end())
				cursor = L.begin();
		}
		if (L.size() == 1)
			cout << *cursor << ">\n";
		else
			cout << *cursor << ", ";
		cursor = L.erase(cursor);
		if (cursor == L.end())
			cursor = L.begin();
	}
}