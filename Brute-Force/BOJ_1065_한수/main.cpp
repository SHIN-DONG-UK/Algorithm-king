#include <iostream>
using namespace std;

int run(int n);
int ans;

int main(){
    int X;
    cin >> X;
    
    for(int num = 1; num <= X; num++){
        if(run(num) == 1) ans++;
    }
    
    cout << ans << '\n';
}

int run(int n){
    int num = n;
    
    int prev = num % 10;
    num = num / 10;
    
    int now = num % 10;
    num = num / 10;
    
    int diff = prev - now;
    prev = now;
    
    while(num != 0){
        
        now = num % 10;
        num = num / 10;
        
        if(diff != prev - now) return 0;
        
        diff = prev - now;
        prev = now;
    }
    return 1;
}
