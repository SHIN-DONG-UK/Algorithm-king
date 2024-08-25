#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

struct Command
{
    int r;
    int c;
    int s;
};

int N, M, K;
int ORI[50][50];
int MAP[50][50];
int tMAP[50][50];
vector<Command> commands;
int a[6];
int visited[6];
int ans = 1e9;


void input();
void init();
void go(int idx);
void rotate(int r, int c, int s);
int calc();

int main()
{
    input();
    go(0);

    cout << ans << '\n';
    return 0;
}

void init()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            MAP[i][j] = ORI[i][j];
        }
    }
}

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> ORI[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        commands.push_back({ r,c,s });
    }
}

void go(int idx)
{
    if (idx == K)
    {
        init();
        for (int i = 0; i < K; i++)
        {
            Command command = commands[a[i]];
            rotate(command.r - 1, command.c - 1, command.s);
        }

        int tmp = calc();
        if (ans > tmp) ans = tmp;
        return;
    }
    for (int i = 0; i < K; i++)
    {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        a[idx] = i;
        go(idx + 1);
        visited[i] = 0;
    }
}

void rotate(int r, int c, int s)
{
    memset(tMAP, 0, sizeof(tMAP));

    for (int k = 0; k < s; k++)
    {
        int y = r - s + k;
        int x = c - s + k;
        int d = 0;

        while (true)
        {
            if (y == r - s + k && x == c + s - k) d++;
            else if (y == r + s - k && x == c + s - k) d++;
            else if (y == r + s - k && x == c - s + k) d++;

            int ny = y + dy[d];
            int nx = x + dx[d];

            tMAP[ny][nx] = MAP[y][x];
            y = ny; x = nx;
            if (y == r - s + k && x == c - s + k) break;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tMAP[i][j] != 0) MAP[i][j] = tMAP[i][j];
        }
    }
}

int calc()
{
    int min_val = 1e9;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += MAP[i][j];
        }
        if (min_val > sum) min_val = sum;
    }
    return min_val;
}