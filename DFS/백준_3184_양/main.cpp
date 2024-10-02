#include <iostream>
using namespace std;

struct Point {
  int y;
  int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int R, C;
char MAP[251][251];
int visited[251][251];
int sheep, wolf;
int tmp_sheep, tmp_wolf;
Point np;

void input();
void simulation();
void dfs(Point cp);

int main() {
  input();
  simulation();
  cout << sheep << ' ' << wolf << '\n';
}
void input() {
  cin >> R >> C;
  for (int i = 0; i < R; i++)
  {
    cin >> MAP[i];
  }
}

void simulation() {
  for (int i = 0; i < R; i++)
  {
    for (int j = 0; j < C; j++) {
      if (visited[i][j] == 1) continue;
      if (MAP[i][j] == '#') continue;

      tmp_sheep = 0; tmp_wolf = 0;
      visited[i][j] = 1;
      
      if (MAP[i][j] == 'o') tmp_sheep++;
      else if (MAP[i][j] == 'v') tmp_wolf++;
      dfs({i, j});

      if (tmp_sheep > tmp_wolf) sheep += tmp_sheep;
      else wolf += tmp_wolf;
    }
  }
}
void dfs(Point cp) {
  for (int d = 0; d < 4; d++) {
    np = { cp.y + dy[d], cp.x + dx[d] };
    if (np.y < 0 || np.y >= R || np.x < 0 || np.x >= C) continue;
    if (visited[np.y][np.x] == 1) continue;
    if (MAP[np.y][np.x] == '#') continue;

    visited[np.y][np.x] = 1;
    if (MAP[np.y][np.x] == 'o') tmp_sheep++;
    else if (MAP[np.y][np.x] == 'v') tmp_wolf++;
    dfs(np);
  }
}