#include <iostream>
using namespace std;

int DAT[10001];

int d(int n);
void simulation();

int main(){
    simulation();
    for(int num=1; num<=10000; num++){
        if(DAT[num] == 0) cout << num << '\n';
    }
}

int d(int n){
    int num = n;
    int divider = 10;
    int rst = 0;
    
    while(num != 0){
        rst += num % divider;
        num = num / divider;
    }
    
    return n + rst;
}

void simulation(){
    int tmp;
    for(int n = 1; n <= 10000; n++){
        tmp = d(n);
        if(tmp <= 10000) DAT[tmp]++;
    }
}
