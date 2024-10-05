#include <iostream>
using namespace std;

int N;
int D[100001][2];

void input();
void solve();


int main(){
    input();
    solve();
    
    cout << (D[N][0] + D[N][1]) % 9901 << '\n';
}

void input(){
    cin >> N;
}

void solve(){
    D[1][0] = 1;
    D[1][1] = 2;
    
    for(int i=2; i<=N; i++){
        D[i][0] = (D[i-1][0] + D[i-1][1]) % 9901;
        D[i][1] = (D[i-1][1] + D[i-1][0] * 2) % 9901;
    }
}
