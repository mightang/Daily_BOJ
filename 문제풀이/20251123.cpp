// 2025.11.13.
// N과 M(7)

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m;
int num[10];
int result[10];

void Func(int st, int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        result[idx] = num[i];
        Func(i, idx + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    Func(0, 0);
    return 0;
}
