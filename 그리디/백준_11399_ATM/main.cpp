#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int arr[1000];
    int ans = 0;
    
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            ans += arr[j];
        }
    }
    
    cout << ans << '\n';
}
