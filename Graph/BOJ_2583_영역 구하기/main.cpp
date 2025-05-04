#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point{
    int y;
    int x;
};

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int N, M, K;
int MAP[100][100];
vector<int> ans;

void input();
void bfs(Point sp);
void simulation();
//void output();

int main(){
    input();
    simulation();
    
    sort(ans.begin(), ans.end());
    
    cout << ans.size() << '\n';
    for (int num : ans) {
        cout << num << ' ';
    }
    cout << '\n';
}

void input(){
    cin >> N >> M >> K;
    
    for(int i=0; i<K; i++){
        int a,b,c,d;
        cin >>a>>b>>c>>d;
        for(int x=a; x<c; x++){
            for(int y=b; y<d; y++){
                MAP[y][x] = 1;
            }
        }
    }
    
}

void bfs(Point sp){
    queue<Point> q;
    q.push(sp);
    MAP[sp.y][sp.x] = 1;
    
    int cnt = 0;
    Point cp, np;
    
    while(!q.empty()){
        cnt++;
        
        cp = q.front();
        q.pop();
        
        for(int d=0; d<4; d++){
            np = {cp.y + dy[d], cp.x + dx[d]};
            if(np.y < 0 || np.y >= N || np.x < 0 || np.x >=M) continue;
            if(MAP[np.y][np.x] == 1) continue;
            MAP[np.y][np.x] = 1;
            q.push(np);
        }
    }
    
    ans.push_back(cnt);
}

void simulation(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //output();
            
            if(MAP[i][j] == 0){
                bfs({i, j});
            }
        }
    }
}
/*
void output(){
    cout << '\n';
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << MAP[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
*/
