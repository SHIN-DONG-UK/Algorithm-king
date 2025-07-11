## 💡 BOJ 11967 - 불켜기 [[문제 링크]](https://www.acmicpc.net/problem/11967)

| **항목** | **내용** |
| - | - |
| **문제 유형** | 그래프 탐색 |
| **사용 알고리즘** | BFS |
| **난이도** | 골드2 |

### ✅ 문제 설명
- NxN 크기의 2차원 맵이 있고, 각 방은 (1,1)부터 (N,N)까지 번호가 매겨져 있다

- 불이 켜져 있고, 인접한 방으로만 이동할 수 있다

- 각 방에는 다른 방의 불을 킬 수 있는 스위치가 있는데, 이 스위치는 여러 개일 수 있다

- **처음에 (1,1)방에 불이 켜져있고, 이 방에서 출발해서 불을 켤 수 있는 방의 최대 개수를 구하는 문제**

### 🔍 풀이 접근
처음에는 불을 키고, BFS로 연결성을 검사하는 것을 반복해서 문제를 해결했다. 그런데, BFS를 여러 번 돌릴 필요는 없다. 방을 방문하면 일단 그 방에서 불을 킬 수 있는 곳에 불을 켠다. 그리고 그 방의 4방향 중에서 이미 방문한 곳이 있으면, 새로 켜진 방도 방문이 가능해졌다고 보고 큐에 추가하면 된다. 

이렇게 하면 한 번의 BFS로 불이 켜져있고 인접한 곳으로 이동해서 불을 키는 로직이 가능해진다.

### 💡 핵심 로직
1. 방을 방문하면, 그 방에서 불을 켤 수 있는 곳에 불을 켠다.
2. 그 방의 4방향 중에서 이미 방문한 곳이 있으면, 새로 켜진 방도 방문이 가능해졌다고 보고 큐에 추가한다.

### 📌 배운 점
**BFS의 확장 활용**  
기존에는 상태가 변할 때마다 BFS를 새로 수행해야 한다고 생각했지만, **상태 변화(불이 켜짐)** 를 실시간으로 큐에 반영하는 방식으로 BFS를 **한 번만 돌려도 문제를 해결할 수 있음**을 배웠다. 이를 통해 **BFS는 단순히 거리 탐색뿐 아니라 조건 변화에 따라 동적으로 탐색 범위를 확장**하는 데도 유용하다는 것을 깨달았다.
