#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int startNode, endNode;
int m;
vector<int> graph[101];
int visited[101];
int ans;

void input();
void bfs();

int main(){
    input();
    bfs();
    if(visited[endNode] == 0) cout << "-1\n";
    else cout << visited[endNode] - 1 << '\n';
}

void input(){
    cin >> n;
    cin >> startNode >> endNode;
    cin >> m;
    
    int from, to;
    for(int i=0; i<m; i++){
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
}

void bfs(){
    queue<int> q;
    q.push(startNode);
    visited[startNode] = 1;
    
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
