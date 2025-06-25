#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int a[8];
int nums[8];
int cnt_arr[10001];
int len;

void input();
void go(int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    go(0);
}

void input() {
    cin >> N >> M;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        cnt_arr[num]++;
    }

    for (int i = 0; i < 10001; i++) {
        if (cnt_arr[i] > 0) {
            nums[len] = i;
            len++;
        }
    }
    // len이 length
    sort(nums, nums + len);
}

void go(int idx) {
    if (idx == M) {
        for (int i = 0; i < M; i++) {
            cout << nums[a[i]] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < len; i++) {
        a[idx] = i;
        go(idx + 1);
    }


}
