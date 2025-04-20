#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Point {
	int y;
	int x;
};

struct CCTV {
	Point pos;
	int num;
};

// 우 하 좌 상
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int N, M;
int min_val;

int arr[10][10];
int practice[10][10];
int visited[10][10];

vector<vector<int>> num_to_dir;
vector<CCTV> cctvs;
int path[8]; // 회전량 저장 배열

void input();
void BruteForce(int index);
void watch(Point p, int dir);
void my_copy();
int get_blind();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	input();
	BruteForce(0);

	cout << min_val << '\n';
	return 0;
}

void input()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] > 0 && arr[i][j] != 6) {
				cctvs.push_back({ i, j, arr[i][j] });
			}
		}
	}

	//벽 표시
	for (int j = 0; j <= M + 1; j++)
	{
		arr[0][j] = 6;
		arr[N + 1][j] = 6;
	}
	for (int i = 0; i <= N + 1; i++)
	{
		arr[i][0] = 6;
		arr[i][M + 1] = 6;
	}

	//init
	vector<int> tmp = {0};
	num_to_dir.push_back(tmp); // 0번 -> dummy
	num_to_dir.push_back(tmp); // 1번 -> {0}
	tmp = { 0, 2 };
	num_to_dir.push_back(tmp); // 2번 -> {0,2}
	tmp = { 0, 3 };
	num_to_dir.push_back(tmp); // 3번 -> {0,3}
	tmp = { 0, 2, 3 };
	num_to_dir.push_back(tmp); // 4번 -> {0, 2, 3}
	tmp = { 0, 1, 2, 3 };
	num_to_dir.push_back(tmp); // 5번 -> {0, 1, 2, 3 }
	min_val = ((1 << 31) - 1);

}

//뼈대
void BruteForce(int index) {
	if (index == cctvs.size()) {

		my_copy(); // original 맵 복사
		memset(visited, 0, sizeof(visited)); // visited 초기화

		for (int i = 0; i < cctvs.size(); i++)
		{
			int num = cctvs[i].num;
			int amount = path[i];
			for (int j = 0; j < num_to_dir[num].size(); j++)
			{
				int dir = (num_to_dir[num][j] + amount) % 4;
				// 해당 방향으로 감시 진행
				watch(cctvs[i].pos, dir);
			}
		}

		int tmp = get_blind();
		if (min_val > tmp)
			min_val = tmp;

		return;
	}

	for (int d = 0; d < 4; d++)
	{
		path[index] = d;
		BruteForce(index + 1);
	}

}

void my_copy()
{
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			practice[i][j] = arr[i][j];
		}
	}
}

void watch(Point p, int dir)
{
	visited[p.y][p.x] = 1;
	//벽이 아닐때까지 dir방향으로 방문처리
	while (practice[p.y][p.x] != 6) {
		p.y += dy[dir];
		p.x += dx[dir];
		visited[p.y][p.x] = 1;
	}
}

int get_blind() 
{
	int rst = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (practice[i][j] != 6 && visited[i][j] == 0)
				rst++;
		}
	}
	return rst;
}