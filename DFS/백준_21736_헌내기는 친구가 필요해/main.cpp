#include <iostream>
using namespace std;

struct Point {
  int y;
  int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char MAP[601][601];
int visited[601][601];
Point Ip, np;
int cnt;

void getI();
void input();
void dfs(Point cp);

int main() {
  input();
  getI();

  visited[Ip.y][Ip.x] = 1;
  dfs(Ip);
  if (cnt > 0) cout << cnt << '\n';
  else cout << "TT\n";
}

void input() {
  cin >> N >> M;
  for (int i = 0; i < N; i++)
  {
    cin >> MAP[i];
  }
}

void getI() {
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++) {
      if (MAP[i][j] == 'I') {
        Ip = { i, j };
        return;
      }
    }
  }
}

void dfs(Point cp) {
  for (int d = 0; d < 4; d++)
  {
    np = { cp.y + dy[d], cp.x + dx[d] };
    if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
    if (visited[np.y][np.x] == 1) continue;
    if (MAP[np.y][np.x] == 'X') continue;
    
    visited[np.y][np.x] = 1;
    if (MAP[np.y][np.x] == 'P') cnt++;
    dfs(np);
  }
}