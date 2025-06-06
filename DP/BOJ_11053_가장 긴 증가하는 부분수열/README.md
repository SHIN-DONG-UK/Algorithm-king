## 💡 BOJ 11053 - 가장 긴 증가하는 부분수열 [[문제 링크](https://www.acmicpc.net/problem/11053)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | LIS (가장 긴 증가하는 부분수열) |
| 사용 알고리즘 | DP |
| 난이도 | 실버2 |

### ✅ 문제 설명

- 수열 A가 주어졌을 때, `가장 긴 증가하는 부분 수열`을 구하라

### 🔍 풀이 접근

#### 2중 for문
1. 수를 하나 선택하자

2. 지나온 애들 중에 얘보다 작은 애 중 길이가 가장 큰 값을 dp에 넣자

3. 이렇게 앞으로 나아가면 항상 최적해를 구할 수 있다

### 💡 핵심 로직
```cpp
int tmp;
for(int i=1; i<N; i++){
        tmp = 0;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                if(dp[j] > tmp) tmp = dp[j];
            }
        }
        dp[i] = tmp + 1;
    }
```

### 📌 배운 점
- DP 문제의 한 유형인 LIS에 대해 공부했습니다.
- 2중 for문과 메모이제이션으로 최적해를 찾는 방법에 대해 이해했습니다.
