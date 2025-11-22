// 2025.11.22.
// 2467. 용액

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int sol[100002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> sol[i];
    }
    sort(sol, sol + n);

    int st = 0;
    int en = n - 1;
    long long best = (long long)2e9 + 5;
    int ansL = sol[st], ansR = sol[en];
    while (st < en) {
        long long sum = (long long)sol[st] + sol[en];
        long long diff = llabs(sum);
        if (diff < best) {
            best = diff;
            ansL = sol[st];
            ansR = sol[en];
        }
        sum > 0 ? en-- : st++;
    }

    cout << ansL << " " << ansR << "\n";
    return 0;
}
