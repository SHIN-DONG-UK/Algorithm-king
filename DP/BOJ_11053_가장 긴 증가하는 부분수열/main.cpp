#include <iostream>
using namespace std;

int N;
int arr[1000];
int dp[1000];
int ans;

void input();
void solve();
void output();

int main(){
    input();
    solve();
    
    for(int i=0; i<N; i++){
        if(dp[i] > ans) ans = dp[i];
    }
    
    //output();
    cout << ans << '\n';
}

void input(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void solve(){
    dp[0] = 1;
    int tmp;
    
    for(int i=1; i<N; i++){
        tmp = 0;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                if(dp[j] > tmp) tmp = dp[j];
            }
        }
        dp[i] = tmp + 1;
        
    }
}

void output(){
    cout << '\n';
    for(int i=0; i < N; i++){
        cout << dp[i] << ' ';
    }
    cout << '\n';
}
