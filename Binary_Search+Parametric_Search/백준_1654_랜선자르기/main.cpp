#include <iostream>
using namespace std;

int K,N;
int LANS[10000];
long long _left, _right;
long long max_val;

void input();
void BinarySearch();

int main(){
    input();
    BinarySearch();
    cout << max_val << '\n';
}

void input()
{
    cin >> K >> N;
    for(int i=0; i<K; i++){
        int tmp;
        cin >> tmp;
        if(tmp > _right) _right = tmp;
        LANS[i] = tmp;
    }
}

void BinarySearch()
{
    // 1. over flow
    // 2. mid == 0이 되는 경우
    long long mid;
    
    while(_left <= _right){
        mid = (_left + _right) / 2;
        if(mid == 0) mid = 1;
        
        //cout << "mid : " << mid << '\n';
        int num = 0;
        for(int i=0; i<K; i++){
            num += LANS[i] / mid;
        }
        if(num < N) _right = mid - 1;
        else {
            if(mid > max_val) max_val = mid;
            _left = mid + 1;
        }
    }
}