#include <iostream>
using namespace std;

int N, M;
int trees[1000000];
int ans;
int max_val;

void input();
void BinarySearch();

int main() {
    input();
    BinarySearch();
    cout << ans << '\n';
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max_val) max_val = tmp;
        trees[i] = tmp;
    }
}

void BinarySearch() {
    int start = 0;
    int end = max_val;
    int mid = (start + end) / 2;
    if (mid == 0) mid = 1;

    while (start <= end && mid <= end) {
        //cout << mid << '\n';

        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (trees[i] >= mid)
                sum += trees[i] - mid;
        }

        if (M > sum) end = mid - 1;
        else {
            ans = mid;
            start = mid + 1;
        }

        mid = (start + end) / 2;
        if (mid == 0) mid = 1;
    }
}
