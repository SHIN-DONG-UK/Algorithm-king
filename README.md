# ![alt text](./images/flip.gif) 알고리즘 문제 풀이 정리

## 👋 개요
이 저장소는 다양한 알고리즘 문제를 해결한 과정을 정리한 공간입니다.  
단순히 문제를 푸는 것에 그치지 않고, **문제 접근 방식**, **핵심 로직**, **배운 점**을 기록하며 실력을 체계적으로 다지고자 했습니다.

- 사용 언어: C++
- 주요 플랫폼: [백준](https://www.acmicpc.net/), [프로그래머스](https://programmers.co.kr/), [코드트리](https://www.codetree.ai/ko/trail-info)
- 정리 기준: **알고리즘 유형별**

---

## 📂 디렉토리 구조

```
📦 알고리즘/
├─ 📁 Graph/
│   ├─ BOJ_14502_연구소.py
│   └─ README.md
├─ 📁 DP/
│   ├─ BOJ_1003_피보나치함수.py
│   └─ README.md
├─ 📁 Greedy/
│   ├─ Programmers_큰수만들기.py
│   └─ README.md
...
```

---

## 🏷️ 분류별 정리

| 분류 | 문제 수 | 바로가기 |
|------|---------|----------|
| 🧩 그래프 탐색 (BFS/DFS) | 5문제 | [📁 Graph](./Graph/) |
| 📈 동적 계획법 (DP) | 4문제 | [📁 DP](./DP/) |
| 💰 그리디 | 3문제 | [📁 Greedy](./Greedy/) |
| 🧮 구현 | 6문제 | [📁 Implementation](./Implementation/) |

---

## ✏️ 예시 정리

### 💡 BOJ 14502 - 연구소 [[문제 링크](https://www.acmicpc.net/problem/14502)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | 완전탐색 + BFS |
| 사용 알고리즘 | 조합(combinations), BFS |
| 난이도 | 중상 |

#### ✅ 문제 설명
연구소 맵에서 바이러스가 퍼지지 않도록 벽 3개를 세워 안전 영역의 최대 크기를 구하는 문제입니다.

#### 🔍 풀이 접근
1. 빈 칸 중 3곳을 조합으로 선택하여 벽을 설치합니다.
2. 각 경우에 대해 BFS를 사용해 바이러스 확산을 시뮬레이션합니다.
3. 남아있는 안전 영역(값이 0인 셀)의 개수를 계산하여 최대값을 갱신합니다.

#### 💡 핵심 코드
```python
from itertools import combinations
from collections import deque
from copy import deepcopy

for walls in combinations(empty_spaces, 3):
    temp_map = deepcopy(original_map)
    for y, x in walls:
        temp_map[y][x] = 1
    spread_virus(temp_map)  # BFS 수행
    safe_zone = count_zero(temp_map)
    max_safe = max(max_safe, safe_zone)
```

#### 📌 배운 점
- 완전탐색 + BFS 조합 연습에 적절한 문제였습니다.
- `deepcopy` 대신 더 효율적인 맵 복사 방법도 고민해볼 여지가 있습니다.
- 문제를 해결하며 **시간 복잡도 고려 + 시뮬레이션 능력**을 키울 수 있었습니다.

---

## ✅ 진행 현황

- [x] 분류별 폴더 구성
- [x] BFS/DFS 유형 3문제 정리
- [ ] Greedy 유형 정리 시작
- [ ] Python 외 C++ 풀이 병행 정리
- [ ] 상위 100문제 마스터 플랜 수립 예정

---

## 📌 작성자 정보

- 이름: 신동욱
- 이메일: [ehd2610@naver.com](mailto:ehd2610@naver.com)
