#include <iostream>
using namespace std;

struct Point {
  int y;
  int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int N, M;
char MAP[101][101];
int visited[101][101];
int W_Power, B_Power;
int cnt;
Point np;

void input();
void simulation();
void dfs(Point cp, char color);
void output();

int main() {
  input();
  simulation();

  cout << W_Power << ' ' << B_Power << '\n';
}

void input() {
  cin >> M >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> MAP[i];
  }
}

void simulation() {
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (visited[i][j] == 1) continue;
      cnt = 1;
      visited[i][j] = 1;
      dfs({ i,j }, MAP[i][j]);

      if (MAP[i][j] == 'W') W_Power += cnt * cnt;
      else B_Power += cnt * cnt;
    }
  }
}

void dfs(Point cp, char color) {
  for (int d = 0; d < 4; d++)
  {
    np = { cp.y + dy[d], cp.x + dx[d] };
    if (np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
    if (visited[np.y][np.x] == 1) continue;
    if (MAP[np.y][np.x] != color) continue;

    cnt++;
    visited[np.y][np.x] = 1;
    dfs(np, color);
  }
}

void output() {
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cout << MAP[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << '\n';
}