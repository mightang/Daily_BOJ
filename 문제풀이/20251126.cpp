// 2025.11.26.
// 2448. 별 찍기 - 11

#include <iostream>
#include <algorithm>
using namespace std;

int n;
char result[7000][7000];

void Func(int y, int x, int len) {
    if (len == 3) {
        result[y][x] = '*';
        result[y + 1][x - 1] = '*';
        result[y + 1][x] = ' ';
        result[y + 1][x + 1] = '*';
        for (int j = x - 2; j <= x + 2; j++) {
            result[y + 2][j] = '*';
        }
        return;
    }
    
    int nxt = len / 2;
    Func(y, x, nxt);
    Func(y + nxt, x - nxt, nxt);
    Func(y + nxt, x + nxt, nxt);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < 7000; i++) {
        fill(result[i], result[i] + 7000, ' ');
    }
    Func(0, n - 1, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}
