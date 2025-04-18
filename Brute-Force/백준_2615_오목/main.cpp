#include <iostream>
using namespace std;

// 오른쪽 위, 오른쪽, 오른쪽 아래, 아래
int dy[4] = { -1, 0, 1, 1 };
int dx[4] = { 1, 1, 1, 0 };

int MAP[19][19];
int ans_dol;
int ans_y;
int ans_x;

void input();
void simulation();
int check(int y, int x, int dir);

int main(){
    input();
    simulation();
    
    if(ans_dol == 0) cout << ans_dol << '\n';
    else{
        cout << ans_dol << '\n';
        cout << ans_y + 1 << ' ' << ans_x + 1 << '\n';
    }
    
}

void input(){
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin >> MAP[i][j];
        }
    }
}

void simulation(){
    for(int j=0; j<19; j++){
        for(int i=0; i<19; i++){
            if(MAP[i][j] == 0) continue;
            
            for(int d=0; d<4; d++){
                if(check(i, j, d) == 5) {
                    ans_dol = MAP[i][j]; ans_y = i; ans_x = j;
                    return;
                }
            }
        }
    }
}

int check(int y, int x, int dir){
    int cnt = 1;
    
    int cy = y;
    int cx = x;
    int ny, nx;
    
    // 정방향 검사
    while(1){
        ny = cy + dy[dir];
        nx = cx + dx[dir];
        if(ny < 0 || ny >= 19 || nx < 0 || nx >= 19) break;
        if(MAP[ny][nx] != MAP[y][x]) break;
        
        cy = ny; cx = nx;
        cnt++;
    }
    cy = y; cx = x;
    // 역방향 검사
    while(1){
        ny = cy - dy[dir];
        nx = cx - dx[dir];
        if(ny < 0 || ny >= 19 || nx < 0 || nx >= 19) break;
        if(MAP[ny][nx] != MAP[y][x]) break;
        
        cy = ny; cx = nx;
        cnt++;
    }
    return cnt;
}
