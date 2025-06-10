#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, K;
		cin >> N >> K;
		string num;
		cin >> num;

		unordered_map<int, bool> visited;
		vector<int> possible_nums;

		// [Logic]
		int len = N / 4;
		for (int k = 0; k < len; k++) {
			//1. k번째 회전
			char tmp = num[N - 1];
			for (int i = N - 1; i >= 1; i--) {
				num[i] = num[i- 1];
			}
			num[0] = tmp;

			//2. 슬라이싱
			for (int i = 0; i < N; i += len) {
				string stmp;
				for (int j = i; j < i + len; j++) {
					stmp += num[j];
				}
				//3. 16 -> 10진수
				int dec = 0;
				for (int j = 0; j < len; j++) {
					if (stmp[j] >= 'A' && stmp[j] <= 'F')
						dec = dec * 16 + stmp[j] - 'A' + 10;
					else if (stmp[j] >= '0' && stmp[j] <= '9')
						dec = dec * 16 + stmp[j] - '0';
				}
				if (visited[dec]) continue;
				visited[dec] = true;

				possible_nums.push_back(dec);
			}
		}
		
		//4. 내림차순 정렬
		sort(possible_nums.begin(), possible_nums.end(), greater<>());

		//5. 정답 출력
		cout << '#' << tc << ' ' << possible_nums[K - 1] << '\n';
	}
	return 0;
}
