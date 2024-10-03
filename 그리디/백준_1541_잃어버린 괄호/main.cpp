#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;
vector<string> v;
int idx;
int flag;
int ans;

void input();
void calc();

int main(){
    input();
    calc();
    
    cout << ans << '\n';
}

void input(){
    cin >> s;
}

void calc(){
    for(int i=0; i<s.size(); i++){
        if(s[i] == '-' || s[i] == '+'){
            v.push_back(s.substr(idx, i-idx));
            v.push_back(s.substr(i, 1));
            idx = i + 1;
        }
    }
    v.push_back(s.substr(idx, s.size() - idx));
    
    for(int i=0; i<v.size(); i++){
        if(v[i] == "-") flag = 1;
        
        if(v[i] != "-" && v[i] != "+"){
            if(flag == 1) ans -= stoi(v[i]);
            else ans += stoi(v[i]);
        }
    }
}
