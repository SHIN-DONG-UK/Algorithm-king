#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
	int num;
	int like;
	int last;
};

int N, q;
Student students[101];
Student* frame[20];
int totalNum;

void init();
void simulation();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	simulation();

	return 0;
}

void init() {
	cin >> N;
	cin >> q;
}

bool compare(Student*& a, Student*& b) {
	return a->num < b->num;
}

void simulation() {
	int num;
	int timestamp = 0;
	while (q--) {
		cin >> num;
		if (students[num].num == 0) {
			totalNum++;
		}
		students[num].num = num;
		students[num].like++;

		bool flag = false;

		int targetIdx = -1;
		int miniLike = 1e9;
		int old = 1e9;

		for (int i = 0; i < N; i++) {
			//비어있으면 넣는다
			if (frame[i] == nullptr) {
				frame[i] = &students[num];
				frame[i]->last = ++timestamp; //이미 있는 학생이 아니기때문에 last update
				flag = true;
				break;
			}
			//프레임에 있는 학생이면 like만 +1한다
			else if (frame[i]->num == num) {
				flag = true; //이미 있는 학생이므로 last update x
				break;
			}
			else {
				if (miniLike > frame[i]->like) {
					targetIdx = i;
					miniLike = frame[i]->like;
					old = frame[i]->last;
				}
				else if (miniLike == frame[i]->like) {
					if (old > frame[i]->last) {
						targetIdx = i;
						old = frame[i]->last;
					}
				}
			}
		}
		//비어있는 사진틀이 없다 && frame에 없는 학생이다
		if (!flag) {
			frame[targetIdx]->like = 0;
			frame[targetIdx] = &students[num];
			frame[targetIdx]->last = ++timestamp; //last update
		}
	}

	if (totalNum >= N) {
		sort(frame, frame + N, compare); //N개가 다 안채워질 수도 있나?

		for (int i = 0; i < N; i++) {
			cout << frame[i]->num << ' ';
		}
		cout << '\n';
	}
	else {
		sort(frame, frame + totalNum, compare);

		for (int i = 0; i < totalNum; i++) {
			cout << frame[i]->num << ' ';
		}
		cout << '\n';
	}

}