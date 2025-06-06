# ![alt text](./images/flip.gif) 알고리즘 문제 풀이 정리

## 👋 개요
이 저장소는 다양한 알고리즘 문제를 해결한 과정을 정리한 레퍼지토리입니다.  
단순히 문제를 푸는 것에 그치지 않고, **문제 접근 방식**, **핵심 로직**, **배운 점**을 기록하며 실력을 체계적으로 다지고자 했습니다.

- 사용 언어: ![cpp](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)
- 주요 플랫폼: [백준](https://www.acmicpc.net/), [SWEA](https://swexpertacademy.com/main/main.do), [코드트리](https://www.codetree.ai/ko/trail-info)
- 정리 기준: **알고리즘 유형별**

---

## 📂 디렉토리 구조

```
📦 Algorithm-king/
├─ 📁 Graph/
│   ├─ BOJ_16236_아기상어
|   |   ├─ main.cpp
|   |   └─ README.md
|   ├─ ...
│   └─ README.md
├─ 📁 DP/
│   ├─ BOJ_11722_가장 긴 감소하는 부분수열
|   ├─ ...
│   └─ README.md
├─ 📁 Greedy/
│   ├─ BOJ_1931_회의실 배정
|   ├─ ...
│   └─ README.md
...
```

---

## 🏷️ 분류별 정리

| 분류 | 문제 수 | 바로가기 |
|------|---------|----------|
| 🧱 브루트포스 (Brute-Force) | 37문제 | [📁 Brute-Force](./Brute-Force/) |
| 💰 그리디 (Greedy) | 13문제 | [📁 Greedy](./Greedy/) |
| 📈 동적 계획법 (DP) | 11문제 | [📁 DP](./DP/) |
| ➗ 이분 탐색 (Binary-Search) | 10문제 | [📁 Binary-Search](./Binary-Search/) |
| 🔗 링크드 리스트 (Linked-List) | 3문제 | [📁 Linked-List](./Linked-List/) |
| 🧩 그래프 탐색 (BFS/DFS) | 45문제 | [📁 Graph](./Graph/) |
| 🧮 구현 | ?문제 | [📁 Implementation](.//) |
---

## ✏️ 예시 정리

### 💡 BOJ 1149 - RGB거리 [[문제 링크](https://www.acmicpc.net/problem/1149)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | DP |
| 사용 알고리즘 | Bottom-up 방식의 다중 상태 DP |
| 난이도 | 실버1 |

#### ✅ 문제 설명
- 집이 `N`개가 일렬로 존재한다.

- 각 집은 **빨강**, **초록**, **파랑** 중 하나의 색으로 칠해야 하며, 각 색을 칠하는 비용이 주어진다.

- **인접한 두 집은 같은 색으로 칠할 수 없다.**

- 모든 집을 규칙에 맞게 칠할 때, **전체 비용의 최솟값**을 구하는 문제이다.

#### 🔍 풀이 접근
- 각 집을 칠하는 데 드는 **최소 누적 비용**을 저장하는 DP 배열을 만든다.

- `dp[i][j]`: `i`번째 집을 `j`색으로 칠했을 때의 **최소 비용**

    - 여기서 `j = 0`은 빨강, `1`은 초록, `2`는 파랑을 의미

#### 💡 핵심 로직
```
예를 들어,
26 40 83
49 60 57
13 89 99

- 처음에는 D[0] = {26, 40, 83}로 초기화
- 그리고 D[1][0] = A[1][0] + min(D[0][1], D[0][2])
- D[1][1] = A[1][1] + min(D[0][0], D[0][2])
- D[1][2] = A[1][2] + min(D[0][0], D[0][1])
...
이렇게 bottom up하면 마지막에 min(D[N-1])이 정답임
```

#### 📌 배운 점
- `BruteForce`하지 않고도 최적해를 구할 수 있는 DP 방법을 이해했습니다.

---

## 📌 작성자 정보

- 이름: 신동욱
- 이메일: [ehd2610@naver.com](mailto:ehd2610@naver.com)
