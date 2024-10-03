#include <iostream>
using namespace std;

struct DeongChi{
    int x;
    int y;
};

int N;
DeongChi arr[50];
int ans[50];

void input();
void simulation();

int main(){
    input();
    simulation();
    
    for(int i=0; i<N; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

void input(){
    cin >> N;
    
    int x, y;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        arr[i] = {x, y};
    }
}

void simulation(){
    int cnt;
    for(int i=0; i<N; i++){
        cnt = 0;
        for(int j=0; j<N; j++){
            if(j == i) continue;
            if(arr[i].x < arr[j].x && arr[i].y < arr[j].y) cnt++;
        }
        ans[i] = cnt + 1;
    }
}
