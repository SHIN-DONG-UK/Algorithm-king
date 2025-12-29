#include <iostream>
#include <string>
using namespace std;

int N;
string block = "____";
const string sline1 = "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
const string sline2 = "\"재귀함수가 뭔가요?\"";
const string sline3 = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
const string sline4 = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
const string sline5 = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";
const string sline6 = "라고 답변하였지.";

void init();
void go(int idx);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();

	cout << sline1 << '\n';

	go(0);

	return 0;
}

void init() {
	cin >> N;
}

void go(int idx) {
	if (idx == N) {
		for (int i = 0; i < idx; i++) {
			cout << block;
		}
		cout << sline2 << '\n';

		for (int i = 0; i < idx; i++) {
			cout << block;
		}
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";

		for (int i = 0; i < idx; i++) {
			cout << block;
		}
		cout << sline6 << '\n';
		return;
	}

	for (int i = 0; i < idx; i++) {
		cout << block;
	}
	cout << sline2 << '\n';
	for (int i = 0; i < idx; i++) {
		cout << block;
	}
	cout << sline3 << '\n';
	for (int i = 0; i < idx; i++) {
		cout << block;
	}
	cout << sline4 << '\n';
	for (int i = 0; i < idx; i++) {
		cout << block;
	}
	cout << sline5 << '\n';
	
	go(idx + 1);
	for (int i = 0; i < idx; i++) {
		cout << block;
	}
	cout << sline6 << '\n';
}