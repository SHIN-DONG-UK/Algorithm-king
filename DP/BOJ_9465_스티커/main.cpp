#include <iostream>
#include <cstring>
using namespace std;

int N;
int A[2][100001];
int D[2][100001];

void init();
void input();
void solve();

int main(){
    int T;
    cin >>T;
    for(int tc=1; tc<=T; tc++){
        input();
        solve();
        
        cout << max(D[0][N], D[1][N]) << '\n';
    }
}

void init(){
    memset(D, 0, sizeof(D));
}

void input(){
    cin >> N;
    for(int i=0; i<2; i++){
        for(int j=1; j<=N; j++){
            cin >> A[i][j];
        }
    }
}

void solve(){
    D[0][1] = A[0][1];
    D[1][1] = A[1][1];
    
    for(int i=2; i<=N; i++){
        D[0][i] = max(D[0][i-2], max(D[1][i-2], D[1][i-1])) + A[0][i];
        D[1][i] = max(D[0][i-2], max(D[1][i-2], D[0][i-1])) + A[1][i];
    }
    
}
