## 💡 BOJ 10815 - 숫자카드 [[문제 링크](https://www.acmicpc.net/problem/10815)]

| 항목 | 내용 |
|------|------|
| 문제 유형 | `이분 탐색` |
| 사용 알고리즘 | `이분 탐색` |
| 난이도 | 실버5 |

### ✅ 문제 설명
- **숫자 카드 `N`개와 정수 `M`개가 주어졌을 때, 정수가 숫자 카드에 존재하는지 출력하라**

### 🔍 풀이 접근
- `N`개의 카드를 정렬하고, 인덱스를 이분 탐색한다

### 💡 핵심 로직
- 이분 탐색으로 값이 존재하면 1을 출력하고, 이분 탐색 함수가 `target`을 찾지 못하고 `false`를 반환하면 0을 출력
	
### 📌 배운 점
- 이분 탐색 기본 문제를 학습했습니다.