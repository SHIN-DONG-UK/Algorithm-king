#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#define MAX_N 20
using namespace std;

int N, X;
int map[MAX_N + 2][MAX_N + 2];
int visited[MAX_N + 2][MAX_N + 2];
int ans;

void Init();
void Input();
int Solve();

int main() {

	//freopen("sample_input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		Init();
		Input();
		int tmp = Solve();
		cout << '#' << tc << ' ' << tmp << '\n';
	}


	return 0;
}

void Init() {
	memset(visited, 0, sizeof(visited));
	ans = 0;
}

void Input() {
	cin >> N >> X;
	for (int j = 0; j <= N + 1; j++) {
		map[0][j] = -1;
		map[N + 1][j] = -1;
	}
	for (int i = 0; i <= N + 1; i++) {
		map[i][0] = -1;
		map[i][N + 1] = -1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

}

int Solve() {
	int rst = 0;
	// 세로 검사
	for (int j = 1; j <= N; j++)
	{
		int flag = 0;
		int i;
		for (i = 1; i <= N; i++)
		{
			int diff = map[i][j] - map[i + 1][j];
			// diff == 1 -> 내려가는거죠
			if (diff == 1) {
				// 검사 방향때문에
				// (i+1, j)부터 시작해가지고 X칸 검사합니다
				int k;
				for (k = 0; k < X; k++) {
					if (map[i + 1][j] != map[i + 1 + k][j] || map[i+1+k][j] == -1) {
						flag = 1;
						break;
					}
				}
				if (k == X) {
					// 경사로 설치 완료
					for (int k = 0; k < X; k++)
						visited[i + 1 + k][j] = 1;
					// 위치 업데이트
					i += k - 1;
				}
			}
			// diff == -1 -> 올라가는거
			else if (diff == -1) {
				// (i, j)부터 시작해서 위로 X칸 검사
				int k;
				for (k = 0; k < X; k++) {
					if (map[i][j] != map[i - k][j] || map[i-k][j] == -1) {
						flag = 1;
						break;
					}
						
					if (visited[i - k][j]) {
						flag = 1;
						break;
					}
						
				}
				if (k == X) {
					// 경사로 설치 완료
					for (int k = 0; k < X; k++)
						visited[i - k][j] = 1;
				}
			}
			else if (diff == 0)
				continue;
			else{
				if (map[i + 1][j] != -1)
					flag = 1;
				break;
			}

			if (flag)
				break;
		}

		if (!flag)
			rst++;
	}

	memset(visited, 0, sizeof(visited));

	// 가로 검사
	for (int i = 1; i <= N; i++)
	{
		int flag = 0;
		int j;
		for (j = 1; j <= N; j++)
		{
			int diff = map[i][j] - map[i][j + 1];
			// diff == 1 -> 내려가는거죠
			if (diff == 1) {
				// 검사 방향때문에
				// (i+1, j)부터 시작해가지고 X칸 검사합니다
				int k;
				for (k = 0; k < X; k++) {
					if (map[i][j + 1] != map[i][j + 1 + k] || map[i][j+1+k] == -1) {
						flag = 1;
						break;
					}

				}
				if (k == X) {
					// 경사로 설치 완료
					for (int k = 0; k < X; k++)
						visited[i][j + 1 + k] = 1;
					// 위치 업데이트
					j += k - 1;
				}
			}
			// diff == -1 -> 올라가는거
			else if (diff == -1) {
				// (i, j)부터 시작해서 위로 X칸 검사
				int k;
				for (k = 0; k < X; k++) {
					if (map[i][j] != map[i][j - k] || map[i][j-k] == -1) {
						flag = 1;
						break;
					}

					if (visited[i][j - k]) {
						flag = 1;
						break;
					}

				}
				if (k == X) {
					// 경사로 설치 완료
					for (int k = 0; k < X; k++)
						visited[i][j - k] = 1;
				}
			}
			else if (diff == 0)
				continue;
			else {
				if(map[i][j+1] != -1)
					flag = 1;
				break;
			}
			if (flag)
				break;
		}

		if (!flag)
			rst++;
	}

	return rst;
}