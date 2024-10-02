#include <iostream>
using namespace std;

struct Point {
  int y;
  int x;
};

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int MAP[5][5];
int nums[1000000];
int ans;
Point np;

void input();
void dfs(Point cp, int lev, int ten, int num);
void simulation();

int main() {
  input();
  simulation();
  
  for (int i = 0; i < 1000000; i++) {
    if (nums[i] > 0) ans++;
  }
  cout << ans << '\n';
}

void input() {
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      cin >> MAP[i][j];
    }
  }
}

void simulation() {
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++) {

      dfs({ i, j }, 0, 10, MAP[i][j]);
    }
  }
}

void dfs(Point cp, int lev, int ten, int num) {
  if (lev == 5) {
    //cout << num << '\n';
    nums[num]++;
    return;
  }

  for (int d = 0; d < 4; d++)
  {
    np = { cp.y + dy[d], cp.x + dx[d] };
    if (np.y < 0 || np.y >= 5 || np.x < 0 || np.x >= 5) continue;
    
    dfs(np, lev + 1, ten *10, num + (MAP[np.y][np.x] * ten));
  }
}