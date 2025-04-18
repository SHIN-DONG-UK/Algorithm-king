#include <iostream>
using namespace std;

int N, M, B;
int MAP[500][500];
int highest;
int lowest = 999;
int ans_h;
int ans_s = 1e9;

void input();
void simulation();
int isPossible(int target);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    input();
    simulation();
    
    cout << ans_s << ' ' << ans_h << '\n';
    
}

void input(){
    cin >> N >> M >> B;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
            if(lowest > MAP[i][j]) lowest = MAP[i][j];
            if(MAP[i][j] > highest) highest = MAP[i][j];
        }
    }
}

void simulation(){
    int val;
    for(int t=lowest; t<=highest; t++){
        val = isPossible(t);
        if(val < 0) continue;
        if(ans_s >= val) {
            ans_s = val;
            ans_h = t;
        }
    }
}

int isPossible(int target){
    int time = 0;
    int block = B;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == target) continue;
            
            if(MAP[i][j] > target) {
                time += 2*(MAP[i][j] - target);
                block += (MAP[i][j] - target);
            }
            else if(MAP[i][j] < target){
                time += (target - MAP[i][j]);
                block -= (target - MAP[i][j]);
            }
        }
    }
    if(block < 0) return -1;
    else return time;
}
