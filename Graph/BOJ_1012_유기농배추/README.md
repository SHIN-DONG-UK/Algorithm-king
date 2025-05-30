## 💡 BOJ 1012 - 유기농 배추 [[문제 링크](https://www.acmicpc.net/problem/1012)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색` |
| 사용 알고리즘 | `BFS` |
| 난이도 | 실버2 |

### ✅ 문제 설명
- 배추에 **배추흰지렁이**가 한 마리라도 살고 있으면 이 지렁이는 인접한 다른 배추로 이동할 수 있음

- 배추들이 모여있는 곳은 한 마리만 있으면 해충을 막을 수 있음

- **필요한 최소 배추흰지렁이 개수를 구하라**

### 🔍 풀이 접근
- 모든 배추를 다 검사해서 덩어리의 개수를 구하면 되겠다

### 💡 핵심 로직
- 2차원 배열을 돌면서 배추가 있는 곳을 찾는다

- 그 곳을 시작점으로 해서 BFS 탐색으로 모든 인접한 배추를 `방문 처리`한다

- `방문 처리`되지 않은 노드를 시작점으로 해서 반복한다

### 📌 배운 점
- BFS 문제의 기본을 공부했습니다.
