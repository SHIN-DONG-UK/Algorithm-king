## 💡 BOJ 16953 - A -> B [[문제 링크](https://www.acmicpc.net/problem/16953)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색` |
| 사용 알고리즘 | `BFS` |
| 난이도 | 실버2 |

### ✅ 문제 설명
- 정수 A를 B로 바꾸려고 하는데, 가능한 연산은 두 가지
  - 2를 곱한다
  - 1을 수의 가장 오른쪽에 추가한다
- **A를 B로 바꾸는데 필요한 연산의 최솟값을 구하는 문제**

### 🔍 풀이 접근
- 각 노드에서 2를 곱하거나, 1을 추가한 값을 queue에 삽입한다

- queue에 들어온 순서대로 처리하면, 최소 연산을 구할 수 있다

### 💡 핵심 로직
- BFS 탐색

### 📌 배운 점