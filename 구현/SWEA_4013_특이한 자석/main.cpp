#include <iostream>
#include <cstring>

#define MAX_K 20
using namespace std;

int K; // K개의 회전 명령
int magnetics[6][8]; // 1 ~ 4
int command_num[MAX_K]; //
int command_dir[MAX_K]; // 1 : 시계방향, -1 : 반시계방향
int visited[6];
int ans;

void Init();
void Input();
void Solve();
void Go(int num, int dir);
void ShiftArr(int num, int dir);
void Print();

int main(){
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        Init();
        Input();
        Solve();
        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}

void Init(){
    memset(visited, 0, sizeof(visited));
    ans = 0;
}

void Input(){
    cin >> K;
    for(int i=1; i<=4; i++){
        for(int j=0; j<8; j++){
            cin >> magnetics[i][j];
        }
    }
    
    for(int i=0; i<K; i++){
        cin >> command_num[i];
        cin >> command_dir[i];
    }
}

void Solve(){
    for(int i=0; i<K; i++){
        memset(visited, 0, sizeof(visited));
        Go(command_num[i], command_dir[i]);
    }
    
    int point = 1;
    // 점수 계산
    for(int i=1; i<=4; i++){
        if(magnetics[i][0])
            ans += point;
        point *= 2;
    }
        
}

void Go(int num, int dir){
    if(num <= 0 || num >= 5)
        return;
    
    if(visited[num-1] == 0){
        // 왼쪽 자석 검사
        if(magnetics[num][6] != magnetics[num-1][2]){
            visited[num] = 1;
            Go(num-1, dir * (-1));
        }
            
    }
    
    if(visited[num+1] == 0){
        // 오른쪽 자석 검사
        if(magnetics[num][2] != magnetics[num+1][6]){
            visited[num] = 1;
            Go(num+1, dir * (-1));
        }
    }
    
    // 회전 진행
    ShiftArr(num, dir);
}

void ShiftArr(int num, int dir){
    // dir == 1 -> 오른쪽
    if(dir == 1){
        int tmp = magnetics[num][7];
        for(int j=7; j>=1; j--)
            magnetics[num][j] = magnetics[num][j-1];
        magnetics[num][0] = tmp;
    }
    // dir == -1 -> 왼쪽
    else{
        int tmp = magnetics[num][0];
        for(int j=0; j < 8-1; j++)
            magnetics[num][j] = magnetics[num][j+1];
        magnetics[num][7] = tmp;
    }
    
}

void Print() {
    cout << '\n';
    for(int i=1; i<=4; i++){
        for(int j=0; j<8; j++)
            cout << magnetics[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
