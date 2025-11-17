// 2025.11.17.
// 20920. 영단어 암기는 괴로워

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> dict;
vector<pair<int, string>> result;
int n, m;

bool compare(pair<int, string> p1, pair<int, string> p2) {
    if (p1.first != p2.first) {
        return p1.first > p2.first;
    }
    else if (p1.second.length() != p2.second.length()) {
        return p1.second.length() > p2.second.length();
    }
    else {
        return p1 < p2;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    while (n--) {
        string word;
        cin >> word;
        if (word.length() < m) continue;
        dict[word]++;
    }
    for (auto x : dict) {
        result.push_back({ x.second, x.first });
    }
    sort(result.begin(), result.end(), compare);

    for (auto x : result) {
        cout << x.second << "\n";
    }
    return 0;
}
