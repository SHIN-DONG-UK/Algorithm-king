## 💡 BOJ 23289 - 온풍기 안녕![[문제 링크](https://www.acmicpc.net/problem/23289)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `구현`, `시뮬레이션` |
| 사용 알고리즘 | `` |
| 난이도 | `플레티넘 5` |

### ✅ 문제 설명
- R x C 격자로 표현된 집 안에 여러 대의 온풍기가 설치되어 있다

- 시뮬레이션
  1. 온풍기 가동
  2. 온도 조절
  3. 바깥쪽 온도 감소
  4. 반복 횟수 _ 1
  5. 검사

- **시뮬레이션하며 조사해야 하는 칸들의 온도가 모두 K 이상일 때까지 걸린 반복 횟수를 구하는 문제**

### 🔍 풀이 접근
각 시뮬레이션에 맞는 함수를 구현해준다. 이때, 가장 먼저 해준 것은 벽과의 상호작용을 어떻게 할 것인지 결정한 것이다. 

각 칸은 최대 4개의 벽을 가질 수 있다. 따라서 2차원 `vector`와 3차원 `bool array`로 표현할 수 있을텐데, 로직구현에 있어 `bool array`가 편할 것 같다고 판단하여 3차원 `bool array`로 벽 유무를 판단하였다. `(y, x)`에 `d`방향으로 벽이 있으면 `wall[y][x][d] = true`이다.

### 💡 핵심 로직
#### 1. 온풍기 가동
항상 세 갈래로 이동하면서 벽에 막혀있는지 검사하며 이동한다. 이는 각 칸에서 매번 세 갈래로 이동하는 BFS로 구현할 수 있다. 세 갈래로 이동하는 방법은 하드코딩으로 구현하면 가장 쉽고 빠르게 구현 가능하다.

#### 2. 온도 조절
온도가 높은 쪽에서 낮은 쪽으로 조절이 일어나도록 구현해야 한다. 또한 해당 방향으로 벽이 있는지 검사해서, 있으면 온도가 이동하지 않고 없으면 이동하는 식으로 구현하면 된다.

'동시에'라는 말은 항상 next_map을 만들어놓고 여기에 반영을 한 다음, 나중에 원래 map에 복사하는 식으로 구현하면 된다.

#### 3. 바깥쪽 온도 감소
단순히 반복문으로 반영하면 된다. 단, 꼭짓점이 두 번 연산되지 않도록 주의한다.

#### 4. 검사
단순히 반복문으로 검사하면 된다.

### 📌 배운 점
- 일반적인 4방향 BFS가 아닌, 특이한 모양의 BFS를 탐색하는 구현 경험을 했습니다. 특히 특이한 모양을 위해 방향을 하드코딩하여 해결했습니다.