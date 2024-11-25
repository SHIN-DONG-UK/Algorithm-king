# 1. 이해

```
주어진대로 구현하면 됨
```

# 2. 설계

```
재귀함수로 Z모양 탐색을 하면 되지 않을까?
```

# 3. 코드

```cpp
#include <iostream>

using namespace std;

int N, r, c;
int ans, cnt;
bool flag;

int two[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
void go(int raw, int column, int n);

int main() {
	cin >> N >> r >> c;

	go(0, 0, N);

	cout << ans << '\n';
}
void go(int start_y, int start_x, int n) {
	if (flag)
		return;
	if (n == 0) {
		cnt++;
		return;
	}

	for (int i = start_y; i < start_y + two[n]; i += two[n - 1]) {
		for (int j = start_x; j < start_x + two[n]; j += two[n - 1]) {
			if (i == r && j == c) {
				ans = cnt;
				flag = true;
			}

			go(i, j, n - 1);
		}
	}
}
```

- 근데 이거 시간초과남
- 굳이 for문 탐색해서 하나하나 검사할 필요 없음
- like 이분탐색처럼 풀면 됨

# 4. 수정된 코드

![image.png](https://prod-files-secure.s3.us-west-2.amazonaws.com/f0d09fab-f760-445a-969a-74459f3b88cd/c6da2d08-fc5a-4b6a-a1d0-b1d360c389b2/image.png)

```cpp
#include <iostream>

using namespace std;

int N, r, c;
int ans, cnt;
bool flag;

int two[16] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };

void go(int raw, int column, int n);

int main() {
	cin >> N >> r >> c;

	cnt += (two[N] / 2) * (two[N] / 2) * 3;
	go(two[N] /2, two[N] / 2, two[N] / 2);

	cout << cnt << '\n';
}

void go(int y, int x, int n) {
	if (flag)
		return;

	if (y == r && x == c) {
		flag = true;
		return;
	}

	// 1사분면?
	if (r < y && c < x) {
		// go
		cnt -= n * n * 3;
		cnt += (n / 2) * (n / 2) * 3;
		if(n == 1)
			go(y - 1, x - 1, n / 2);
		else
			go(y - n / 2, x - n / 2, n / 2);
	}

	// 2사분면
	else if (r < y && c >= x) {
		// go
		cnt -= n * n * 2;
		cnt += (n / 2) * (n / 2) * 3;
		if (n == 1)
			go(y - 1, x, n / 2);
		else
			go(y - n / 2, x + n / 2, n / 2);
	}
	// 3사분면
	else if (r >= y && c < x) {
		// go
		cnt -= n * n;
		cnt += (n / 2) * (n / 2) * 3;
		if (n == 1)
			go(y, x - 1, n / 2);
		else
			go(y + n / 2, x - n / 2, n / 2);
	}
	// 4사분면
	else {
		// go
		cnt += (n / 2)*(n / 2) * 3;
		go(y + n / 2, x + n / 2, n / 2);
	}
}
```

- 이런 식으로 이분 탐색처럼 중심점을 찾아가면 원하는 점을 찾을 수 있음
- 이 과정에서 몇 개의 칸을 지나왔는지는 그냥 수식으로 계산할 수 있음