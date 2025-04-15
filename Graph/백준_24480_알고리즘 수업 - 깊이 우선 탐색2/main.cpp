#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
vector<int> graph[100001];
int visited[100001];
int cnt = 1;

void input();
void dfs(int now);

int main() {
  input();

  visited[R] = 1;
  dfs(R);

  for (int i = 1; i <= N; i++)
  {
    cout << visited[i] << '\n';
  }
}

void input() {
  cin >> N >> M >> R;
  int from, to;
  for (int i = 0; i < M; i++)
  {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  for (int i = 1; i <= N; i++)
  {
    sort(graph[i].begin(), graph[i].end(), greater<int>());
  }
}

void dfs(int now) {
  for (int i = 0; i < graph[now].size(); i++)
  {
    int next = graph[now][i];
    if (visited[next] > 0) continue;
    
    cnt++;
    visited[next] = cnt;
    dfs(next);
  }
}