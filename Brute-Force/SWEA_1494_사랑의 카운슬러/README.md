## 💡 SWEA 1494 - 사랑의 카운슬러 [[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV2b_WPaAEIBBASw)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | **Backtracking** |
| 사용 알고리즘 | **제약 조건 재귀** |
| 난이도 | D4 |

### ✅ 문제 설명
- 지렁이 `N`마리가 있고, 임의의 두 지렁이를 매칭한 후 하나가 다른 지렁이가 있는 곳으로 가도록 함

- 가능한 움직인 벡터 합의 크기가 작기를 바람

- 모든 지렁이들을 매칭시키고 소개팅을 주선하되, 각 지렁이들이 움직인 벡터 합의 `최솟값`을 구하라

### 🔍 풀이 접근
- 어차피 `벡터 합`의 최솟값을 구하는 것이다.

- 움직일 지렁이 `N/2`개를 선택하고, 움직일 지렁이는 다 빼고 그렇지 않은 지렁이는 다 더하면 된다.

- 움직일 지렁이를 선택하는 경우의 수 $_NC_{N/2}$를 다 해보면 최적해를 구할 수 있다. -> `Brute-Force`


### 💡 핵심 로직
```cpp
void go(int idx, int cnt, long long sumY, long long sumX) {
	if (cnt > N / 2) return;
	if (idx == N)
	{
		if (cnt == N / 2)
		{
			long long tmp = sumY * sumY + sumX * sumX;
			if (ans > tmp) ans = tmp;
			return;
		}
		else return;
	}
	go(idx + 1, cnt + 1, sumY - zis[idx].y, sumX - zis[idx].x); //움직일 지렁이를 선택한 경우
	go(idx + 1, cnt, sumY + zis[idx].y, sumX + zis[idx].x); //가만히 있는 지렁이를 선택한 경우
}
```

### 📌 배운 점
- `합` 조건에 따라 경우의 수가 매우 줄어들 수 있음을 알게되었습니다.