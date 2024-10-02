#include <iostream>
using namespace std;

int N,M;
char MAP[51][51];
int min_val = 1e9;

void input();
void simulation();

int main(){
    input();
    simulation();
    
    cout << min_val << '\n';
}

void input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> MAP[i];
    }
}

void simulation(){
    int cnt;
    
    for(int i=0; i <= N-8; i++){
        for(int j=0; j <= M-8; j++){
            cnt = 0;
            
            for(int a=i; a<i+8; a++){
                for(int b=j; b<j+8; b++){
                    if((i+j) % 2 == 0){
                        if((a+b) % 2 == 0 && MAP[i][j] != MAP[a][b]) cnt++;
                        else if((a+b) % 2 == 1 && MAP[i][j] == MAP[a][b]) cnt++;
                    }
                    else{
                        if((a+b) % 2 == 1 && MAP[i][j] != MAP[a][b]) cnt++;
                        else if((a+b) % 2 == 0 && MAP[i][j] == MAP[a][b]) cnt++;
                    }
                }
            }
            
            if(min_val > cnt) min_val = cnt;
            
            if(MAP[i][j] == 'B') MAP[i][j] = 'W';
            else MAP[i][j] = 'B';
            
            cnt = 1;
            
            for(int a=i; a<i+8; a++){
                for(int b=j; b<j+8; b++){
                    if((i+j) % 2 == 0){
                        if((a+b) % 2 == 0 && MAP[i][j] != MAP[a][b]) cnt++;
                        else if((a+b) % 2 == 1 && MAP[i][j] == MAP[a][b]) cnt++;
                    }
                    else{
                        if((a+b) % 2 == 1 && MAP[i][j] != MAP[a][b]) cnt++;
                        else if((a+b) % 2 == 0 && MAP[i][j] == MAP[a][b]) cnt++;
                    }
                }
            }
            if(min_val > cnt) min_val = cnt;
        }
    }
}
