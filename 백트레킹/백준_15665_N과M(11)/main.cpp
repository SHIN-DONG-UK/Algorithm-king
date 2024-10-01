#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int path[7];
int nums[7];
int visited[7][10001];

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
    if(idx == M){
        
        for(int i=0; i<M; i++){
            cout << nums[path[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=0; i<N; i++){
        if(visited[idx][nums[i]] == 1) continue;
        visited[idx][nums[i]] = 1;
        path[idx] = i;
        go(idx + 1);
    }
    
    memset(visited[idx], 0, sizeof(visited[idx]));
}
