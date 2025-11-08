#include <iostream>
#include <cstring>
using namespace std;

int N;
char word[51];
int cnt;

// trie
const int ROOT = 1;
int unused = 2;
const int MX = 50 * 50 + 5; // 최대 50개 단어 && 최대 길이 50
bool chk[MX];
int nxt[MX][26];
void insert(char* w);

void init();
void traversal(int cur);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	traversal(ROOT);

	cout << cnt << "\n";

	return 0;
}

void init() {
	for (int i = 0; i < MX; i++) {
		memset(nxt[i], -1, sizeof(int) * 26);
	}

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word;
		insert(word);
	}
}

void insert(char* w) {
	int cur = ROOT;
	
	int i = 0;
	while (w[i] > 0) {
		int idx = w[i] - 'a';
		if (nxt[cur][idx] == -1) {
			nxt[cur][idx] = unused++;
		}
		cur = nxt[cur][idx];

		i++;
	}
	chk[cur] = true;
}

void traversal(int cur) {
	bool flag = false;

	for (int i = 0; i < 26; i++) {
		if (nxt[cur][i] == -1)
			continue;
		flag = true;
		traversal(nxt[cur][i]);
	}

	// leaf
	if (!flag) {
		cnt++;
		return;
	}
}