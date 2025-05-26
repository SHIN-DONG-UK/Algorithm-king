#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int ry;
	int rx;
	int by;
	int bx;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char MAP[11][11];
int visited[11][11][11][11];
Node snode;
int ay, ax;
int ans = 1e9;

void input();
void bfs(Node);
Node move(Node, int);
void print(Node, int);

int main() {

	input();
	bfs(snode);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{	
			if (visited[ay][ax][i][j] != 0)
			{
				if (ans > visited[ay][ax][i][j]) ans = visited[ay][ax][i][j];
			}
		}
	}

	if (ans == 1e9) cout << "-1\n";
	else if (ans > 11) cout << "-1\n";
	else cout << ans - 1 << '\n';

	return 0;
}

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> MAP[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			if (MAP[i][j] == 'R') {
				snode.ry = i;
				snode.rx = j;
			}
			else if (MAP[i][j] == 'B') {
				snode.by = i;
				snode.bx = j;
			}
			else if (MAP[i][j] == 'O') {
				ay = i; ax = j;
			}

		}
	}
}

void bfs(Node snode) {
	queue<Node> q;
	q.push(snode);
	visited[snode.ry][snode.rx][snode.by][snode.bx] = 1;

	Node cnode, nnode;
	while (!q.empty()) {
		cnode = q.front();
		q.pop();
		//print(cnode, -1);

		for (int d = 0; d < 4; d++)
		{
			nnode = move(cnode, d);
			if (nnode.ry == -1) continue; // 실패
			if (visited[nnode.ry][nnode.rx][nnode.by][nnode.bx] > 0) continue;
			
			visited[nnode.ry][nnode.rx][nnode.by][nnode.bx] = visited[cnode.ry][cnode.rx][cnode.by][cnode.bx] + 1;
			if (MAP[nnode.ry][nnode.rx] == 'O') return;
			q.push(nnode);
		}
	}
}

Node move(Node node, int dir) {
	Node cnode = node;
	Node nnode;

	// b 선
	if ((dir == 0 && (node.ry > node.by)) 
		|| (dir == 1 && (node.ry < node.by))
		|| (dir == 2 && (node.rx > node.bx))
		|| (dir == 3 && (node.rx < node.bx))) {
		while (true) {
			//print(cnode, dir);

			nnode = { cnode.ry, cnode.rx, cnode.by + dy[dir], cnode.bx + dx[dir] };
			if (MAP[nnode.by][nnode.bx] == '#') break;
			if (MAP[nnode.by][nnode.bx] == 'O') return { -1,-1,-1,-1 }; // 실패
			cnode = nnode;
			
		}
		while (true) {
			//print(cnode, dir);

			nnode = { cnode.ry + dy[dir], cnode.rx + dx[dir], cnode.by, cnode.bx };
			if (MAP[nnode.ry][nnode.rx] == '#') break;
			if (nnode.ry == nnode.by && nnode.rx == nnode.bx) break;
			if (MAP[nnode.ry][nnode.rx] == 'O') return nnode;
			cnode = nnode;
		}
		return cnode;
	}
	// 위 경우가 아니면 r을 선해도 문제없거나 r선이어야만 함
	else {
		while (true) {
			//print(cnode, dir);
			if (MAP[cnode.ry][cnode.rx] == 'O') break;

			nnode = { cnode.ry + dy[dir], cnode.rx + dx[dir], cnode.by, cnode.bx };
			if (MAP[nnode.ry][nnode.rx] == '#') break;
			cnode = nnode;
		}
		while (true) {
			//print(cnode, dir);

			nnode = { cnode.ry, cnode.rx, cnode.by + dy[dir], cnode.bx + dx[dir] };
			if (MAP[nnode.by][nnode.bx] == '#') break;
			if (MAP[nnode.by][nnode.bx] == 'O') return { -1,-1,-1,-1 }; // 실패
			if (nnode.ry == nnode.by && nnode.rx == nnode.bx) break;
			
			cnode = nnode;
		}
		return cnode;
	}
}

void print(Node node, int dir) {
	cout << "dir : " << dir << '\n';
	cout << '\n';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == node.ry && j == node.rx) cout << "R ";
			else if (i == node.by && j == node.bx) cout << "B ";
			else cout << ". ";
		}
		cout << '\n';
	}
	cout << '\n';
}