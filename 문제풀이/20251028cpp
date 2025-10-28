//2025.10.28.
//1992. 쿼드트리

#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s[65]; // 문제에서 N ≤ 64 이므로 넉넉히 65칸
void Func(int y, int x, int len) {
    // 현재 영역의 기준 문자
    char init = s[y][x];

    // 길이가 1이면 그 문자 그대로 출력하고 종료
    if (len == 1) {
        cout << init;
        return;
    }

    // 현재 영역이 모두 같은 문자(init)인지 검사
    bool changed = false;
    for (int i = y; i < y + len; i++) {        //  지역 상한 사용: i < y + len
        for (int j = x; j < x + len; j++) {    //  지역 상한 사용: j < x + len
            if (s[i][j] != init) {
                changed = true;
            }
        }
    }

    // 만약 하나라도 다른 문자가 있었다면 4등분하여 재귀 호출
    if (changed) {
        int half = len / 2;
        cout << "("; // 4사분면 결과를 괄호로 감쌈

        // 호출 순서: 좌상 → 우상 → 좌하 → 우하
        Func(y,         x,         half); // 좌상
        Func(y,         x + half,  half); // 우상
        Func(y + half,  x,         half); // 좌하
        Func(y + half,  x + half,  half); // 우하

        cout << ")";
    }
    // 모두 같은 문자였다면 그 문자 하나만 출력
    else {
        cout << init;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i]; // 한 줄씩 입력 (문자열로 받으면 인덱싱 편함)
    }

    Func(0, 0, n); // 전체 영역에서 시작
    return 0;
}
