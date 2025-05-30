## 💡 BOJ 11725 - 트리의 부모 찾기 [[문제 링크](https://www.acmicpc.net/problem/11725)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색` |
| 사용 알고리즘 | `BFS` |
| 난이도 | 실버2 |

### ✅ 문제 설명
- 루트 없는 트리가 주어진다

- **트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 문제**

### 🔍 풀이 접근
- 주어지는 정보를 통해 트리 자료구조를 구성한다

- Breadth First Traversal을 하면서 array에 기록해나가면 된다


### 💡 핵심 로직
- root에서 시작해서 다음 노드를 방문할 때, 다음 노드 번호의 array에 현재 노드 번호를 기록해나간다.

### 📌 배운 점
- 방문 배열의 중요성을 다시 느꼈다. 트리는 사이클이 없지만, 입력은 무방향 간선이라 중복 방문을 막지 않으면 바로 이전 정점으로 되돌아가 ‘자식이 부모를 또 부모로 기록’하는 문제가 생긴다.