#include <iostream>
#include <cmath>
using namespace std;

int N;
int ans;

void input();
void simulation();
int how(int cnt);
int sub(int num, int k);

int main(){
    input();
    simulation();
    
    cout << ans << '\n';
}

void input(){
    cin >> N;
}

void simulation(){
    int cnt = 0;
    int ord = 0;
    int add, k, six;
    
    while(true){
        add = cnt * 1000;
        k = how(cnt);
        ans = 666 + add;
        
        if(k == 0){
            ord++;
            if(ord == N) return;
        }
        else{
            six = sub(ans, k);
            ans -= six+1;
            
            for(int i=0; i<pow(10, k); i++){
                ans++;
                ord++;
                if(ord == N) return;
            }
        }
        cnt++;
    }
}

int how(int cnt){
    int num = cnt;
    int rst = 0;
    int val;
    while(num != 0){
        val = num % 10;
        num = num / 10;
        if(val != 6) return rst;
        rst++;
    }
    return rst;
}

int sub(int num, int k){
    int rst = 0;
    int i = 0;
    int ten = 1;
    
    while(i < k){
        rst += 6*ten;
        
        i++;
        ten *= 10;
    }
    return rst;
}
