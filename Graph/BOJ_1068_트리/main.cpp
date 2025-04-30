#include <iostream>
#include <vector>
using namespace std;


int N; // 노드 개수 (max : 50)
vector<int> tree[51]; // tree
int deleted;
int rootNum;

// 정답 카운트
int ansCnt;

void input();
void dfs(int lev);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	dfs(rootNum);

	cout << ansCnt << '\n';
	return 0;
}

void input() {
	cin >> N;
	int parent;
	for (int nodeNum = 0; nodeNum < N; nodeNum++)	{
		cin >> parent;
		if (parent != -1) tree[parent].push_back(nodeNum);
		else rootNum = nodeNum;
	}
	// 삭제할 노드
	cin >> deleted;

}

void dfs(int nodeNum) {
	if (nodeNum == deleted) return;
	if (tree[nodeNum].size() == 1 && tree[nodeNum][0] == deleted) { // 예외
		ansCnt++;
		return;
	}

	// 리프 노드 카운트
	if (tree[nodeNum].size() == 0) {
		ansCnt++;
		return;
	}

	for (auto num : tree[nodeNum]) dfs(num);
}