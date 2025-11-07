#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int sum[1030][1030]; // sum[i][j] = i번째 행의 1..j까지 누적합
// 전역 배열은 0으로 초기화되므로 sum[i][0]은 0으로 안전하게 사용 가능

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    // 입력과 동시에 "행 기준 누적 합" 구성
    // sum[i][j] = sum[i][j-1] + a[i][j]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            sum[i][j] = sum[i][j - 1] + x;
        }
    }

    // 질의 처리
    // 각 질의 (x1,y1)~(x2,y2)에 대해 행을 x1..x2 순회하며
    // 해당 행의 부분합을 더한다.
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int result = 0;
        for (int i = x1; i <= x2; i++) {
            result += (sum[i][y2] - sum[i][y1 - 1]);
        }
        cout << result << "\n";
    }
    return 0;
}
