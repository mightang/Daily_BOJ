#2644. 촌수계산[C++]

1. 풀이
-그래프 탐색
정상적인 가계도라면 사람을 정점, 부모-자식 관계를 간선으로 표현할 수 있는 트리 형태를 가진다.
부모와 자식 사이가 1촌이므로 촌수를 계산하려면 시작 정점의 거리를 0으로 하고 인접 정점마다 1을 더해주는 방식으로 그래프 탐색을 통해 거리를 갱신해 주면 된다.

-입력받기
while (m--) {
	int x, y;
	cin >> x >> y;
	adj[x].push_back(y);
	adj[y].push_back(x);
}
fill(dist, dist + n + 1, -1);

관계가 있는 정점을 입력받아 상호 간의 간선을 입력한다. 이렇게 하면 무향 그래프의 성질을 가지게 되어서 연결되어 있는 경우에 양방향으로 탐색이 가능하다. 
촌수를 저장할 dist 배열의 초기값을 -1로 초기화한다.

-BFS
queue<int> q;
q.push(a);
dist[a] = 0;
while (!q.empty()) {
	int cur = q.front();
	q.pop();
	for (auto x : adj[cur]) {
		if (dist[x] != -1) continue;
		dist[x] = dist[cur] + 1;
		q.push(x);
	}
}
BFS, DFS 중 어느 것을 이용해도 무방하다. 탐색을 시작하는 정점 a를 큐에 넣고, 초기 거리를 0으로 설정한다. 그런 다음 a와 연결된 정점들을 차례로 큐에 넣으며 거리를 1씩 더해 준다. 
이렇게 하면 관계가 있는 경우에는 측정된 거리의 값이 저장될 것이고, 그렇지 않다면 초기값인 -1로 남아있을 것이다. 따라서 그래프 탐색이 끝난 이후 dist[b]를 출력해 주면 된다. 

​
2. 최종 답안
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int n, m, a, b;
vector<int> adj[102];
int dist[102];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> a >> b >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	fill(dist, dist + n + 1, -1);

	queue<int> q;
	q.push(a);
	dist[a] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto x : adj[cur]) {
			if (dist[x] != -1) continue;
			dist[x] = dist[cur] + 1;
			q.push(x);
		}
	}

	cout << dist[b];
	return 0;
}
