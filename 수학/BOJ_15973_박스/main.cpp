#include <iostream>
using namespace std;

int px1, py1, px2, py2;
int qx1, qy1, qx2, qy2;

void init();
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	return 0;
}

void init() {
	cin >> px1 >> py1 >> px2 >> py2;
	cin >> qx1 >> qy1 >> qx2 >> qy2;
}

void solve() {
	if (py1 > qy2 || py2 < qy1 || px2 < qx1 || px1 > qx2) {
		cout << "NULL\n";
	}
	else if ((py2 == qy1 && px2 == qx1) || (py2 == qy1 && px1 == qx2) || (py1 == qy2 && px2 == qx1) || (py1 == qy2 && px1 == qx2)) {
		cout << "POINT\n";
	}
	else if (px2 == qx1 || px1 == qx2 || py2 == qy1 || py1 == qy2) {
		cout << "LINE\n";
	}
	else {
		cout << "FACE\n";
	}
}