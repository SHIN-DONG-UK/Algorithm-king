## 💡 BOJ 15664 - N과 M(10) [[문제 링크](https://www.acmicpc.net/problem/15664)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `재귀` |
| 사용 알고리즘 | `백트래킹` |
| 난이도 | 실버2 |

### ✅ 문제 설명
- N개의 자연수와 자연수 M가 주어짐

- N개의 자연수 중에서 M개를 고른 수열을 모두 출력하라

- 고른 수열은 비내림차순

- N개의 자연수는 같은 수가 포함될 수 있음

### 🔍 풀이 접근
- 주어지는 숫자를 오름차순으로 정렬한다

- 조합 포맷에서 가지치기한다
    - 같은 lev에 사용된 숫자는 다시 사용하지 못하도록 하면 된다
    - 하나의 visited를 더 선언해서 기록해둔다

### 💡 핵심 로직
- 조합을 구하는데, 비내림차순이라고 start 넘길 때 i넘기는게 아니라 조합그대로 i + 1을 넘긴다

- 그 이유는 이건 인덱스로 쓰이기 때문

### 📌 배운 점
- 조합을 활용한 가지치기를 배웠습니다.