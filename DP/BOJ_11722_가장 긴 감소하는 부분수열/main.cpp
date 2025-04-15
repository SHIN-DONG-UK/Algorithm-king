#include <iostream>
using namespace std;

int N;
int A[1000];
int D[1000];
int ans;

void input();
void solve();

int main(){
    input();
    solve();
    
    for(int i=0; i<N; i++){
        if(D[i] > ans) ans = D[i];
    }
    
    cout << ans << '\n';
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

void solve(){
    D[0] = 1;
    
    int tmp;
    for(int i=1; i<N; i++){
        tmp = 0;
        for(int j=i-1; j>=0; j--){
            if(A[j] > A[i]){
                if(D[j] > tmp) tmp = D[j];
            }
        }
        D[i] = tmp + 1;
    }
}
