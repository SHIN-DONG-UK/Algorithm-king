#include <iostream>
using namespace std;

int N, K;
int coins[10];
int ans;

void input();
void simulation();

int main(){
    input();
    simulation();
    
    cout << ans << '\n';
}

void input(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> coins[i];
    }
}

void simulation(){
    for(int i=N-1; i>=0; i--){
        ans += K / coins[i];
        K = K % coins[i];
    }
}
