// 2025.11.10

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> adj[1005];   // 인접 리스트: a → b 형태로 저장
int in_line[1005];       // 각 노드의 진입 차수 (앞에 들어야 할 과목 수)
int result[1005];        // 각 과목을 들을 수 있는 최소 학기 번호

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;          // a 과목을 들은 후 b 과목을 들을 수 있음
        adj[a].push_back(b);    // 방향 그래프 간선 저장
        in_line[b]++;           // b의 진입 차수 증가
    }

    queue<int> q;
    // 진입 차수가 0인 노드(선수 과목 없는 과목)부터 시작
    for (int i = 1; i <= n; i++) {
        if (in_line[i] == 0) {
            result[i] = 1;      // 첫 학기부터 들을 수 있음
            q.push(i);
        }
    }

    // 위상 정렬 수행 (BFS)
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        // 현재 과목 이후에 들을 수 있는 과목들 확인
        for (auto nxt : adj[cur]) {
            in_line[nxt]--;     // 선수 과목 하나 이수 → 진입 차수 감소
            if (in_line[nxt] == 0) {
                q.push(nxt);    // 모든 선수 과목 이수 완료 → 수강 가능
                result[nxt] = result[cur] + 1; // 다음 학기에 들을 수 있음
            }
        }
    }

    // 각 과목별 최소 수강 학기 출력
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
