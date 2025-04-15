#include <iostream>
using namespace std;

int N;
int score[301];
int dp[301];

void input();
void solve();
void output();

int main(){
    input();
    solve();
    //output();
    cout << dp[N] << '\n';
}

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> score[i];
    }
}

void solve(){
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    
    for(int i=3; i<=N; i++){
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }
}

void output(){
    for(int i=0; i<=N; i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}
