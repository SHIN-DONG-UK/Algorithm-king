## 💡 BOJ 2206 - 벽 부수고 이동하기 [[문제 링크](https://www.acmicpc.net/problem/2206)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색` |
| 사용 알고리즘 | `BFS (Flood Fill)` |
| 난이도 | 골드3 |

### ✅ 문제 설명
- N x M 맵이 있고, (1, 1)에서 시작해서 (N, M)에 도착해야 함

- `1`은 벽, `0`은 빈 칸이고 벽은 지날 수 없음

- 최단거리로 이동하고 싶은데, 벽을 `한 번` 부수고 이동할 수 있음

- **최단거리를 출력하라. 만약 이동할 수 없으면 -1 출력**

### 🔍 풀이 접근
이 문제는 벽을 한 번 부술 수 있다는 조건때문에 단순한 최단거리 문제에서 조금 더 생각해야 합니다. 하지만 벽을 '한 번' 부술 수 있으므로, 2차원 맵의 한 노드에서는 두 가지 상태가 존재할 뿐입니다. 

**1. 벽을 아직 부수지 않은 상태**  
**2. 벽을 한 번 부순 상태**

현재 노드의 상태는 전이되어, 다음 노드에 영향을 끼칩니다. 예를 들어,

- **길이면**, 현재 상태를 유지한 채 이동할 수 있습니다.
- **벽이라면**, 아직 벽을 부수지 않았다면 이 벽을 부수고 이동할 수 있습니다.

같은 노드에서 상태에 따라 최단거리가 다르므로, 두 개의 최단거리 테이블을 선언합니다. 그리고 상태에 따른 BFS 탐색으로 최단거리를 구해내면 됩니다. 

코드의 편의성때문에 3차원 dist 배열로 두 개의 최단거리 테이블을 대신했습니다.

### 💡 핵심 로직
1. 길이면, 그대로 진행
2. 벽인데 아직 부순 적 없으면 진행

### 📌 배운 점
**-상태를 나눠서 탐색하는 BFS 패턴을 익힘-**  
단순히 한 지점을 방문했는지만 확인하는 것이 아니라, 벽을 부쉈는지 여부라는 상태를 고려해서 탐색했습니다. 같은 좌표라도 다른 상태로 도달할 수 있기 때문에, 이를 구분해주는 3차원 배열을 사용하는 방식이 유용함을 배웠습니다.