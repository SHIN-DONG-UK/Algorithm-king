#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int set_price = 1001;
int not_price = 1001;

void input();
void solve();
int ans;

int main(){
    input();
    solve();
    
    cout << ans << '\n';
}

void input(){
    cin >> N >> M;
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        if(set_price > a) set_price = a;
        if(not_price > b) not_price = b;
    }
}

void solve(){
    // 세트 + 낱개 조합으로 가장 싼 거 찾으면 됨
    // 일단 세트로 다사
    int cnt = N/6; // 세트 개수
    ans = cnt * set_price;
    
    if(N%6 != 0) {
        ans += set_price;
        cnt++;
    }
    
    int now = 6 * cnt; // 갖고있는 개수
    
    int tmp = ans; // 임시 비용
    
    for(int i=0; i<cnt; i++){
        now -= 6;
        tmp -= set_price;
        
        tmp += abs(now - N) * not_price;
        now += abs(now - N);
        
        if(ans > tmp) ans = tmp;
    }
}
