# 1. 이해

```
[조건]
- N개의 자연수와 자연수 M
- N개의 자연수 중에서 M개를 고른 수열을 모두 출력하라

[입력]
N M
N개의 수

[출력]
- 수열은 오름차순 출력
- 중복되는 수열을 여러 번 출력하면 안됨
```

# 2. 설계

```
1. 일단 순열을 구한다.
2. 그리고 컷 한다
	- 같은 lev에서 사용된 숫자는 다시 사용하지 못하도록 하면 된다
	- 그러기 위해서는 하나의 visited를 더 선언하면 될 것같다
```