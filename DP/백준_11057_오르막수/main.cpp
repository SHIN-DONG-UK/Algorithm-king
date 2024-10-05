#include <iostream>
using namespace std;

int N;
int S[11];

void input();
void init();
void sum();

int main(){
    
    init();
    input();
    for(int i=1; i<N; i++){
        sum();
    }
    
    cout << S[10] << '\n';
}

void init(){
    for(int i=1; i<=10; i++){
        S[i] = i;
    }
}
void sum(){
    int rst = 0;
    
    for(int i=1; i<=10; i++){
        rst += S[i];
        S[i] = rst % 10007;
    }
}

void input(){
    cin >> N;
}
