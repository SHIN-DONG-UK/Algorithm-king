## 💡 SWEA 5656 - 벽돌깨기 [[문제 링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force` + `Simulation` |
| 사용 알고리즘 | 중복 순열 |
| 난이도 | 모의 SW 역량 테스트 |

### ✅ 문제 설명
- `w x h` 크기 격자에 구슬을 쏘아 벽돌을 깨는데, 구슬은 `N`번만 쏠 수 있음

- 구슬은 좌, 우로만 움직일 수 있어서 항상 맨 위에 있는 벽돌만 깨트릴 수 있음

- 벽돌은 숫자 1 ~ 9로 표현
	- 구슬이 명중한 벽돌은 상하좌우로 (벽돌에 적힌 숫자 -1) 칸 만큼 같이 제거

- 제거되는 범위 내에 있는 벽돌은 동시에 제거됨

- 빈 공간이 있을 경우 벽돌은 밑으로 떨어지게 된다

- N개의 벽돌을 떨어트려 최대한 많은 벽돌을 제거하려고 함

- `N`, `W`, `H` 그리고 `벽돌의 정보`가 주어질 때, `최대한 많은 벽돌을 제거`하고 남은 벽돌 개수를 구하라

### 🔍 풀이 접근
- N이 최대 4번, 그리고 W가 최대 12이므로 돌을 떨어뜨리는 모든 경우의 수를 시뮬레이션하더라도 최악의 경우 $12^4 = 20,736$

- 모든 경우에 대해, Simulation을 진행해 최대한 많은 벽돌을 제거한 경우를 찾는다.

### 💡 핵심 로직
```cpp
void CrashBlock(Point sp) {
	queue<Point> q;
	q.push(sp);
	tmp_map[sp.y][sp.x] = 0;

	Point cp, np;
	while (!q.empty()) {
		cp = q.front(); q.pop();

		for (int d = 0; d < 4; d++)
		{
			for (int k = 1; k < cp.num; k++)
			{
				np = { cp.y + dy[d] * k, cp.x + dx[d] * k, tmp_map[cp.y + dy[d] * k][cp.x + dx[d] * k]};
				if (np.y < 0 || np.y >= H || np.x < 0 || np.x >= W)
					break;
				if (tmp_map[np.y][np.x] == 0)
					continue;
				else if (tmp_map[np.y][np.x] == 1)
					tmp_map[np.y][np.x] = 0;
				else {
					q.push(np);
					tmp_map[np.y][np.x] = 0;
				}
					
			}
		}
	}

	GoDown();
}
```

### 📌 배운 점
- 벽돌의 연쇄 반응을 `queue`를 이용해 해결했습니다.