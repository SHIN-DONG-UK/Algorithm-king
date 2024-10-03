#include <iostream>
using namespace std;

int N, M;
int arr[10000];
int ans;

void input();
void simulation();
int getSum(int);

int main(){
    input();
    simulation();
    
    cout << ans << '\n';
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
}

void simulation(){
    int sum = 0;
    
    for(int l=1; l<=N; l++){
        sum = getSum(l);
        if(sum == M) ans++;
        
        for(int i=0; i<N-l; i++){
            sum = sum - arr[i] + arr[i+l];
            if(sum == M) ans++;
        }
    }
}

int getSum(int length){
    int sum = 0;
    for(int i=0; i<length; i++){
        sum += arr[i];
    }
    return sum;
}
