// 2025.11.02
// 1774. 우주신과의 교감

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
using namespace std;

int n, m;                           // n: 우주신 수, m: 이미 연결된 통로 수
vector<int> p(1005, -1);            // Disjoint Set (Union-Find)
vector<tuple<double, int, int>> line; // (거리, 노드1, 노드2)
pair<int, int> point[1005];         // 각 우주신의 좌표 (x, y)

double get_dist(pair<int, int> p1, pair<int, int> p2) {
	double dx = pow((p1.first - p2.first), 2);
	double dy = pow((p1.second - p2.second), 2);
	return sqrt(dx + dy);
}
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0; // 이미 같은 집합이면 무시

	if (p[u] == p[v]) p[u]--; // 크기가 같다면 한쪽 크기 증가
	if (p[u] < p[v]) p[v] = u;
	else p[u] = v;
	return 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	// 각 우주신의 좌표 입력
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		point[i] = { x, y };
	}

	// 모든 우주신 쌍 간 거리 계산 → 간선 리스트 생성
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			double dist = get_dist(point[i], point[j]);
			line.push_back({ dist, i, j });
		}
	}

	// 거리 기준 오름차순 정렬 (Kruskal 준비)
	sort(line.begin(), line.end());

	int count = 0; // 연결된 간선 개수

	//  이미 연결된 통로를 미리 DSU로 합침
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (is_diff_group(x, y)) count++;
	}

	double result = 0;

	//  Kruskal 알고리즘 수행
	for (auto x : line) {
		int a, b;
		double cost;
		tie(cost, a, b) = x;

		if (!is_diff_group(a, b)) continue;
		count++;
		result += cost;
		if (count == n - 1) break; // 모든 노드 연결 완료
	}

	//  결과 출력 (소수점 둘째 자리)
	cout << fixed << setprecision(2) << result;
	return 0;
}
