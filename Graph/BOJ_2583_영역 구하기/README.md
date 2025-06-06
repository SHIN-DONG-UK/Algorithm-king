## 💡 BOJ 2583 - 영역 구하기 [[문제 링크](https://www.acmicpc.net/problem/2583)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색`, `Brute-Force` |
| 사용 알고리즘 | `BFS` |
| 난이도 | 실버1 |

### ✅ 문제 설명
- N x M 모눈종이가 있고, K개의 사각형을 그릴거임

- **K개의 사각형 좌표가 주어질 때, 분리된 영역의 개수와 각 넓이를 구하는 문제**


### 🔍 풀이 접근
- 사각형은 2중 for-loop으로 표시해놓는다

- 맵을 전체 탐색하면서 사각형이 아닌 곳에서 BFS해서 각 넓이를 파악한다

### 💡 핵심 로직
- 사각형을 표시하는 로직

### 📌 배운 점
- Brute-Force와 BFS를 같이 활용하는 문제를 이해했습니다.