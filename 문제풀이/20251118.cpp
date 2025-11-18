// 2025.11.18.
// 20920. 이중 우선순위 큐

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;

        priority_queue<pair<int, int>> mx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > mn;
        vector<bool> alive(k, 0);
        int id = 0;
        while (k--) {
            char op;
            int n;
            cin >> op >> n;
            if (op == 'I') {
                mn.push({n, id});
                mx.push({n, id});
                alive[id] = 1;
                id++;
            }
            else if (op == 'D') {
                if (n == 1) {
                    while (!mx.empty() && !alive[mx.top().second]) {
                        mx.pop();
                    }
                    if (!mx.empty()) {
                        alive[mx.top().second] = 0;
                        mx.pop();
                    }
                }
                else if (n == -1) {
                    while (!mn.empty() && !alive[mn.top().second]) {
                        mn.pop();
                    }
                    if (!mn.empty()) {
                        alive[mn.top().second] = 0;
                        mn.pop();
                    }
                }
            }
        }
        while (!mx.empty() && !alive[mx.top().second]) mx.pop();
        while (!mn.empty() && !alive[mn.top().second]) mn.pop();

        if (mx.empty() || mn.empty()) cout << "EMPTY\n";
        else cout << mx.top().first << " " << mn.top().first << "\n";
    }
    return 0;
}
