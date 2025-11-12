// 2025.11.12.
// 16928. 뱀과 사다리 게임

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int dist[102];     // dist[i]: i번 칸에 도달하기까지 던진 주사위 횟수
int jump[102];     // jump[i]: i번 칸에서 이동할 목적지(사다리·뱀 적용 결과)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 초기화: 각 칸의 목적지는 자기 자신, 방문 배열은 -1
    for (int i = 1; i <= 100; i++) {
        jump[i] = i;
        dist[i] = -1;
    }

    // 사다리 입력
    cin >> n >> m;
    while (n--) {
        int x, y;
        cin >> x >> y;
        jump[x] = y; // 사다리를 타면 y로 이동
    }
    // 뱀 입력
    while (m--) {
        int u, v;
        cin >> u >> v;
        jump[u] = v; // 뱀을 만나면 v로 이동
    }

    // BFS 시작
    queue<int> q;
    q.push(1);        // 1번 칸에서 출발
    dist[1] = 0;      // 시작점의 이동 횟수는 0

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        // 주사위 1~6까지 던지는 모든 경우 탐색
        for (int dir = 1; dir <= 6; dir++) {
            int nxt = cur + dir;
            if (nxt > 100) continue; // 100번 칸을 넘어가면 무시
            int to_next = jump[nxt]; // 사다리나 뱀을 적용한 이동 목적지
            if (dist[to_next] != -1) continue; // 이미 방문한 칸이면 스킵

            dist[to_next] = dist[cur] + 1; // 주사위 한 번 추가
            q.push(to_next);               // 다음 탐색 대상으로 추가
        }
    }

    cout << dist[100]; // 100번 칸까지 최소 주사위 횟수 출력
    return 0;
}
