#include <iostream>
using namespace std;

const int power2[11] = { 1,2,4,8,16,32,64,128,256,512,1024 };

int K;
int arr[1025];   // 1-based index
int btree[1025]; // 1-based index
int gIdx;		 // global arr index counter

void init();
void solve();

void pre_order(int now);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> K;
	for (int i = 1; i <= power2[K] - 1; i++) {
		cin >> arr[i];
	}
	gIdx = 1;

	pre_order(1);
}

void solve() {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		for (int j = 1; j <= power2[i]; j++) {
			cout << btree[sum + j] << ' ';
		}
		sum += power2[i];
		cout << '\n';
	}
}


void pre_order(int now) {
	if (now >= power2[K]) {
		return;
	}

	int left = now * 2;
	int right = now * 2 + 1;

	pre_order(left);
	btree[now] = arr[gIdx++];
	pre_order(right);
}
