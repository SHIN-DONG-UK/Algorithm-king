#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[100000];

void output();
bool BinarySearch(int tar);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A, A + N);

    cin >> M;
    for (int i = 0; i < M; i++) {
        int tar;
        cin >> tar;
        if (BinarySearch(tar)) cout << "1\n";
        else cout << "0\n";
    }
}

bool BinarySearch(int tar) {
    int start = 0;
    int end = N-1; // 중요 -> 그냥 무지성으로 N으로 두면 out of index 에러 날 수 있음
							     // start도 N이고 end도 N이 되버리는 케이스에서 out of index Error
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (A[mid] > tar) end = mid - 1;
        else if (A[mid] < tar) start = mid + 1;
        else return true;
    }
    return false;
}