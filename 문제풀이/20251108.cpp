// 2025.11.08.
// 1753. 최단경로

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<int, int>> adj[1002];
int d[1002];
const int INF = 1e9 + 10;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n >> m;
	fill(d, d + n + 1, INF);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}
	int st, en;
	cin >> st >> en;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[st] = 0;
	pq.push({ d[st], st });
	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (d[cur.second] != cur.first) continue;
		for (auto nxt : adj[cur.second]) {
			if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
			d[nxt.second] = d[cur.second] + nxt.first;
			pq.push({ d[nxt.second], nxt.second });
		}
	}

	cout << d[en];
	return 0;
}
