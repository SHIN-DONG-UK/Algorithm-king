#include <iostream>
using namespace std;

int N, L;
int pos[1001];
int ans;

void input();
void solve();

int main(){
    input();
    solve();
    
    cout << ans << '\n';
}

void input(){
    cin >> N >>L;
    int p;
    for(int i=0; i<N; i++){
        cin >> p;
        pos[p] = 1;
    }
}

void solve(){
    for(int i=1; i<=1000; i++){
        if(pos[i] == 1){
            ans++;
            for(int j=i; j<i+L; j++){
                if(j > 1000) break;
                pos[j] = 0;
            }
        }
    }
}
