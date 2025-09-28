#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int n, k;
int dist[100002];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;

	fill(dist, dist + 100002, -1);
	deque<int> dq;
	dq.push_back(n);
	dist[n] = 0;
	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();
		if (cur == k) break;

		int nxt = cur * 2;
		if (nxt <= 100000 && (dist[nxt] == -1 || dist[nxt] > dist[cur])) {
			dist[nxt] = dist[cur];
			dq.push_front(nxt);
		}

		nxt = cur - 1;
		if (nxt >= 0 && (dist[nxt] == -1 || dist[nxt] > dist[cur] + 1)) {
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}

		nxt = cur + 1;
		if (nxt <= 100000 && (dist[nxt] == -1 || dist[nxt] > dist[cur] + 1)) {
			dist[nxt] = dist[cur] + 1;
			dq.push_back(nxt);
		}
	}

	cout << dist[k];
	return 0;
}
