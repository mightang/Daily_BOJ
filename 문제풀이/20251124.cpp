// 2025.11.24.
// 2447. 별 찍기 - 10

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
char result[7000][7000];

void fill_blank(int y, int x, int len) {
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            result[i][j] = ' ';
        }
    }
}

void Func(int y, int x, int len) {
    if (len == 3) {
        for (int i = y; i < y + len; i++) {
            for (int j = x; j < x + len; j++) {
                if (i == y + 1 && j == x + 1) {
                    fill_blank(i, j, len / 3);
                }
                else {
                    result[i][j] = '*';
                }
            }
        }
        return;
    }

    int nxt = len / 3;
    for (int i = y; i <= y + 2 * nxt; i += nxt) {
        for (int j = x; j <= x + 2 * nxt; j += nxt) {
            if (i == y + nxt && j == x + nxt) {
                fill_blank(i, j, nxt);
            }
            else {
                Func(i, j, nxt);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    Func(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j];
        }
        cout << "\n";
    }
    return 0;
}
