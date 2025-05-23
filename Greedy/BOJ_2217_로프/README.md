## 💡 BOJ 2217 - 로프 [[문제 링크](https://www.acmicpc.net/problem/2217)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | 정렬+ 그리디 |
| 사용 알고리즘 | Greedy |
| 난이도 | 실버4 |

### ✅ 문제 설명
- N개의 로프가 있고 각 로프는 들어올릴 수 있는 중량이 다름.

- 로프는 병렬 연결이 가능. 

- k개의 로프, 중량 w물체.

- 각 로프에 걸리는 중량 = w/k.

- 모든 로프를 사용할 필요 없음.

- 로프를 이용해 들어올릴 수 있는 최대 중량을 구하라.

### 🔍 풀이 접근
- 극단적인 상황을 가정해보자.
```
2
1
100
```

- 만약 1 100을 병렬연결하면 1까지 버틸 수 있다

- 그니까 연결하면 무게를 k개로 나누는 대신 최대 버팀 중량은 병렬 연결된 로프들의 최솟값이 된다

- 로프들 중 최솟값 * k가 최대인 지점을 찾으면 되겠다.

- 이때 내림차순으로 정렬해놓고 순서대로 방문해야 최적해가 나온다.

### 💡 핵심 로직
```cpp
void solve() {
	ans = arr[1];
	for (int i = 2; i <= N; i++) {
		if (arr[i] * i > ans) ans = arr[i] * i;
	}
}
```

### 📌 배운 점
- 정렬 후 최댓값을 찾는 그리디 문제를 이해했습니다.

