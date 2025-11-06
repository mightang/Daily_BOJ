#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
vector<tuple<int, int, int>> line;
vector<int> p(100002, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;
	if (p[u] == p[v]) p[u]--;
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	long long sum = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		sum += c;
		line.push_back({ c, a, b });
	}
	sort(line.begin(), line.end());

	int count = 0;
	long long result = 0;
	for (auto x : line) {
		int a, b;
		long long cost;
		tie(cost, a, b) = x;
		if (!is_diff_group(a, b)) continue;
		count++;
		result += cost;
		if (count == n - 1) break;
	}

	if (count != n - 1) cout << -1;
	else cout << sum - result;
	return 0;
}
