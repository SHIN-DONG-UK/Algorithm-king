# 1. 이해

```
- 정수 A를 B로 바꾸려고 한다
- 가능한 연산 두 개
	1. 2를 곱한다
	2. 1을 수의 가장 오른쪽에 추가한다

[출력]
A를 B로 바꾸는데 필요한 연산의 최솟값
```

# 2. 설계

```
- 그리디로 이 문제를 해결할 수 있는가?
	-> 놉. 2를 무지성으로 곱하면 안되는 케이스가 존재
	-> 그럼 모든 경우를 다 따져보면 풀 수 있지 않을까
- queue에서 숫자 하나를 꺼내서 1번 연산과 2번 연산을 모두 수행하고, 다시 집어 넣는 방식을
반복하면 언젠가 도달하게 된다 그때 멈추면 됨

```

# 3. 주의

```
- 후보는 int형 범위를 넘을 수 있고, 정답은 그렇지 않을 수 있음
- 이를 고려하기 위해 long long 타입을 선언해야 함
```