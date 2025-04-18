## 💡 SWEA 22683 - 나무 베기 [[문제 링크](https://swexpertacademy.com/main/code/userProblem/userProblemDetail.do?contestProbId=AZIyCYJ6p30DFAQP)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force` + `DFS` |
| 사용 알고리즘 | 재귀 (Recursion), DFS |
| 난이도 | 모의 SW 역량 테스트 |

### ✅ 문제 설명
- 최소 리모컨 조작 횟수로 출발지에서 목적지까지 이동시키고자 함

- 가는 경로 상 나무는 지날 수 없음

- N x N 맵에 벨 수 있는 나무의 최대 수가 주어짐

- 여기서 목적지까지 이동시키기 위한 최소 조작 횟수를 구하고 싶음

- 차윤이는 항상 위를 바라보는 상태로 RC카 조작을 시작함

- 최소 조작으로 목적지까지 갈 때의 조작 횟수를 출력하라

### 🔍 풀이 접근
- 벨 수 있는 나무 개수가 주어지면, 나무를 베는 모든 시나리오에 대해 시뮬레이션을 진행한다

- 이제 최소 조작 횟수로 도착지에 도착하고자 하는데, 회전도 하나의 조작이므로 이를 고려해 설계한다

- 일단 경로가 중요하므로, DFS로 설계한다

- 경로를 만들 때 그 방향에 대한 최소 회전 횟수를 반영해서 최소 조작 횟수를 기록한다

### 💡 핵심 로직
```cpp
void GoPath(int y, int x, int dir, int cnt) {
	if (y == endPos.y && x == endPos.x) {
		if (ans > cnt)
			ans = cnt;
		return;
	}

	int ny, nx;
	for (int i = 0; i < 4; i++)
	{
		ny = y + dy[(dir + i) % 4];
		nx = x + dx[(dir + i) % 4];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if (visited[ny][nx] == 1)
			continue;
		if (map[ny][nx] == 'T')
			continue;

		visited[ny][nx] = 1;
		GoPath(ny, nx, (dir + i) % 4, cnt + c[i] + 1);
		visited[ny][nx] = 0;
	}
}
```

### 📌 배운 점
- DFS에 특정 가중치를 더하는 기법에 대해 알게 되었습니다.