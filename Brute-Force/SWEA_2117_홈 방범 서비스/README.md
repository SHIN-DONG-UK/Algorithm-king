## 💡 SWEA 2117 - 홈 방범 서비스 [[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | **Brute-Force** (Backtracking) |
| 사용 알고리즘 | for-loop |
| 난이도 | 모의 SW 역량 테스트 |

### ✅ 문제 설명
- `N x N` 맵에 집(1)과 빈 곳(0)이 있음

- 홈 방범 서비스를 제공받는 집들은 각각 `M` 비용을 지불

- 홈 방범 서비스 `운영 비용`은 K * K + (K-1) * (K-1)

- 홈 방범 서비스 -> `마름모` 모양만 제공

- 보안회사는 손해를 보지 않는 한 `최대한 많은 집에 홈 방범 서비스`를 제공한다고 할 때, 그런 집들의 수를 출력하라

### 🔍 풀이 접근
- `Brute-Froce`하게 모든 마름모에 대한 모든 위치에서 계산하면, 최적해를 보장함.

- (0, 0)에서 (n-1, n-1)까지 한 번에 커버되는 k까지 마름모를 늘려보아야 함.

- 만약 N이 20이면, k는 22까지 늘려야 위 조건을 만족.


### 💡 핵심 로직
```cpp
void Check(int cy, int cx, int k) {
	int cost = 0;
	int cnt = 0;
	
	for(int dy = -k + 1; dy <= k - 1; dy++){
		int row = cy + dy;
		int span = (k - 1) - abs(dy);
		for(int dx = -span; dx <= span; dx++){
			int col = cx + dx;
			if (row < 0 || row >= N || col < 0 || col >= N)
				continue;
			if (map[row][col] == 1) {
					cost += M;
					cnt++;
				}
		}
	}
	if (cost >= k * k + (k - 1)*(k - 1))
		ans = max(ans, cnt);
}
```

### 📌 배운 점
- 마름모 순회 방법을 알게 되었습니다.