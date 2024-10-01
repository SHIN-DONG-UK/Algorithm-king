#include <iostream>
#include <queue>
using namespace std;

struct Point{
    int y;
    int x;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int N, M;
int MAP[1000][1000];
int visited[1000][1000];
Point sp;

void input();
void bfs();
void output();

int main(){
    input();
    bfs();
    output();
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 2) sp = {i, j};
        }
    }
}

void bfs(){
    queue<Point> q;
    q.push(sp);
    visited[sp.y][sp.x] = 1;
    
    Point cp, np;
    while(!q.empty()){
        cp = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            np = {cp.y + dy[d], cp.x + dx[d]};
            if(np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
            if(visited[np.y][np.x] > 0) continue;
            if(MAP[np.y][np.x] == 1){
                visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
                q.push(np);
            }
        }
    }
}

void output(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j] == 0){
                if(MAP[i][j] == 1) cout << "-1 ";
                else cout << "0 ";
            }
            else cout << visited[i][j] - 1 << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
