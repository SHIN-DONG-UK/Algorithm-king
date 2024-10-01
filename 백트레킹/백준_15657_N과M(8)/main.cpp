#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int path[8];
int nums[8];

void input();
void go(int idx, int start);

int main(){
    input();
    go(0, 0);
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }
    sort(nums, nums+N);
}

void go(int idx, int start){
    if(idx == M){
        for(int i=0; i<M; i++){
            cout << nums[path[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=start; i<N; i++){
        path[idx] = i;
        go(idx + 1, i);
    }
}
