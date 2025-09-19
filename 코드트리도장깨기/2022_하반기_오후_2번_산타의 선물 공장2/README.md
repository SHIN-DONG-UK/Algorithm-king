# 1. 이해

```
[문제 요약]

- 산타의 선물 공장에 이어서...
- 각 벨트의 정보와 선물의 정보를 조회할 수 있는 기능들을 추가하여 새로운 공장을 만들고자 한다

1. 공장 설립
    - 선물 공장에 n개의 벨트를 설치하고, 총 m개의 물건을 준비한다
    - m개의 선물의 위치가 공백을 사이에 두고 주어진다
    - 각 선물의 번호는 오름차순으로 벨트에 쌓인다

2. 물건 모두 옮기기
    - m_src번째 벨트에 있는 선물들을 모두 m_dst번째 벨트의 선물들로 옮긴다
    - 옮겨진 선물들은 m_dst 벨트 앞에 위치한다
    - 만약 m_src번째 벨트에 선물이 존재하지 않다면 아무 것도 하지 않는다
    - 옮긴 뒤에 m_dst번째 벨트에 있는 선물들의 개수를 출력한다

3. 앞 물건만 교체하기
    - m_src번째 벨트에 있는 선물 중 가장 앞에 있는 선물을 m_dst번째 벨트의 선물들 중 가장 앞에 있는 선물과 교체한다
    - 둘 중 하나의 벨트에 선물이 아예 존재하지 않다면 교체하지 않고 해당 벨트로 선물을 옮기기만 한다
    - 옮긴 뒤에 m_dst번째 벨트에 있는 선물들의 개수를 출력한다

4. 물건 나누기
    - m_src번째 벨트에 있는 선물들의 개수를 n이라고 할 때 가장 앞에서 floor(n/2)번째까지 있는 선물을 m_dst번째 벨트 앞으로 옮긴다
    - 만약 m_src 벨트에 선물이 1개인 경우에는 선물을 옮기지 않는다
    - 당연히 0개면 아무것도 안하겠죠?
    - 옮긴 뒤에 m_dst 번째 벨트에 있는 선물들의 개수를 출력한다

5. 선물 정보 얻기
    - 선물 번호 p_num이 주어질 때, 해당 선물의 앞 선물의 번호 a와 뒤 선물 번호 b라 할때 a + 2 * b를 출력한다
    - 만약 앞 선물이 없는 경우에는 a = -1
   - 뒤 선물이 없는 경우에도 b = -1

6. 벨트 정보 얻기
    - 벨트 번호 b_num이 주어질 때, 해당 벨트의 맨 앞에 있는 선물의 번호를 a, 맨 뒤에 있는 선물의 번호를 b, 해당 벨트에 있는 선물의 개수를 c라고 할 때, a + 2 * b + 3 * c의 값을 출력한다
    - 선물이 없는 벨트의 경우 a == b == -1이다

- q번에 걸쳐 명령을 순서대로 진행하며 원하는 결과를 출력하라

[제약 사항]

- q <= 100,000
- 물건 나누기 명령은 최대 100번만 주어진다
- 선물의 개수 n <= 100,000
- 벨트의 개수 m <= 100,000
```

# 2. 설계

