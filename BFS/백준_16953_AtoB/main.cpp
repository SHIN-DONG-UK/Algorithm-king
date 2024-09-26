#include <iostream>
#include <queue>
using namespace std;

int A, B;
int ans;

void input();
bool bfs();

int main() {
	input();
	if (bfs()) cout << ans + 2 << '\n';
	else cout << "-1\n";
}

void input() {
	cin >> A >> B;
}

bool bfs() {
	queue<int> q;
	q.push(A);
	
	long long now;
	long long op1, op2;
	int len;

	while (!q.empty()) {
		len = q.size();
		
		for (int i = 0; i < len; i++)
		{
			now = q.front();
			q.pop();

			op1 = now * 2;
			op2 = now * 10 + 1;

			if (op1 == B || op2 == B) return true;

			// overflow 고려
			if (op1 < 1e9) q.push(op1);
			if (op2 < 1e9) q.push(op2);
		}

		ans++;
	}

 	return false;
}