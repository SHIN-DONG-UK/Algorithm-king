#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
vector<int> graph[101];
int visited[101];
int min_val = 1e9;
int min_node = -1;

void input();
void bfs(int start);
void simulation();

int main(){
    input();
    simulation();
    cout << min_node << '\n';
}

void input(){
    cin >> N >> M;
    int from, to;

    for(int i=0; i<M; i++){
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    
    int now, next;
    while(!q.empty()){
        now = q.front();
        q.pop();
        
        for(int i=0; i<graph[now].size(); i++){
            next = graph[now][i];
            if(visited[next] > 0) continue;
            visited[next] = visited[now] + 1;
            q.push(next);
        }
    }
                      
}

void simulation(){
    for(int node = 1; node <= N; node++){
        memset(visited, 0, sizeof(visited));
        bfs(node);
        
        int sum = 0;
        for(int i=1; i<=N; i++){
            sum += visited[i];
        }
        sum -= N;
        if(min_val > sum){
            min_val = sum;
            min_node = node;
        }
    }
}
