// 2025.11.13.
// 1238. 파티

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, x;
vector<pair<int, int>> adj1[10002];   // 원래 방향 그래프: st → en (가중치 T)
vector<pair<int, int>> adj2[10002];   // 역방향 그래프: en → st (가중치 T)
int d1[10002];                        // d1[i]: X에서 i로 가는 최단 거리 (X → i)
int d2[10002];                        // d2[i]: i에서 X로 가는 최단 거리 (i → X, 역그래프에서 X → i)
const int INF = 1e9 + 10;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> x;
    // 거리 배열을 무한대로 초기화
    fill(d1, d1 + n + 1, INF);
    fill(d2, d2 + n + 1, INF);

    // 간선 입력
    while (m--) {
        int st, en, T;
        cin >> st >> en >> T;
        adj1[st].push_back({ T, en });   // 정방향: st → en
        adj2[en].push_back({ T, st });   // 역방향: en → st
    }

    // 다익스트라 1: X에서 출발하여 정방향 그래프 탐색 (X → i)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    d1[x] = 0;
    pq.push({ d1[x], x });
    while (!pq.empty()) {
        auto cur = pq.top();  // cur.first: 현재까지 거리, cur.second: 정점 번호
        pq.pop();
        if (d1[cur.second] != cur.first) continue; // 이미 더 짧은 거리로 갱신된 경우 스킵

        for (auto nxt : adj1[cur.second]) {
            // nxt.first: 간선 가중치, nxt.second: 다음 정점
            if (d1[nxt.second] <= d1[cur.second] + nxt.first) continue; // 더 좋은 경로가 아니면 스킵
            d1[nxt.second] = d1[cur.second] + nxt.first;                // 최단 거리 갱신
            pq.push({ d1[nxt.second], nxt.second });
        }
    }

    // 다익스트라 2: X에서 출발하여 역방향 그래프 탐색 (역그래프에서 X → i = 원래 그래프에서 i → X)
    d2[x] = 0;
    pq.push({ d2[x], x });
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d2[cur.second] != cur.first) continue;

        for (auto nxt : adj2[cur.second]) {
            if (d2[nxt.second] <= d2[cur.second] + nxt.first) continue;
            d2[nxt.second] = d2[cur.second] + nxt.first;
            pq.push({ d2[nxt.second], nxt.second });
        }
    }

    // 각 정점 i에 대해 (i → X) + (X → i) 의 최댓값 찾기
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (d1[i] == INF || d2[i] == INF) continue; // 왕복 불가능한 경우 제외
        mx = max(mx, d1[i] + d2[i]);
    }
    cout << mx;
    return 0;
}
