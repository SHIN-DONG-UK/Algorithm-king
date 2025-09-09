#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int y;
	int x;
};

const int MX = 9;
int arr[MX][MX];
vector<Point> candi;

void init();
bool go(int index);
bool check(Point& p);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init();

	if (go(0)) {
		for (int i = 0; i < MX; i++) {
			for (int j = 0; j < MX; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << '\n';
	}

	return 0;
}

void init() {
	for (int i = 0; i < MX; i++) {
		for (int j = 0; j < MX; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) 
				candi.push_back({ i, j });
		}
	}
}

bool go(int index) {
	if (index == candi.size()) {
		return true;
	}

	Point p = candi[index];
	for (int i = 1; i <= 9; i++) {
		arr[p.y][p.x] = i;
		if (check(p)) {
			if (go(index + 1)) return true;
		}
		arr[p.y][p.x] = 0;
	}
	return false;
}

bool check(Point& p) {
	//행검사
	for (int j = 0; j < p.x; j++) {
		if (arr[p.y][j] == arr[p.y][p.x]) return false;
	}
	for (int j = p.x + 1; j < MX; j++) {
		if (arr[p.y][j] == arr[p.y][p.x]) return false;
	}

	//열검사
	for (int i = 0; i < p.y; i++) {
		if (arr[i][p.x] == arr[p.y][p.x]) return false;
	}
	for (int i = p.y + 1; i < MX; i++) {
		if (arr[i][p.x] == arr[p.y][p.x]) return false;
	}

	//9칸 검사
	int sy = 3 * (p.y / 3);
	int sx = 3 * (p.x / 3);
	for (int i = sy; i < sy + 3; i++) {
		for (int j = sx; j < sx + 3; j++) {
			if (i != p.y && j != p.x) {
				if (arr[i][j] == arr[p.y][p.x]) return false;
			}
		}
	}

	return true;
}