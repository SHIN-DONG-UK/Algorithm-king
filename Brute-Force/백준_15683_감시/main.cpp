#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 8
using namespace std;

struct Point{
    int y;
    int x;
};

// 상우하좌
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int N, M;
int map[MAX+2][MAX+2];
int cctv_map[MAX+2][MAX+2];
vector<Point> cctvs;
int ans = 1e9;

// 중복순열
int CNT;
int order[MAX];

// cctv 번호에 따른 가능한 방향 배열
vector<int> numAnddirTodir[6][4];

void Init();
void Input();
void Go(int idx);
void GetBlindspot();
void Print();

int main(){
    Init();
    Input();
    Go(0);
    
    cout << ans << '\n';
    return 0;
}

void Init(){
    // 1번 카메라
    for(int d=0; d<4; d++)
        numAnddirTodir[1][d].push_back(d);
    // 2번 카메라
    for(int d=0; d<4; d++){
        numAnddirTodir[2][d].push_back(d);
        numAnddirTodir[2][d].push_back((d+2)%4);
    }
    // 3번 카메라
    for(int d=0; d<4; d++){
        numAnddirTodir[3][d].push_back(d);
        numAnddirTodir[3][d].push_back((d+1)%4);
    }
    // 4번 카메라
    for(int d=0; d<4; d++){
        numAnddirTodir[4][d].push_back(d);
        numAnddirTodir[4][d].push_back((d-1+4)%4);
        numAnddirTodir[4][d].push_back((d+1)%4);
    }
    // 5번 카메라는 안돌려도 됨
    for(int d=0; d<4; d++){
        for(int dd=0; dd<4; dd++)
            numAnddirTodir[5][d].push_back(dd);
    }
}

void Input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            if(map[i][j] >= 1 && map[i][j] <= 5){
                cctvs.push_back({i, j});
            }
                
        }
    }
    // padding
    for(int i=0; i<N+2; i++){
        map[i][0] = -2;
        map[i][M+1] = -2;
    }
    for(int j=0; j<M+2; j++){
        map[0][j] = -2;
        map[N+1][j] = -2;
    }
}

void Go(int idx){
    if(idx == cctvs.size()){
        GetBlindspot();
        //Print();
        return;
    }
    
    for(int i=0; i<4; i++){
        order[idx] = i;
        Go(idx + 1);
    }
}

void GetBlindspot(){
    // map 복사
    for(int i=0; i<N+2; i++){
        for(int j=0; j<M+2; j++){
            cctv_map[i][j] = map[i][j];
        }
    }
    
    Point cp;
    // cctv 돌면서 가능한 영역 표시
    for(int i=0; i<cctvs.size(); i++){
        int d = order[i];
        int cctvNum = map[cctvs[i].y][cctvs[i].x];
        // 방향이 주어지면 해당 방향으로 표시
        for(int k=0; k<numAnddirTodir[cctvNum][d].size(); k++){
            // 해당 방향으로 직진
            cp = cctvs[i];
            int dir = numAnddirTodir[cctvNum][d][k];
            while(true){
                cp.y += dy[dir];
                cp.x += dx[dir];
                // 맵 밖 -> 해당 방향 종료
                if(map[cp.y][cp.x] == -2)
                    break;
                // 벽 -> 해당 방향 종료
                if(map[cp.y][cp.x] == 6)
                    break;
                // cctv 위치이면 그냥 덮어 써도 상관없음
                // 어차피 ccvts배열에 위치가 다 저장되어 있기 때문
                cctv_map[cp.y][cp.x] = -1;
            }
        }
        
    }
    int cnt = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(cctv_map[i][j] == 0)
                cnt++;
        }
    }
    
    ans = min(ans, cnt);
}

void Print(){
    cout << '\n';
    for(int i=0; i<N+2; i++){
        for(int j=0; j<M+2; j++)
            cout << cctv_map[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
