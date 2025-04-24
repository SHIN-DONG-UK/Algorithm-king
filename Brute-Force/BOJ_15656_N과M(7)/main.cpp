#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[8];
int nums[8];

void input();
void go(int idx);

int main(){
    input();
    go(0);
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    sort(nums, nums + N);
}

void go(int idx){
    if(idx==M){
        for(int i=0; i<M; i++){
            cout << nums[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=0; i<N; i++){
        a[idx] = i;
        go(idx + 1);
    }
}

