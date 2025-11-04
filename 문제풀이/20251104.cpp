// 2025.11.04
// 백준 1774. 나만 안되는 연애

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int n, m; // n: 캠퍼스 개수, m: 도로 후보 개수
char gender[1002]; // 각 캠퍼스의 성별 정보 (M/F)
vector<tuple<int, int, int>> line; // (거리, 캠퍼스1, 캠퍼스2)
vector<int> p(1005, -1); // Union-Find 부모 배열 (음수면 루트, 절댓값은 크기)

// find(x): x의 루트(대표 노드) 찾기 + 경로 압축
int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]); // 경로 압축
}

// unite(u, v): 두 집합을 합치기. 이미 같은 집합이면 false 반환
bool unite(int u, int v) {
	u = find(u);
	v = find(v);

	if (u == v) return 0; // 이미 같은 트리에 속함 → 연결 불필요

	// union by size (더 큰 트리에 작은 트리를 붙임)
	if (p[u] == p[v]) p[u]--; // 두 집합 크기가 같으면 하나 증가
	if (p[u] < p[v]) p[v] = u; // u 트리가 더 큼 → v를 u 밑에 붙임
	else p[u] = v; // 반대의 경우
	return 1;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> gender[i]; // 각 캠퍼스의 성별 입력
	}

	while (m--) {
		int u, v, d;
		cin >> u >> v >> d; // 두 캠퍼스와 거리 입력
		if (gender[u] == gender[v]) continue; // 같은 성별이면 연결 불가
		line.push_back({ d, u, v }); // 거리 기준으로 저장
	}

	// 거리(가중치)가 작은 순으로 정렬 → 크루스칼 알고리즘 준비
	sort(line.begin(), line.end());

	int result = 0; // 총 거리 (최소 신장 트리 가중치 합)
	int count = 0;  // 현재까지 연결된 간선 개수

	// 크루스칼 알고리즘 수행
	for (auto x : line) {
		int a, b, cost;
		tie(cost, a, b) = x; // tuple 언패킹

		if (!unite(a, b)) continue; // 이미 연결된 경우 무시
		result += cost; // 간선 추가
		count++;

		if (count == n - 1) break; // 모든 캠퍼스 연결 완료
	}

	// MST 완성 여부 확인
	if (count < n - 1) cout << -1; // 모든 노드 연결 불가 (성별 제약 등)
	else cout << result; // 최소 거리 합 출력

	return 0;
}
