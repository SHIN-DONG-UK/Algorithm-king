## 💡 BOJ 1065 - 한수 [[문제 링크](https://www.acmicpc.net/problem/1065)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `Brute-Force` |
| 사용 알고리즘 | `while-loop` |
| 난이도 | `실버4` |

### ✅ 문제 설명
- `한수`는 양의 정수 X의 각 자리가 `등차수열을 이루는 수`이다

- 1보다 크거나 같고, N보다 작거나 같은 `한수의 개수`를 출력하라

### 🔍 풀이 접근
- 한 번이라도 기록된 차이가 다르면 `false`, 끝까지 문제가 없으면 `true`를 반환하는 함수를 만든다

- 1부터 N까지 이 함수를 돌려서 `true`인 개수를 누적한다

### 💡 핵심 로직
```cpp
int run(int n){
    int num = n;
    
    int prev = num % 10;
    num = num / 10;
    
    int now = num % 10;
    num = num / 10;
    
    int diff = prev - now;
    prev = now;
    
    while(num != 0){
        
        now = num % 10;
        num = num / 10;
        
        if(diff != prev - now) return 0;
        
        diff = prev - now;
        prev = now;
    }
    return 1;
}
```

### 📌 배운 점
- 정수를 분해하기 위해 나머지 연산을 활용했습니다.