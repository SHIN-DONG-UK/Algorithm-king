## 💡 BOJ 9466 - 텀 프로젝트 [[문제 링크](https://www.acmicpc.net/problem/9466)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `그래프 탐색` |
| 사용 알고리즘 | `DFS` |
| 난이도 | 골드3 |

### ✅ 문제 설명
- 팀을 만드는데, 인원 수의 제한은 없다

- 단 한 명만 같이하고 싶은 사람으로 지명한다(자기자신도 가능)

- 학생이 다른 학생을 가리켰을 때, 만약 closed되면 팀이다

- **이렇게 팀을 구성했을 때 어느 팀에도 속하지 않은 학생 수를 구하는 문제**

### 🔍 풀이 접근
- $O(N^2)$ 풀이
  - N명의 학생을 각각 돌면서, N번 안에 자기 자신을 만나면 closed이고, 아니면 open이다
  - 하지만 시간초과

- $O(N)$으로 풀려면?
  - 중복을 피하자


### 💡 핵심 로직
- 다음 사람이 사이클이 아니거나 사이클이면 나는 사이클이 아니다

- `x`에서 시작해서 `x`로 다시 돌아오면 그 사이 학생들은 모두 사이클이다

- `x`에서 시작해서 다른 `y`를 재방문하면, `x`부터 `y 이전`까지는 사이클이 아니고, `y`부터 `y`까지 사이클이다

### 📌 배운 점
- 전형적인 단방향 그래프에서 사이클을 찾아내는 방법을 학습했습니다.