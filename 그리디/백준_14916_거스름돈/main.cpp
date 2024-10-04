#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = -1;

void input();
void solve();

int main(){
    input();
    solve();
    
    cout << ans << '\n';
    
}

void input(){
    cin >> n;
}

void solve(){
    // 1. 5원 올인
    int cnt = n / 5;
    
    if(n%5 != 0) cnt++;
    else {
        // 나누어 떨어지면 여기서 끝내
        // 이게 젤 최소임
        ans = cnt;
        return;
    }
    
    int now = 5 * cnt;
    int len = cnt;
    
    // 2. 5원 하나 빼고 2원이 가능한지 검사
    for(int i=0; i<len; i++){
        cnt -= 1;
        now -= 5;
        
        // 2원이 가능한 순간 끝내
        // 그게 최소야
        if(abs(n-now) % 2 == 0){
            cnt += abs(n-now) / 2;
            now = n;
            
            ans = cnt;
            return;
        }
    }
}
