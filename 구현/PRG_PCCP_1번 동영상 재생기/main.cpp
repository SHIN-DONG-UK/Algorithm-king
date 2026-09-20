#include <iostream>
#include <string>
#include <vector>
using namespace std;

string video_len, pos, op_start, op_end;
vector<string> commands;

int op_start_int, op_end_int;
int video_len_int;
int pos_int;

void init();
void solve();
void set_pos(int t);
int str_to_int(string mstr);
string int_to_str(int mint);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	init();
	solve();

	cout << int_to_str(pos_int) << '\n';

	return 0;
}

void init() {
	cin >> video_len >> pos >> op_start >> op_end;
	video_len_int = str_to_int(video_len);
	pos_int = str_to_int(pos);
	op_start_int = str_to_int(op_start);
	op_end_int = str_to_int(op_end);

	if (op_start_int <= pos_int && pos_int <= op_end_int) {
		pos_int = op_end_int;
	}

	int len;
	string tmp;
	cin >> len;
	for (int i = 0; i < len; i++) {
		cin >> tmp;
		commands.push_back(tmp);
	}
}

void solve() {
	for (auto& str : commands) {
		if (str == "next") {
			set_pos(10);
		}
		else if (str == "prev") {
			set_pos(-10);
		}
		else {
			cout << "Invalid command!\n";
		}
	}
}

void set_pos(int t) {
	pos_int += t;

	if (pos_int <= 0) {
		pos_int = 0;
	}

	else if (pos_int >= video_len_int) {
		pos_int = video_len_int;
	}

	if (op_start_int <= pos_int && pos_int <= op_end_int) {
		pos_int = op_end_int;
	}
}

int str_to_int(string mstr) {
	int rst = 0;
	rst += (mstr[0] - '0') * 10 * 60;
	rst += (mstr[1] - '0') * 60;
	rst += (mstr[3] - '0') * 10;
	rst += (mstr[4] - '0');

	return rst;
}

string int_to_str(int mint) {
	string rst;

	rst += ((mint / 60) / 10) + '0';
	rst += ((mint / 60) % 10) + '0';
	rst += ':';
	rst += ((mint % 60) / 10) + '0';
	rst += ((mint % 60) % 10) + '0';

	return rst;
}