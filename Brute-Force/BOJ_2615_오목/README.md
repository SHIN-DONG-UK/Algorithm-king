## 💡 BOJ 2615 - 오목 [[문제 링크](https://www.acmicpc.net/problem/2615)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force` |
| 사용 알고리즘 | `while-loop` |
| 난이도 | `실버1` |

### ✅ 문제 설명
- 19 x 19 바둑판에 검은 바둑알과 흰 바둑알 교대로 놓을거임

- 같은 색이 5개 연속이면 이기고, 6개 연속은 이긴게 아님

### 🔍 풀이 접근
- 전체 바둑판을 탐색하는데 현재 위치가 1 또는 2이면 검사를 시작한다 -> `Brute-Force`

- 검사는 가로, 세로, 대각선으로 이루어진다

- 방문처리를 해놔서 중복 연산하는 일이 없도록 한다

### 💡 핵심 로직
```cpp
int check(int y, int x, int dir){
    int cnt = 1;
    
    int cy = y;
    int cx = x;
    int ny, nx;
    
    // 정방향 검사
    while(1){
        ny = cy + dy[dir];
        nx = cx + dx[dir];
        if(ny < 0 || ny >= 19 || nx < 0 || nx >= 19) break;
        if(MAP[ny][nx] != MAP[y][x]) break;
        
        cy = ny; cx = nx;
        cnt++;
    }
    cy = y; cx = x;
    // 역방향 검사
    while(1){
        ny = cy - dy[dir];
        nx = cx - dx[dir];
        if(ny < 0 || ny >= 19 || nx < 0 || nx >= 19) break;
        if(MAP[ny][nx] != MAP[y][x]) break;
        
        cy = ny; cx = nx;
        cnt++;
    }
    return cnt;
}
```

### 📌 배운 점
- 2차원 배열에서 탐색을 위한 구현 연습을 했습니다.