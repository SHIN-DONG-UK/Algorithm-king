## 💡 BOJ 20057 - 마법사 상어와 토네이도[[문제 링크](https://www.acmicpc.net/problem/20057)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `구현`, `시뮬레이션` |
| 사용 알고리즘 | `` |
| 난이도 | `골드3` |

### ✅ 문제 설명
- **주어지는 시뮬레이션을 구현하는 문제**

### 🔍 풀이 접근
문제 상황을 그대로 코드로 구현하면 될 것같다.

구현해야하는 것은

1. 달팽이 모양으로 이동하기
2. spread 함수 구현하기

여기서 spread 함수는 토네이도에 의해 모래가 흩뿌려지는 것을 구현하는 함수다.

먼저 달팽이 모양이 어떻게 구현되어야 하는지 살펴보자. 달팽이 모양을 자세히 살펴보면

`좌하 우우상상 좌좌좌하하하 우우우우상상상상...`

이런 식으로 반복된다. 이런 구성을 만드는 반복문을 작성하면 아래와 같다.

```cpp
while(1){
	for 2번 {
    	for k번 {
        	위치 업데이트;
            spread 함수;
        }
        방향 업데이트;
    }
    k 업데이트(+1);
}
```
이제 spread 함수를 구현해보자. 먼저 spread 함수의 시그니처는

```cpp
spread(int y, int x, int d);
```
정도면 될 것같다.

이제 방향별로 토네이도 모양을 따라 비율 계산을 할 수 있도록 해야한다. 사실 떠오른게 하드코딩밖에 없다. 그래서 방향별로(d=0,1,2,3) 이동량을 다 정해놓고, 반복문을 통해 해당 칸들을 접근해서 계산을 때리자. 그리고 맵 밖으로 나간 애들을 더해나가면 정답을 구할 수 있다.

### 💡 핵심 로직
- 달팽이 모양으로 이동하는 반복문

### 📌 배운 점
- 달팽이 모양으로 움직이기

- 하드코딩으로 주어지는 문제 구현하기