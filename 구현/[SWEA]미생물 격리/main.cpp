#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Mi {
    int y;
    int x;
    int num;
    int dir;
};


int N, M, K;
vector<Mi> MAP[100][100];
vector<Mi> Mis;
int ans;

void init();
void input();
void process();
void get_MAP();
void get_Mis();
int turn(int dir);

int main()
{
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        process();

        cout << "#" << tc << " " << ans << '\n';
    }
}

void init()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            MAP[i][j].clear();
        }
    }
    Mis.clear();
    ans = 0;
}

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        Mis.push_back({ a,b,c,d-1 });
    }
}

void process()
{
    for (int i = 0; i < M; i++)
    {
        get_MAP();
        get_Mis();
    }

    for (int i = 0; i < Mis.size(); i++)
    {
        ans += Mis[i].num;
    }
}

void get_MAP()
{
    Mi tmp, next;
    int len = Mis.size();
    for (int t = 0; t < len; t++)
    {
        tmp = Mis.back();
        Mis.pop_back();
        next.y = tmp.y + dy[tmp.dir];
        next.x = tmp.x + dx[tmp.dir];
        next.num = tmp.num;
        next.dir = tmp.dir;
        if (next.y == 0 || next.y == N - 1 || next.x == 0 || next.x == N - 1) {
            next.num /= 2;
            next.dir = turn(next.dir);
        }
        if(next.num != 0) 
            MAP[next.y][next.x].push_back(next);
    }
}

int turn(int dir)
{
    if (dir == 0) return 1;
    else if (dir == 1) return 0;
    else if (dir == 2) return 3;
    else return 2;
}

void get_Mis()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (MAP[i][j].size() == 0) continue;

            Mi tmp = { i,j,0,-1 };
            Mi ori;
            int max_val = 0;
            int max_dir = -1;

            int len = MAP[i][j].size();
            for (int k = 0; k < len; k++)
            {
                ori = MAP[i][j].back();
                MAP[i][j].pop_back();

                if (ori.num > max_val) {
                    max_val = ori.num;
                    max_dir = ori.dir;
                }
                tmp.num += ori.num;
            }

            tmp.dir = max_dir;

            Mis.push_back(tmp);
        }
    }
}