```
[나이브한 생각]

- 산타의 선물 공장 문제처럼 linked-list를 잘 구현하면 됨

[설계]

- 상자 구조체
    - num
    - *prev
    - *next

- m개의 상자 정보를 저장할 배열

- Head, Tail
    - n개의 벨트가 존재하므로 각각 최대 n개 필요

- 각 벨트의 상자 개수
    - 최대 길이 n

- 임시 벡터
    - 벨트 내의 상자끼리 링킹을 위한 임시 배열을 만든다

[알고리즘]

1. 공장 설립
    - m번 loop를 돈다
    - 상자 정보를 업데이트한다
    - 임시 벡터에 상자들을 넣는다
    - 임시 벡터를 돌면서 링킹작업을 한다
    - Head와 Tail도 업데이트한다
    - 각 벨트의 상자 개수도 업데이트한다

2. 물건 모두 옮기기
  - m_src 벨트의 개수가 0이면 아무것도 안한다
  - m_src번째 벨트의 리스트를 m_dst 번째 벨트의 앞에 옮긴다
    - 일단 m_src번째 리스트를 돌면서 belt 정보를 m_dst로 update한다
    - 그리고 Head[m_dst]->prev를 Tail[m_src]로 한다
    - Tail[m_src]->next = Head[m_dst]로 한다
    - Head[m_dst] = Head[m_src]로 바꾼다
    - m_src에 있는 물건 개수를 m_dst에 합친다
    - 그리고 count[m_src]=0으로 초기화한다
    - Head[m_src] = Tail[m_src] = nullptr로 초기화한다
    - count[m_dst]를 출력한다
    - (주가) 케이스 쪼개줘야 함 -> m_dst가 비어있는 경우 or 아닌경우

3. 앞 물건만 교체하기
   - 이거 케이스를 나눠야하지 않나?
    - (주가) 둘 다 0인 경우 -> 아무것도 하지 않는다
    - m_src가 0인 경우
        - pt = Head[m_dst]로 복사해둔다
        - Head[m_dst]->next를 Head로 한다
        - 그리고 Head->prev = nullptr로 초기화한다
        - count[m_dst]에서 1뺸다
        - Head[m_src] = Tail[m_src] = pt다
        - pt->prev = pt->next = nullptr;로 초기화한다
        - count[m_src]에 1 더한다

    - m_dst가 0인 경우
        - pt = Head[m_src]로 복사해둔다
        - Head[m_src]->next를 Head로 한다
        - 그리고 Head->prev = nullptr로 초기화한다
        - count[m_src]에서 1뺀다
        - Head[m_dst] = Tail[m_dst] = pt다
        - pt->prev = pt->next = nullptr이다
        - count[m_dst]에 1 더한다

    - 둘 다 0이 아닌경우
        - pt = Head[m_dst]->next로 복사해둔다
        - Head[m_dst]->next = Head[m_src]->next로 바꾼다
        - Head[m_src]->next = pt로 바꾼다
        - 그리고 Head[m_dst]와 Head[m_src]를 swap한다
        - count 배열은 바뀌지 않는다
        - prev도 바뀌지 않는다 next만 바뀐다
    
  - count[m_dst]를 출력한다

4. 물건 나누기
      - 만약 count[m_src] <= 1이면 안한다
    - count[m_src]/2 를 tmp라고 하자
    - Head[m_src]부터 count[m_src]/2번째를 찾는다
      - 찾은게 tail라고하자
      - 기존 Head[m_src]를 head에 저장해놓자


     - (추가) 케이스 쪼개기 -> dst가 비어있는 경우 or 아닌 경우

      - tail->next가 새로운 Head가 된다
      - tail->next->prev = nullptr로 한다
     - Head[m_src] = tail->next다

    - 비어있으면
        - tail->next를 nullptr로 바꾸고
        - head와 tail을 그대로 벨트의 Head와 Tail로 한다
    - 그렇지 않으면


      - tail->next = Head[m_dst]다
      - Head[m_dst]->prev = tail이다
      - head가 m_dst의 새로운 Head가 된다

      - count[m_src] -= tmp한다
      - count[m_dst] += tmp한다


5. 선물 정보 얻기
    - 박스 번호로 박스 배열에 접근하자
    - pt->prev == nullptr이면 a = -1 아니면 a = pt->prev->num
    - pt->next == nullptr이면 b = -1 아니면 b = pt->next->num
    - a + 2 * b를 출력한다

6. 벨트 정보 얻기
    - count[b_num] == 0이다 -> a = -1, b = -1, c = 0
  - 그렇지 않으면 a = Head[b_num]->num / b = Tail[b_num]->num / c = count[b_num]
  - a + 2b + 3c를 출력

```