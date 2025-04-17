## 💡 BOJ 1541 - 잃어버린 괄호 [[문제 링크](https://www.acmicpc.net/problem/1541)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | Greedy + 구현 |
| 사용 알고리즘 | Greedy |
| 난이도 | 실버3 |

### ✅ 문제 설명
- 수식이 주어진다.

- 괄호를 적절히 쳐서 최솟값을 만들어라.

### 🔍 풀이 접근
- 마이너스(-)를 최대한 이용한다.

- 최대한 -를 기준으로 +를 묶어서 값을 작게 만든다.

- 즉, -기준으로 파싱하고 나머지는 다 더해주면 최대한 큰 -를 만들 수 있다.

### 💡 핵심 로직
```cpp
void calc(){
    for(int i=0; i < s.size(); i++) {
        if(s[i] == '-' || s[i] == '+') {
            v.push_back(s.substr(idx, i-idx));
            v.push_back(s.substr(i, 1));
            idx = i + 1;
        }
    }
    v.push_back(s.substr(idx, s.size() - idx));
    
    for(int i=0; i<v.size(); i++) {
        if(v[i] == "-") flag = 1;
        
        if(v[i] != "-" && v[i] != "+"){
            if(flag == 1) ans -= stoi(v[i]);
            else ans += stoi(v[i]);
        }
    }
}

```

### 📌 배운 점
- 일단 -를 뽑아내는 그리디한 접근으로 최적해를 구하는 방법을 이해했습니다.
