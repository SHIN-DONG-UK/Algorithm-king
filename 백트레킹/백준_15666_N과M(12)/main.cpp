#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M;
int a[8];
int visited[8];
int visited2[8][10001];
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
    sort(nums, nums + N);
}

void go(int idx, int start){
    if(idx == M) {
        for(int i=0; i<M; i++){
            cout << nums[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=start; i<N; i++){
        if(visited2[idx][nums[i]] == 1) continue;
        visited2[idx][nums[i]] = 1;
        a[idx] = i;
        go(idx+1, i);
    }
    memset(visited2[idx], 0, sizeof(visited2[idx]));
}
