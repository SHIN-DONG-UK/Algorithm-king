#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10001];
int dp[10001];

void input();
void solve();
void output();

int main(){
    input();
    solve();
    
    cout << max(dp[N-2], max(dp[N-1], dp[N])) << '\n';
}

void input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> arr[i];
    }
}

void solve(){
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    
    for(int i=3; i<=N; i++){
        dp[i] = max(dp[i-1], max(dp[i-2] + arr[i], dp[i-3] + arr[i-1] + arr[i]));
    }
}
