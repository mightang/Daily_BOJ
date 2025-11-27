// 2025.11.27.
// 28464. Potato

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int dish[200002];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> dish[i];
        sum += dish[i];
    }
    sort(dish, dish + n);

    int mn = 0;
    for (int i = 0; i < n / 2; i++) {
        mn += dish[i];
    }
    int mx = sum - mn;

    cout << mn << " " << mx;
    return 0;
}
