# 1. 이해

```
[조간]
- N개의 자연수와 자연수 M이 주어짐
- N개의 자연수 중에서 M개를 고른 수열
- 같은 수를 여러 번 골라도 됨
- 고른 수열은 비내림차순

[입력]
- N, M (1 ≤ M ≤ N ≤ 8)
- N개의 자연수

[출력]
- 조건을 만족하는 수열
- 사전 순 증가로
```

# 2. 설계

```
조합 + path 배열값으로 숫자 배열 인덱싱 하는데, start를 i+1로 넘기지 않고 i로 넘기면 됨
```