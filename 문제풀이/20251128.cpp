// 2025.11.28.
// 2294. 동전 2

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, k;
int coin[105];
int d[100005];

const int INF = 1000000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    fill(d, d + k + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        d[coin[i]] = 1;
    }
    sort(coin, coin + n);

    for (int i = 1; i <= k; i++) {
        if (d[i] != INF) continue;
        for (int idx = 0; idx < n; idx++) {
            if (i <= coin[idx]) continue;
            int tmp = d[i - coin[idx]] + 1;
            if (tmp <= 0) continue;
            d[i] = min(d[i], tmp);
        }
    }

    if (d[k] >= INF) cout << -1;
    else cout << d[k];
    return 0;
}
