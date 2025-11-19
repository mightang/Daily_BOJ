// 2025.11.19.
// 1759. 암호 만들기

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int l, c;
string result;
char letter[20];
bool is_used[20];

void Func(int st, int len) {
    if (len == l) {
        int con = 0;
        int vow = 0;
        for (auto x : result) {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
                vow++;
            }
            else con++;
        }
        if (con >= 2 && vow >= 1) {
            cout << result << "\n";
        }
        return;
    }
    for (int i = st; i < c; i++) {
        if (!is_used[i]) {
            is_used[i] = 1;
            result.push_back(letter[i]);
            Func(i, len + 1);
            result.pop_back();
            is_used[i] = 0;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        cin >> letter[i];
    }
    sort(letter, letter + c);

    Func(0, 0);
    return 0;
}
