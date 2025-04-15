#include <iostream>
#include <algorithm>
using namespace std;

struct Person {
	int paper;
	int interview;
};

int T;
int N;
Person persons[100000];
int ans;

void input();
void solve();

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		input();
		solve();

		cout << ans << '\n';
	}
	
}

bool compare(Person a, Person b) {
	return a.paper < b.paper;
}

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> persons[i].paper;
		cin >> persons[i].interview;
	}
	
	sort(persons, persons + N, compare);
	
}

void solve() {
	int now = persons[0].interview;
	ans++;

	for (int i = 1; i < N; i++) {
		if (persons[i].interview < now) {
			now = persons[i].interview;
			ans++;
		}
	}
}