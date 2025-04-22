## 💡 SWEA 3234 - 준환이의 양팔 저울 [[문제 링크](https://swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AZIyCYJ6p30DFAQP)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `백트레킹(Back-tracking)` |
| 사용 알고리즘 | `제약 조건이 있는 재귀` |
| 난이도 | 모의 SW 역량 테스트 |

### ✅ 문제 설명
- N개의 서로 다른 무게를 가진 무게 추와 양팔저울이 있다

- 모든 무게 추를 양팔저울에 올리는 순서는 총 $N!$

- 여기에 왼쪽에 올릴지 오른쪽에 올릴지 -> $2^N * N!$

- 단, 오른쪽 저울 무게가 왼쪽보다 크면 안됨

- **이런 방법으로 준환이가 양팔 저울에 모든 무게추를 올리는 방법은 몇 가지?**

### 🔍 풀이 접근
- 문제대로 $2^N * N!$을 구현하면 $N=9$인 경우 시간초과가 발생한다 

- 사실 모든 경우의 수를 직접 탐색할 필요가 없다

- 우리는 수식으로 $2^N * N!$을 얻을 수 있다

- 그래서 수식으로 구해도 되는 구간이 나오면, 수식으로 구하면 된다

- 그렇지 않은 구간을 그래프 탐색하도록 코드를 작성하여야 한다

- 수식으로 구해도 되는 구간은 나머지 무게를 모두 `right`에 더해도
`left`가 더 크거나 같은 경우이다

### 💡 핵심 로직
```cpp
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
```

### 📌 배운 점
- 모든 경우의 수를 구하는데, `가지치기` 조건으로 더 깊숙한 트리로 들어가지 않는 `백트레킹`문제 유형을 이해했습니다.