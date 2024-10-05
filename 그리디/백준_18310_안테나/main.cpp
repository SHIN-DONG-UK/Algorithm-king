#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[200000];
int ans;

void input();
void solve();

int main(){
    input();
    solve();
    
    cout << ans << '\n';
}

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
}

void solve(){
    ans = arr[(N-1)/2];
    
}
