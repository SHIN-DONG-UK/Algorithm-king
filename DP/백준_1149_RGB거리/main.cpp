#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000][3];
int D[1000][3];

void input();
void solve();

int main(){
    input();
    solve();
    
    cout << min(D[N-1][0], min(D[N-1][1], D[N-1][2])) << '\n';
}

void input(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> A[i][j];
        }
    }
}

void solve(){
    for(int j=0; j<3; j++){
        D[0][j] = A[0][j];
    }
    
    for(int i=1; i<N; i++){
        D[i][0] = A[i][0] + min(D[i-1][1], D[i-1][2]);
        D[i][1] = A[i][1] + min(D[i-1][0], D[i-1][2]);
        D[i][2] = A[i][2] + min(D[i-1][0], D[i-1][1]);
    }
}
