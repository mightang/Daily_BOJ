//2025.10.29.
//1647. 도시 분할 계획

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
vector<int> p(1000005, -1);             // 부모(또는 집합 크기)를 저장하는 배열, 초기값 -1
tuple<int, int, int> edge[1000005];     // (비용, 정점 a, 정점 b) 형태로 간선 저장

// find 함수: 경로 압축을 이용해 루트 노드를 찾음
int find(int x) {
    if (p[x] < 0) return x;             // 음수면 루트이므로 자기 자신 반환
    return p[x] = find(p[x]);           // 재귀적으로 루트 찾고 경로 압축
}

// 서로 다른 그룹인지 확인하고, 다르면 합침 (Union-Find)
bool is_diff_group(int u, int v) {
    u = find(u);                        // u의 루트 찾기
    v = find(v);                        // v의 루트 찾기

    if (u == v) return 0;               // 루트가 같으면 이미 같은 그룹 → 사이클 발생

    if (p[u] == p[v]) p[u]--;           // 두 집합 크기가 같으면 u의 크기 증가 (음수이므로 감소)
    if (p[u] < p[v]) p[v] = u;          // u가 더 큰 집합이면 v를 u에 연결
    else p[u] = v;                      // 아니면 u를 v에 연결
    return 1;                           // 두 그룹을 합쳤음을 반환
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;                      // n: 정점 수, m: 간선 수
    for (int i = 0; i < m; i++) {
        int a, b, c;                    // a, b: 연결된 노드 / c: 비용
        cin >> a >> b >> c;
        edge[i] = { c, a, b };          // 튜플에 (비용, 노드1, 노드2) 저장
    }

    sort(edge, edge + m);               // 간선을 비용 기준으로 오름차순 정렬 (Kruskal 전처리)

    int count = 0;                      // 현재까지 선택한 간선 개수
    int result = 0;                     // MST 누적 비용 합

    for (int i = 0; i < m; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];      // 튜플 풀기: (비용, 노드 a, 노드 b)

        if (!is_diff_group(a, b)) continue; // 사이클이면 패스
        result += cost;                 // 간선 비용 추가
        count++;                        // 간선 개수 증가

        // MST 완성 시점(n-1개의 간선 선택 완료)
        // 마지막으로 추가된 간선을 제거하여 두 개의 마을로 나눔
        if (count == n - 1) {
            result -= cost;             // 마지막 간선 비용 빼기
            break;                      // 종료
        }
    }

    cout << result;                     // 두 마을로 분할된 최소 유지비 출력
    return 0;
}
