## 💡 SWEA 4008 - 숫자 만들기 [[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force`, 같은 것이 있는 순열 (BackTracking) |
| 사용 알고리즘 | 재귀 (Recursion) |
| 난이도 | 모의 SW 역량 테스트 |

### ✅ 문제 설명
- `N`개의 숫자

- `+`, `-`, `*`, `/`의 연산자 카드를 숫자 사이에 끼워 넣기

- 연산자의 우선 순위는 고려하지 않고 왼쪽에서 오른쪽으로 계산

- 주어진 연산자 카드를 사용하여 수식을 계산했을 때, `최대와 최소 차이`를 구하라

### 🔍 풀이 접근
- 가능한 모든 연산자의 순서를 시도하고 최댓값과 최솟값을 갱신

- 연산자의 개수는 최대 11이므로, 모든 경우의 수는 11!

- 각 경우의 수 마다 최대 11번의 연산 수행

- 즉, 최악의 경우 11 * 11! -> 시간초과

- `같은 것이 있는 순열`로 시간을 아껴야 함


### 💡 핵심 로직
```cpp
void Go(int idx) {
	if (idx == N - 1) {
		int tmp = calc();
		min_ans = min(min_ans, tmp);
		max_ans = max(max_ans, tmp);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] == 0)
			continue;
		oper[i] -= 1;
		selected.push_back(i);
		Go(idx + 1);
		selected.pop_back();
		oper[i] += 1;
	}
}
```

### 📌 배운 점
- 각 연산자의 개수를 저장해 놓고, 연산자를 다 쓰면 `continue`하는 식으로 `같은 것이 있는 순열`을 구현할 수 있음을 알게 되었습니다.