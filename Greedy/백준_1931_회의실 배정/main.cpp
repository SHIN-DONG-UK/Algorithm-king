#include <iostream>
#include <algorithm>
using namespace std;

struct Meeting{
    int start;
    int end;
};

int N;
Meeting meetings[100000];
int ans;

void input();
void simulation();

int main(){
    input();
    simulation();
    
    cout << ans << '\n';
}

bool compare(Meeting a, Meeting b){
    if(a.end == b.end){
        return a.start < b.start;
    }
    return a.end < b.end;
}

void input(){
    cin >> N;
    int start, end;
    
    for(int i=0; i<N; i++){
        cin >> start >> end;
        meetings[i] = {start, end};
    }
    
    sort(meetings, meetings + N, compare);
}

void simulation() {
    int time = meetings[0].end;
    ans = 1;
    
    for(int i=1; i<N; i++){
        if(meetings[i].start >= time){
            ans++;
            time = meetings[i].end;
        }
    }
    
}
