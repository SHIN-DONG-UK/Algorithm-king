#define MAX_N 50
#define MAX_M 100

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int board[MAX_N + 1][MAX_N + 1];
int cnt;

struct Package {
	int num;
	int y, x;
	int w, h;
	bool isRemoved;

	int down_lazer() {
		int min_y = N;
		for (int j = x; j < x + w; j++) {
			
			for (int i = y + 1; i <= N; i++) {
				if (board[i][j] > 0) {
					if (min_y > i - 1) {
						min_y = i - 1;
					}
					break;
				}
			}

		}

		return min_y;
	}

	bool left_lazer() {
		for (int i = y; i > y - h; i--) {
			for (int j = x - 1; j >= 1; j--) {
				if (board[i][j] > 0) {
					return false;
				}
			}
		}

		return true;
	}

	bool right_lazer() {
		for (int i = y; i > y - h; i--) {
			for (int j = x + w; j <= N; j++) {
				if (board[i][j] > 0) {
					return false;
				}
			}
		}

		return true;
	}

	void add() {
		for (int i = y; i > y - h; i--) {
			for (int j = x; j < x + w; j++) {
				board[i][j] = num;
			}
		}
	}

	void remove() {
		for (int i = y; i > y - h; i--) {
			for (int j = x; j < x + w; j++) {
				board[i][j] = 0;
			}
		}
	}
};

Package packages[MAX_M + 1];
vector<Package*> sort_vec;
vector<Package*> ordered_vec;

void init();
void solve();

int package_getOff_left();
int package_getOff_right();

void debug_print() {
	cout << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	init();
	solve();

	return 0;
}

bool compare_num(Package* a, Package* b) {
	return a->num < b->num;
}

bool compare_y(Package* a, Package* b) {
	return a->y > b->y;
}

void init() {
	cin >> N >> M;

	int k, h, w, c;
	for (int i = 0; i < M; i++) {
		cin >> k >> h >> w >> c;
		packages[k].num = k;
		packages[k].y = 0;
		packages[k].x = c;
		packages[k].w = w;
		packages[k].h = h;
		packages[k].isRemoved = false;

		sort_vec.push_back(packages + k);
		ordered_vec.push_back(packages + k);

		int row = packages[k].down_lazer();
		packages[k].y = row;
		packages[k].add();
	}

	cnt = M;
	sort(ordered_vec.begin(), ordered_vec.end(), compare_num);
}

void solve() {
	while (cnt) {
		//debug_print();

		int number = package_getOff_left();
		if (number > 0) {
			cnt--;
			cout << number << '\n';
		}

		//debug_print();

		number = package_getOff_right();
		if (number > 0) {
			cnt--;
			cout << number << '\n';
		}

		//debug_print();
	}
}

int package_getOff_left() {
	for (Package* opt : ordered_vec) {
		if (opt->isRemoved) continue;

		if (opt->left_lazer()) {
			opt->isRemoved = true;
			opt->remove();

			sort(sort_vec.begin(), sort_vec.end(), compare_y);

			for (Package* spt : sort_vec) {
				if (spt->isRemoved) continue;

				int new_row = spt->down_lazer();
				
				if (new_row != spt->y) {
					spt->remove();
					spt->y = new_row;
					spt->add();
				}
			}

			return opt->num;
		}
	}
	return -1;
}

int package_getOff_right() {
	for (Package* opt : ordered_vec) {
		if (opt->isRemoved) continue;

		if (opt->right_lazer()) {
			opt->isRemoved = true;
			opt->remove();

			sort(sort_vec.begin(), sort_vec.end(), compare_y);

			for (Package* spt : sort_vec) {
				if (spt->isRemoved) continue;

				int new_row = spt->down_lazer();

				if (new_row != spt->y) {
					spt->remove();
					spt->y = new_row;
					spt->add();
				}
			}

			return opt->num;
		}
	}
	return -1;
}