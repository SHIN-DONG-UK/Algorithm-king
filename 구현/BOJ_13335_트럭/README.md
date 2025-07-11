## 💡 BOJ 13335 - 트럭[[문제 링크](https://www.acmicpc.net/problem/13335)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `구현` |
| 사용 알고리즘 | `` |
| 난이도 | `실버1` |

### ✅ 문제 설명
- n개의 트럭이 있고, 그 순서는 바꿀 수 없다

- 각 트럭의 무게는 다를 수 있다

- w대의 트럭만 다리에 동시에 올라갈 수 있다

- w대의 트럭 무게 합은 L보다 작거나 같아야 한다

- 다리 위에 '완전히 올라가지 못한 트럭'의 무게는 고려하지 않는다

- **트럭이 단위 시간으로 움직일 때, 모든 트럭이 다리를 지나가는데 걸리는 시간을 구하는 문제**

### 🔍 풀이 접근
문제 주어진 그대로 구현하면 될 것 같다.

- 트럭들을 대기 큐에 넣어놓고, 다리로 하나씩 보낸다.
- 다리는 array로 구현한다.
- 보낼 수 있거나, 없거나 조건문으로 검사한다.
- 다리로 보낼 수 있으면 보낸다음 다리 안에서 트럭들을 한 칸씩 밀고, 보낼 수 없으면 안보내고 다리 안에서 트럭들을 한 칸씩 민다.
- 이걸 while 루프 안에서 수행하고 while 루프는 시간을 기록한다.

### 💡 핵심 로직
- 큐 사이즈와 다리 위에 트럭이 올라간 대수로 while 루프의 종료 여부를 결정한다

### 📌 배운 점
- 트럭을 순서대로 다루고 그 현황을 파악하기 위해 큐 자료구조를 활용했는데, 이 자료구조를 활용하는 상황에 대해 학습했습니다.