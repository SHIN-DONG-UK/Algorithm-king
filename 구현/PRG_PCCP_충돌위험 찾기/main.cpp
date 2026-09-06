#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

vector<vector<int>> points;
vector<vector<int>> routes;

map<tuple<int, int, int>, int> cnt;

vector<tuple<int, int, int>> get_path(int t_offset, int aIdx, int bIdx);

void init();
int solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	int answer = solve();

	cout << answer << '\n';
	return 0;
}

void init() {
	int n, m;
	int r, c;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> r >> c;
		vector<int> tmp;
		tmp.push_back(r);
		tmp.push_back(c);

		points.push_back(tmp);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		int l;
		cin >> l;

		int k;
		vector<int> tmp;
		for (int j = 0; j < l; j++) {
			cin >> k;
			tmp.push_back(k);
		}

		routes.push_back(tmp);
	}
}

vector<tuple<int, int, int>> get_path(int t_offset, int aNum, int bNum) {
	vector<tuple<int, int, int>> rst;

	// 1. r 변화
	vector<int> aP = points[aNum - 1];
	vector<int> bP = points[bNum - 1];

	if (aP[0] > bP[0]) {
		// 줄어들게
		for (int i = aP[0] - 1; i >= bP[0]; i--) {
			tuple<int, int, int> ppoint = { ++t_offset, i, aP[1] };
			rst.push_back(ppoint);
		}
	}
	else if (aP[0] < bP[0]) {
		// 늘어나게
		for (int i = aP[0] + 1; i <= bP[0]; i++) {
			tuple<int, int, int> ppoint = { ++t_offset, i, aP[1] };
			rst.push_back(ppoint);
		}
	}

	// 2. c 변화
	if (aP[1] > bP[1]) {
		// 줄어들게
		for (int j = aP[1] - 1; j >= bP[1]; j--) {
			tuple<int, int, int> ppoint = { ++t_offset, bP[0], j};
			rst.push_back(ppoint);
		}

	}
	else if (aP[1] < bP[1]) {
		// 늘어나게
		for (int j = aP[1] + 1; j <= bP[1]; j++) {
			tuple<int, int, int> ppoint = { ++t_offset, bP[0], j };
			rst.push_back(ppoint);
		}
	}

	return rst;
}

int solve() {
	// 1. 중복 위치 카운팅
	for (vector<int>& route : routes) {
		int t_offset = 0;
		
		int start_point_num = route[0];
		int start_point_r = points[start_point_num - 1][0];
		int start_point_c = points[start_point_num - 1][1];

		tuple<int, int, int> first = { t_offset, start_point_r, start_point_c };
		
		cnt[first]++;

		for (int i = 0; i < route.size() - 1; i++) {
			vector<tuple<int, int, int>> path = get_path(t_offset, route[i], route[i + 1]);

			for (auto& t : path) {
				cnt[t]++;
			}

			t_offset += path.size();
		}
	}

	// 2. 중복 개수 확인
	int rst = 0;
	
	for (auto it = cnt.begin(); it != cnt.end(); it++) {
		if (it->second >= 2) {
			rst++;
		}
	}

	return rst;
}