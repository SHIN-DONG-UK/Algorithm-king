# 1. 이해

```
R : 뒤집기 -> 순서 뒤집기
D : 버리기 -> 첫 번째 수 버리기(비어있는데 사용하면 에러)

[출력]
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과 출력
```
# 2. 설명

```
[구현]
1. 커맨드를 입력받아야 함
	-> string으로 입력받고, 문자열을 순회하면서 조건문으로 커맨드를 처리하자
	
2. 숫자 배열을 입력받아야 함
	-> 숫자가 띄어쓰기로 구분되지 않고, [1,2,3,4] 형식으로 입력됨
	-> string으로 입력받고, parsing을 수행해야 함
	
3. deque()로 요소 삭제를 구현하자
	-> 뒤집기를 실제로 수행하게 되면 시간초과가 일어날것이라 예상
	-> 그래서 양끝에서 삭제를 O(1)에 구현할 수 있는 deque() 자료구조를 사용

4. 뒤집기 구현
	-> 실제로 뒤집지 않고, 앞에서 삭제할지 뒤에서 삭제할지 플래그를 저장해놓고
	플래그에 따라 앞뒤 방향 정해주기

5. 출력 구현
	-> deque()에 요소가 없으면 대괄호만 출력해야 함
	-> 뒤집은 방향에 따라 출력순서가 달라야 함
```