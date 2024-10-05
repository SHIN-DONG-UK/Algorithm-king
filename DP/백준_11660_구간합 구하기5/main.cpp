#include <iostream>
using namespace std;

int N, M;
int MAP[1025][1025];
int table[1025][1025];

void input();
void solve();

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    input();
    solve();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> MAP[i][j];
        }
    }
        
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            table[i][j] = table[i-1][j] + table[i][j-1] + MAP[i][j] - table[i-1][j-1];
        }
    }
}

void solve(){
    int x1, y1, x2, y2;
    
    for(int i=0; i<M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        
        if(x1 == 1 && y1 == 1) cout << table[x2][y2] << '\n';
        else if(x1 == x2 && y1 == y2) cout << MAP[x1][y1] << '\n';
        else cout << table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1] << '\n';
    }
}
