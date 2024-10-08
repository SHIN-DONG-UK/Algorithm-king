// [오답노트] 1
// map과 tmp_map 두 개를 사용해서 왔다갔다 하고 있다
// 이 과정에서 tmp_map에 반영된 결과를 map에 업데이트하지 않거나, 그 반대의 경우 오답이 발생
// 이 부분은 올해 상반기 1번 문제에서도 활용되었다
// 따라서 둘 간의 업데이트가 예외가 없도록 주의해야 한다

// [오답노트] 2
// 계산의 결과가 내가 생각한 범위를 넘을 수 있음
// 검증 제대로 할 것

#include <iostream>
#include <vector>

#define MAX_MAP 50
using namespace std;

struct Point {
	int y;
	int x;
};

struct Atom {
	int m;
	int s;
	int d;
};

// 상 우상 우 우하 하 좌하 좌 좌상
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

vector<Atom> map[MAX_MAP][MAX_MAP];
vector<Atom> map_tmp[MAX_MAP][MAX_MAP];
int N, M, K;

void Input();
void Simulation();

void MoveAtoms();
void MoveAtom(Point p); // -> map_tmp에 반영 // OK
void AddAtoms(); // -> map에 반영
int CalcMass();

int main() {
	Input();
	Simulation();

	return 0;
}

void Input() {
	cin >> N >> M >> K;
	
	int x, y, m, s, d;
	for (int i = 0; i < M; i++)
	{
		cin >> y >> x >> m >> s >> d;
		map[y - 1][x - 1].push_back({ m,s,d });
	}
}

void Simulation() {
	for (int i = 0; i < K; i++)
	{
		MoveAtoms();
		AddAtoms();
	}
	cout << CalcMass() << '\n';
}



void MoveAtoms() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].size() > 0) {
				MoveAtom({ i,j });
			}
		}
	}
}

void MoveAtom(Point p) {
	Point np;
	Atom atom;

	// map에 있던 atom 다 빼고, map_tmp에 일단 다 집어넣어
	int len = map[p.y][p.x].size();
	for (int i = len-1; i >= 0; i--)
	{
		atom = map[p.y][p.x].back();
		map[p.y][p.x].pop_back();
		np = { (p.y + dy[atom.d] * atom.s + 100*N) % N, (p.x + dx[atom.d] * atom.s + 100*N) % N};
		map_tmp[np.y][np.x].push_back(atom);
	}

}

void AddAtoms() {
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map_tmp[i][j].size() == 0) continue;
			else if (map_tmp[i][j].size() == 1) {
				Atom atom = map_tmp[i][j].back();
				map_tmp[i][j].pop_back();
				map[i][j].push_back(atom);
			}
			else {
				bool flag = true;

				Atom atom = map_tmp[i][j].back();
				map_tmp[i][j].pop_back();

				int tar_m = atom.m;
				int tar_s = atom.s;
				int std_d = atom.d;

				int len = map_tmp[i][j].size();

				for (int k = len - 1; k >= 0; k--)
				{
					atom = map_tmp[i][j].back();
					map_tmp[i][j].pop_back();

					if (atom.d % 2 != std_d % 2)
						flag = false;

					tar_m += atom.m;
					tar_s += atom.s;
				}

				tar_m /= 5;
				if (tar_m == 0) continue; // 해당 합성은 종료되었음.
				tar_s /= (len + 1);

				if (flag) {
					// 상하좌우
					for (int d = 0; d < 8; d += 2)
						map[i][j].push_back({ tar_m, tar_s, d });
				}
				else {
					// 대각선
					for (int d = 1; d < 8; d += 2)
						map[i][j].push_back({ tar_m, tar_s, d });
				}
			}
			
		}
	}
}

int CalcMass() {
	int rst = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j].size() > 0) {
				for (int k = 0; k < map[i][j].size(); k++)
				{
					rst += map[i][j][k].m;
				}
			}
		}
	}
	return rst;
}