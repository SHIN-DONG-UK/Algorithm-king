#include <iostream>
using namespace std;

struct Point{
    int y;
    int x;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int M, N;
char MAP[1001][1001];
int visited[1001][1001];
Point np;
int flag;

void input();
void simulation();
void dfs(Point cp);

int main(){
    input();
    simulation();
    
    if(flag == 1) cout << "YES\n";
    else cout << "NO\n";
    
}

void input(){
    cin >> M >> N;
    for(int i=0; i<M; i++){
        cin >> MAP[i];
    }
}

void simulation(){
    for(int i=0; i<N; i++){
        if(visited[0][i] == 1) continue;
        if(MAP[0][i] == '1') continue;
        dfs({0, i});
        
        if(flag == 1)
            break;
    }
}

void dfs(Point cp){
    for(int d=0; d<4; d++){
        np = {cp.y + dy[d], cp.x + dx[d]};
        if(np.y < 0 || np.y >= M || np.x < 0 || np.x >= N) continue;
        if(MAP[np.y][np.x] == '1') continue;
        if(visited[np.y][np.x] == 1) continue;
        
        visited[np.y][np.x] = 1;
        if(np.y == M-1)
            flag = 1;
        dfs(np);
    }
}
