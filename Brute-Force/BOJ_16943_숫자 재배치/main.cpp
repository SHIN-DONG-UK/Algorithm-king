#include <iostream>
using namespace std;

int A, B;

int len_a;
int arr[10];
bool visited[10];
int path[10];

int max_ans;

void init();
void go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	go(0);

	cout << max_ans << '\n';

	return 0;
}

void init() {
	cin >> A >> B;

	int a = A;
	while (a > 0) {
		arr[++len_a] = a % 10;
		a /= 10;
	}
	
	max_ans = -1;
}

void go(int idx) {
	if (idx == len_a) {
		if (path[0] == 0) {
			return;
		}

		int tmp = 0;
		for (int i = 0; i < len_a; i++) {
			tmp *= 10;
			tmp += path[i];
		}

		if (tmp < B && tmp > max_ans)
			max_ans = tmp;

		return;
	}
	for (int i = 1; i <= len_a; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		path[idx] = arr[i];
		go(idx + 1);
		visited[i] = false;
	}
}