[문제 요약]

- DB는 하나의 테이블이며, 5가지 쿼리를 제공
- 5가지 쿼리는 다음과 같음

```
1. init

- 테이블 초기화
- init 형태로 주어짐
- table에 있는 모든 데이터 삭제
- 해당 쿼리는 가장 처음에 항상 주어지며, 최대 50번

2. insert

- 테이블에 새로운 데이터 추가
- insert name value 형태로 주어짐
- name과 value는 유일해야 함
- 따라서 이미 존재하는 name 혹은 value라면 0을 출력
- 새로운 name과 새로운 value의 조합이라면 테이블에 추가 후 1 출력
- name 길이 <= 10
- 1 <= value <= 10억
- 쿼리 최대 10만번

3. delete

- 테이블에서 데이터 삭제
- delete name 형태로 주어짐
- name이 없다면 0 출력
- 있다면 value 출력
- name 길이 <= 10
- 쿼리 최대 10만번

4. rank

- 테이블에서 k번째로 작은 value를 가진 row의 name을 출력
- rank k 형태로 주어짐
- 테이블이 가진 row의 수가 k보다 작다면, None을 출력
- k <= 10만
- 쿼리 최대 10만번

5. sum

- 테이블에서 k 이하의 value를 가진 row를 모두 찾아서 그들의 value 합 출력
- sum k 형태로 주어짐
- 1 <= k <= 10억
- 쿼리 최대 10만번
```

[제약 사항]

- 쿼리 총 합 최대 30만번
- name은 알파벳 대소문자로만 이루어짐

[나이브한 생각]

- name과 value를 hash map으로 관리하면 될 것 같다
- 단, name이 유일해야 하고, value도 유일해야 한다
- name -> value인 hash map이 있으면 name의 유일함은 찾을 수 있다
- value만 따로 visited 배열 혹은 hash set을 만들면 된다
- value의 범위가 10억이므로, 사이사이 빈 공간을 낭비하지 않기 위해 array 대신 hash set을 이용

- 먼저 sum 쿼리를 보자
- sum 쿼리가 빠르려면 구간합 배열을 선언해놓으면 된다
- 그런데, insert와 delete가 빈번하므로 segment tree를 활용해야 한다
- 그런데 k이하의 value를 가진 데이터들의 합을 계산해야 하므로, value를 인덱스로하는 원본 배열의 segment tree를 구성해야 한다
- value는 최대 10억이지만, 최대 10만개임 -> value를 인덱스로 하는 배열을 선언할 경우 9억9990만이 비게 됨
- 범위가 [1, 1e9]인 원본 배열의 segment tree를 구성하려면 원본 배열의 4배 수준의 메모리가 필요하므로, segment tree를 만들 수 없음
- 따라서 정적으로 segment tree의 노드를 만들어놓지 말고, 동적으로 만드는 방식을 적용해보자
- value를 인덱스로하는 가상의 원본 배열 A가 있다고 하자
- insert name 500이라는 명령을 수행해보자
- 세그먼트 트리를 만들기 위해 루트 노드에서 시작한다
- 자식 노드가 담당하는 범위가 leaf 노드일 때까지 노드를 생성하거나 수정하면서 내려가면 된다
- delete name이라는 명령을 수행해보자
- name -> value로 500을 얻는다
- 그리고 노드가 담당하는 범위가 500 500 일 때까지 내려가는 경로 상 노드의 sum 값에서 500을 빼주면 된다
- 이 Dynamic Segment Tree에서 query를 수행해보자
- query(1, k)는 1부터 k까지의 합을 계산한다
- Static Segment Tree와 동일한 구조로 계산하면 된다

- rank 쿼리를 보자
- Dynamic Segment Tree에는 value순서대로 leaf 노드가 존재한다
- 즉, value 오름차순 리스트가 있다고 생각해보자
- 그럼 k번째 값을 찾아서 그대로 리턴하면 된다
- 그런데 트리에서 k번째를 어떻게 찾아가야 하나?
- 각 노드는 자신을 루트로 하는 리프 노드의 개수를 관리하고 있다고 하자
- 왼쪽 자식의 리프 노드 개수가 k보다 작으면, 오른쪽 자식으로 내려간다
- 왼쪽 자식의 리프 노드 개수가 k보다 크거나 같으면, 왼쪽 자식으로 내려간다 
- 오른쪽 자식으로 내려갈 떄는, k가 바뀐다
- k에서 왼쪽 자식의 리프 노드 개수를 빼줘야한다

- 리프 노드의 개수는 어떻게 관리할 수 있나?
- insert시 항상 leaf 노드가 생성된다
- 따라서 insert할 때마다 leaf 노드로 내려가면서 경로 상 모든 노드의 cnt를 1 증가시키면 된다
- delete시 leaf 노드로 내려가면서 경로 상 모든 노드의 cnt를 1 감소시키면 된다

[설계]

<자료구조>

- Node 구조체
	- cnt
	- sum
	- l, r (노드가 담당하는 범위)
	- left, right (자식 포인터)

- memory pool
	- Node를 관리하는 memory pool
	- memory pool에서 동적 할당을 흉내내면 됨
	- unused를 관리하고 있어야 함
- hash map
	- name -> value
	- value -> name

<알고리즘>

1. init

- unused = 0
- hash map clear

2. insert

- hash map에서 name이 존재하면 return 0
- hash map에서 value가 존재하면 return 0
- hash map에 name->value 할당
- hash map에 value->name 할당
- Dynamic Segment Tree에 value update
- return 1

3. delete

- hash map에서 name이 존재하지 않으면 return 0
- Dynamic Segment Tree에서 value에 해당하는 leaf node 삭제(update)
- name->value 삭제
- value->name 삭제
- return value

4. rank

- hash map의 길이가 k보다 작다면, None 출력
- 그렇지 않으면, Segment Tree Traversal
- 왼쪽 자식의 리프 노드 개수가 k보다 작으면, 오른쪽 자식으로 내려간다
- 왼쪽 자식의 리프 노드 개수가 k보다 크거나 같으면, 왼쪽 자식으로 내려간다 
- 오른쪽 자식으로 내려갈 떄는, k가 바뀐다
- k에서 왼쪽 자식의 리프 노드 개수를 빼줘야한다
- 리프 노드에 도달했으면, 해당 범위(l==r==index==value)를 리턴

5. sum

- 단순히 Segment Tree에서 query(1, k) 수행


value(idx) -> Node pointer를 갖고 있어야 겠는데?



