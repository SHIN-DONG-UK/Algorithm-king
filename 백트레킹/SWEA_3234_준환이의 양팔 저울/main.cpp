#include <iostream>
#include <algorithm>

#define MAX 9
using namespace std;

int N;
int weights[MAX];
// 순열
int visited[MAX];
int Exp[10] = { 1,2,4,8,16,32,64,128,256,512 };
int factorial[10] = { 0,1,2,6,24,120,720,5040,40320,362880 };
// 정답
int ans;
int totalWeight;

void Init();
void Input();
void Go(int lev, int left, int right, int remaining);

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Init();
		Input();
		Go(0, 0, 0, totalWeight);

		cout << '#' << tc << ' ' << ans << '\n';
	}
}

void Init() {
	ans = 0;
	totalWeight = 0;
}

void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> weights[i];
		totalWeight += weights[i];
	}

	sort(weights, weights + N, greater<>());
}

void Go(int lev, int left, int right, int remaining) {
	// 가지치기 1
	// 오른쪽이 왼쪽보다 더 커져서는 안됨
	if (left < right)
		return;
	// 종료 조건
	if (lev == N) {
		ans++;
		return;
	}
	// 가지치기 2
	// 남은 모든 무게를 right에 더해도 left가 크면, 그냥 수식 계산 가능
	if (left >= right + remaining) {
		ans += Exp[N - lev] * factorial[N - lev];
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = 1;
		Go(lev + 1, left + weights[i], right, remaining - weights[i]);
		Go(lev + 1, left, right + weights[i], remaining - weights[i]);
		visited[i] = 0;
	}
}
