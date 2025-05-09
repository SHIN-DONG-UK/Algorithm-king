
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define START 0
#define END 101
using namespace std;

struct Point {
	int y;
	int x;
};

int T, N;
int graph[102][102]; // 인접행렬방식
Point sp, ep;
Point way_list[101];
int visited[102];

void Init();
void Input();
int CalcDist(Point p1, Point p2);
void Bfs();

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		Init();
		Input();
		Bfs();

		if (visited[END] == 1)
			cout << "happy\n";
		else
			cout << "sad\n";
	}
	
	return 0;
}

void Init() {
	memset(visited, 0, sizeof(visited));
	memset(graph, 0, sizeof(graph));

}
void Input() {
	cin >> N;
	// start
	cin >> sp.y >> sp.x;
	// way
	for (int i = 1; i <= N; i++)
		cin >> way_list[i].y >> way_list[i].x;
	// end
	cin >> ep.y >> ep.x;

	// start to way
	int dist;
	for (int i = 1; i <= N; i++) {
		dist = CalcDist(sp, way_list[i]);
		if (dist > 1) continue;
		graph[START][i] = dist;
		graph[i][START] = dist;
	}
	// way to way
	for (int i = 1; i <= N-1; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			dist = CalcDist(way_list[i], way_list[j]);
			if (dist > 1) continue;
			graph[i][j] = dist;
			graph[j][i] = dist;
		}
	}
	// way to end
	for (int i = 1; i <= N; i++) {
		dist = CalcDist(ep, way_list[i]);
		if (dist > 1) continue;
		graph[END][i] = dist;
		graph[i][END] = dist;
	}
	// start to end
	dist = CalcDist(sp, ep);
	if (dist == 1) {
		graph[START][END] = dist;
		graph[END][START] = dist;
	}
}

int CalcDist(Point p1, Point p2) {
	int ManhattanDist = abs(p1.y - p2.y) + abs(p1.x - p2.x);
	return (ManhattanDist % 1000) == 0 ? ManhattanDist / 1000 : ManhattanDist / 1000 + 1;
}

void Bfs() {
	queue<int> q;
	q.push(START);
	visited[START] = 1;

	int cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();

		for (int next = 0; next <= 101; next++)
		{
			if (graph[cur][next] == 0)
				continue;
			if (visited[next] == 1)
				continue;
			
			visited[next] = 1;
			q.push(next);
			
		}
	}
}