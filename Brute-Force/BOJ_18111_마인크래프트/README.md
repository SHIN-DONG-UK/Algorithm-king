## 💡 BOJ 18111 - 마인크래프트 [[문제 링크](https://www.acmicpc.net/problem/18111)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force` |
| 사용 알고리즘 | `for-loop` |
| 난이도 | `실버2` |

### ✅ 문제 설명

[땅 고르기]
- `N x M`의 맵

- 각 칸은 `0이상 256이하`

- 왼쪽 위 좌표는 `(0, 0)`

- 땅의 높이를 일정하게 바꾸는 작업임
	1. **제거** : 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다 `2초`
	2. **추가** : 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다 `1초`

[출력]
- 땅 고르기 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력

- 처음 `B`개의 블록을 갖고 있음

- 시간이 같은게 여러 개 있다면 높이가 가장 높은 거

### 🔍 풀이 접근
- 최대한 빨리 땅을 고르기 위해, 현재 땅의 높이 최댓값과 최솟값 사이에서 땅을 골라야 함

- 이 사이 높이를 다 해보면서, 최솟값을 찾는다

### 💡 핵심 로직
```cpp
int isPossible(int target){
    int time = 0;
    int block = B;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(MAP[i][j] == target) continue;
            
            if(MAP[i][j] > target) {
                time += 2*(MAP[i][j] - target);
                block += (MAP[i][j] - target);
            }
            else if(MAP[i][j] < target){
                time += (target - MAP[i][j]);
                block -= (target - MAP[i][j]);
            }
        }
    }
    if(block < 0) return -1;
    else return time;
}
```

### 📌 배운 점
- 최적해를 구하기 위해 `Brute-Force`하게 접근하고, 문제 요구사항을 구현하는 해결력을 길렀습니다.

