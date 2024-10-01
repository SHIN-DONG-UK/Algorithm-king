#include <iostream>
#include <queue>
using namespace std;

struct Point{
    int y;
    int x;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int N,M;
int MAP[500][500];
int visited[500][500];
int ans, max_val;

void input();
void simulation();
void bfs(Point sp);

int main(){
    input();
    simulation();
    cout << ans << '\n';
    cout << max_val << '\n';
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
}

void bfs(Point sp){
    queue<Point> q;
    q.push(sp);
    visited[sp.y][sp.x] = 1;
    
    int cnt = 0;
    Point cp, np;
    while(!q.empty()){
        cnt++;
        cp = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            np = {cp.y + dy[d], cp.x + dx[d]};
            if(np.y < 0 || np.y >= N || np.x < 0 || np.x >= M) continue;
            if(visited[np.y][np.x] == 1) continue;
            if(MAP[np.y][np.x] == 1){
                visited[np.y][np.x] = 1;
                q.push(np);
            }
        }
    }
    if(cnt > max_val) max_val = cnt;
}

void simulation(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == 1 && visited[i][j] == 0){
                bfs({i, j});
                ans++;
            }
        }
    }
}
