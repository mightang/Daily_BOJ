// 2025.11.20.
// 15489. 파스칼 삼각형

#include <iostream>
#include <algorithm>
using namespace std;

int r, c, w;
int tri[32][32];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    tri[1][1] = 1;
    tri[2][1] = 1;
    tri[2][2] = 1;
    for (int i = 3; i <= 30; i++) {
        for (int j = 1; j <= i; j++) {
            tri[i][j] = tri[i - 1][j - 1] + tri[i - 1][j];
        }
    }

    cin >> r >> c >> w;
    int result = 0;
    for (int row = 0; row < w; row++) {
        for (int col = 0; col <= row; col++) {
            result += tri[r + row][c + col];
        }
    }

    cout << result;
    return 0;
}
