#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 최대 범위 (B <= 100,000)
const int MAX = 100000;

// 전역 변수 선언
int spf[MAX + 1];           // 각 수의 가장 작은 소인수 (Smallest Prime Factor)
int pfc[MAX + 1] = {0, };   // 각 수의 소인수 개수 (Prime Factor Count)
bool is_prime[21];          // 소인수 개수가 소수인지 판별 (최대 개수는 20이하)

void precompute();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int A, B;
    if (!(cin >> A >> B)) return 0;

    int underprime_count = 0;

    for (int i = A; i <= B; i++) {
        int count = pfc[i]; 

        if (count <= 20 && is_prime[count]) {
            underprime_count++;
        }
    }

    cout << underprime_count << '\n';

    return 0;
}

void precompute() {
    for (int i = 2; i <= MAX; i++) {
        spf[i] = i;
    }
    for (int i = 2; i * i <= MAX; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= MAX; j += i) {
                if (spf[j] == j) {
                    spf[j] = i; 
                }
            }
        }
    }

    for (int i = 2; i <= MAX; i++) {
        pfc[i] = pfc[i / spf[i]] + 1;
    }

    fill(is_prime, is_prime + 21, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 20; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 20; j += i) {
                is_prime[j] = false;
            }
        }
    }
}