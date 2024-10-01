#include <iostream>
using namespace std;

int N, M;
int a[9];

void input();
void go(int idx, int start);

int main(){
    input();
    go(0,0);
}

void input(){
    cin >> N >> M;
}

void go(int idx, int start){
    if(idx == M){
        for(int i=0; i<M; i++){
            cout << a[i] + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=start; i<N; i++){
        a[idx] = i;
        go(idx + 1, i);
    }
}
