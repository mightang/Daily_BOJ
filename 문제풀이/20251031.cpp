//2025.10.31.
//2887. 행성 터널

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

// 각 행성의 3차원 좌표를 담는 구조체
typedef struct {
	int x, y, z;
}plannet;

int n;                                      // 행성(정점) 개수
plannet p[100002];                          // 1..n 행성의 좌표
vector<tuple<int, int, int>> line;          // 간선 목록: (cost, a, b)
vector<int> parent(100002, -1);             // DSU용 배열: 음수면 루트이자 집합 크기(-size)

// 경로 압축을 포함한 find: 루트 노드 반환
int find(int x) {
	if (parent[x] < 0) return x;            // 음수면 루트
	return parent[x] = find(parent[x]);     // 재귀 + 경로 압축
}

// u, v가 다른 집합이면 union 수행 후 true, 같으면 false
bool is_diff_group(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0;                   // 이미 같은 집합 → 합치지 않음(사이클)
	if (parent[u] == parent[v]) parent[u]--;// 크기 같으면 u의 집합 크기 1 증가(음수 감소)
	if (parent[u] < parent[v]) parent[v] = u;// u의 집합이 더 크면 v를 u에 붙임
	else parent[u] = v;                     // 아니면 u를 v에 붙임
	return 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {          // 1-indexed 입력
		int x, y, z;
		cin >> x >> y >> z;
		p[i].x = x;
		p[i].y = y;
		p[i].z = z;
	}

	// 각 축(x, y, z)별로 (좌표값, 인덱스) 쌍을 모아 정렬할 벡터
	vector<pair<int, int>> vx, vy, vz;
	for (int i = 1; i <= n; i++) {
		vx.push_back({ p[i].x, i });
		vy.push_back({ p[i].y, i });
		vz.push_back({ p[i].z, i });
	}
	sort(vx.begin(), vx.end());             // x 좌표 기준 오름차순
	sort(vy.begin(), vy.end());             // y 좌표 기준 오름차순
	sort(vz.begin(), vz.end());             // z 좌표 기준 오름차순

	// 핵심: 각 축에서 인접한 두 점만 간선 후보로 추가하면 충분
	// (해당 축에서 가장 가까운 이웃들만으로도 MST의 모든 유의미한 간선을 커버)
	for (int i = 0; i < n - 1; i++) {
		int a = vx[i].second;
		int b = vx[i + 1].second;
		int cost = abs(p[a].x - p[b].x);    // x축 차이를 비용으로
		line.push_back({ cost, a, b });

		a = vy[i].second;
		b = vy[i + 1].second;
		cost = abs(p[a].y - p[b].y);        // y축 차이를 비용으로
		line.push_back({ cost, a, b });

		a = vz[i].second;
		b = vz[i + 1].second;
		cost = abs(p[a].z - p[b].z);        // z축 차이를 비용으로
		line.push_back({ cost, a, b });
	}

	sort(line.begin(), line.end());         // 간선 비용 오름차순 정렬 (Kruskal 준비)

	int count = 0;                          // 선택된 간선 수
	long long result = 0;                   // 누적 비용(오버플로 방지용 long long)
	for (auto x : line) {
		int a, b, cost;
		tie(cost, a, b) = x;                // (cost, a, b) 분해
		if (!is_diff_group(a, b)) continue; // 같은 집합이면 스킵(사이클 방지)
		count++;
		result += cost;                     // 비용 누적
		if (count == n - 1) break;          // MST 완성: 간선 n-1개면 종료
	}

	cout << result;                          // 최소 비용 출력
	return 0;
}
