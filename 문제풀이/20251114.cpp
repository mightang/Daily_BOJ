#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <tuple>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int c, p;
        unordered_map<string, tuple<int, int, int>> coffee;
        cin >> c >> p;
        while (c--) {
            string n;
            int s, m, l;
            cin >> n >> s >> m >> l;
            coffee[n] = { s, m, l };
        }

        int delivery_fee = 100 / p;
        while (p--) {
            string x, y, z;
            cin >> x >> y >> z;

            int result;
            if (y == "small") {
                result = get<0>(coffee[z]);
            }
            else if (y == "medium") {
                result = get<1>(coffee[z]);
            }
            else if (y == "large") {
                result = get<2>(coffee[z]);
            }

            result += delivery_fee;
            if (result % 5 == 1) {
                result -= 1;
            }
            else if (result % 5 == 4) {
                result += 1;
            }

            cout << x << " " << result << "\n";
        }
    }
    return 0;
}
