// 2025.11.21.
// 2805. 나무 자르기

#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
long long tree[1000002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        mx = max(mx, tree[i]);
    }

    long long st = 0;
    long long en = mx;
    long long ans = 0;
    while (st <= en) {
        long long mid = (st + en) / 2;

        long long cut = 0;
        for (int i = 0; i < n; i++) {
            if (tree[i] > mid) {
                cut += (tree[i] - mid);
            }
        }

        if (cut >= m) {
            ans = mid;
            st = mid + 1;
        }
        else {
            en = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
