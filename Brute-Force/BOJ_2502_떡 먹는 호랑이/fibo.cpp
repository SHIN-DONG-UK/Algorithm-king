#include <iostream>
using namespace std;

int D, K;
int coefA[31], coefB[31];

void init();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    solve();

    return 0;
}

void init() {
    cin >> D >> K;
}

void solve() {
    //초기 계수 세팅
    coefA[1] = 1; coefB[1] = 0;
    coefA[2] = 0; coefB[2] = 1;

    //피보나치처럼 계수 전개
    for (int i = 3; i <= D; i++) {
        coefA[i] = coefA[i - 1] + coefA[i - 2];
        coefB[i] = coefB[i - 1] + coefB[i - 2];
    }

    //arr[D] = coefA[D]*A + coefB[D]*B = K
    for (int A = 1; coefA[D] * A < K; A++) {
        int remain = K - coefA[D] * A;
        if (remain % coefB[D] == 0) {
            int B = remain / coefB[D];

            if (A <= B) {
                cout << A << '\n';
                cout << B << '\n';
                return;
            }
        }
    }
}