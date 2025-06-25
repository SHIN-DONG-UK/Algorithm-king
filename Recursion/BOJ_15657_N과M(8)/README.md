## 💡 BOJ 15657 - N과 M(8) [[문제 링크](https://www.acmicpc.net/problem/15657)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `재귀` |
| 사용 알고리즘 | `백트래킹` |
| 난이도 | 실버3 |

### ✅ 문제 설명
- N개의 자연수와 자연수 M이 주어짐

- N개의 자연수 중에서 M개를 고른 수열

- 같은 수를 여러 번 골라도 됨

- 고른 수열은 비내림차순

### 🔍 풀이 접근
- 조합 + path 배열값으로 숫자 배열 인덱싱 하는데, start를 i+1로 넘기지 않고 i로 넘기면 됨

### 💡 핵심 로직
```cpp
void go(int idx, int start){
    if(idx == M){
        for(int i=0; i<M; i++){
            cout << nums[path[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for(int i=start; i<N; i++){
        path[idx] = i;
        go(idx + 1, i);
    }
}

```

### 📌 배운 점
- 조합을 활용해 문제를 해결했습니다.