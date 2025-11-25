// 2025.11.25.
// 1780. 종이의 개수

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int paper[2200][2200];
int r1, r2, r3 = 0;

void Func(int y, int x, int len) {
    if (len == 1) {
        if (paper[y][x] == -1) r1++;
        else if (paper[y][x] == 0) r2++;
        else if (paper[y][x] == 1) r3++;
        return;
    }

    bool is_same = 1;
    int init = paper[y][x];
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (paper[i][j] != init) {
                is_same = 0;
                break;
            }
        }
    }

    if (is_same) {
        if (init == -1) r1++;
        else if (init == 0) r2++;
        else if (init == 1) r3++;
    }
    else {
        int nxt = len / 3;
        for (int i = y; i <= y + nxt * 2; i += nxt) {
            for (int j = x; j <= x + nxt * 2; j += nxt) {
                Func(i, j, nxt);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0); 

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    Func(0, 0, n);

    cout << r1 << "\n" << r2 << "\n" << r3;
    return 0;
}
