#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[500001];
int visited[500001];
int sum;

void input();
void solve();
void dfs(int now, int lev);

int main() {
  input();
  solve();

  if (sum % 2 == 0) cout << "No\n";
  else cout << "Yes\n";
}

void input() {
  cin >> N;
  
  int from, to;
  for (int i = 0; i < N - 1; i++) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
}

void dfs(int now, int lev) {
  for (int i = 0; i < graph[now].size(); i++) {
    int next = graph[now][i];
    if (visited[next] > 0) continue;

    visited[next] = lev + 1;
    dfs(next, lev + 1);
  }
}

void solve() {
  visited[1] = 1;
  dfs(1, 0);

  for (int i = 2; i <= N; i++) {
    if (graph[i].size() == 1) {
      sum += visited[i];
    }
  }
}