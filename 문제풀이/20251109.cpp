// 2025.11.09.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int a1, a2, a3;
    cin >> n;
    cin >> a1 >> a2 >> a3;

    int mx1 = a1, mx2 = a2, mx3 = a3;
    int mn1 = a1, mn2 = a2, mn3 = a3;
    for (int i = 2; i <= n; i++) {
        cin >> a1 >> a2 >> a3;

        int nmx1 = a1 + max(mx1, mx2);
        int nmx2 = a2 + max({ mx1, mx2, mx3 });
        int nmx3 = a3 + max(mx2, mx3);

        int nmn1 = a1 + min(mn1, mn2);
        int nmn2 = a2 + min({ mn1, mn2, mn3 });
        int nmn3 = a3 + min(mn2, mn3);

        mx1 = nmx1; mx2 = nmx2; mx3 = nmx3;
        mn1 = nmn1; mn2 = nmn2; mn3 = nmn3;
    }
    int maxAns = max({ mx1, mx2, mx3 });
    int minAns = min({ mn1, mn2, mn3 });

    cout << maxAns << ' ' << minAns << '\n';
    return 0;
}
