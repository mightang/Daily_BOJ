#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s[65]; // �������� N �� 64 �̹Ƿ� �˳��� 65ĭ
void Func(int y, int x, int len) {
    // ���� ������ ���� ����
    char init = s[y][x];

    // ���̰� 1�̸� �� ���� �״�� ����ϰ� ����
    if (len == 1) {
        cout << init;
        return;
    }

    // ���� ������ ��� ���� ����(init)���� �˻�
    bool changed = false;
    for (int i = y; i < y + len; i++) {        //  ���� ���� ���: i < y + len
        for (int j = x; j < x + len; j++) {    //  ���� ���� ���: j < x + len
            if (s[i][j] != init) {
                changed = true;
            }
        }
    }

    // ���� �ϳ��� �ٸ� ���ڰ� �־��ٸ� 4����Ͽ� ��� ȣ��
    if (changed) {
        int half = len / 2;
        cout << "("; // 4��и� ����� ��ȣ�� ����

        // ȣ�� ����: �»� �� ��� �� ���� �� ����
        Func(y, x, half); // �»�
        Func(y, x + half, half); // ���
        Func(y + half, x, half); // ����
        Func(y + half, x + half, half); // ����

        cout << ")";
    }
    // ��� ���� ���ڿ��ٸ� �� ���� �ϳ��� ���
    else {
        cout << init;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i]; // �� �پ� �Է� (���ڿ��� ������ �ε��� ����)
    }

    Func(0, 0, n); // ��ü �������� ����
    return 0;
}