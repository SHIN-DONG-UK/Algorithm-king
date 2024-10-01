#include <iostream>
using namespace std;

int N, M;
int a[8];

void input();
void go(int idx);

int main(){
    input();
    go(0);
}

void input(){
    cin >> N >> M;
}

void go(int idx){
    if(idx == M){
        for(int i=0; i<M; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=1; i<=N; i++){
        a[idx] = i;
        go(idx + 1);
    }
}
