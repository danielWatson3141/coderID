#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

string flip_s(string s, vector<bool> &f) {
    string ans;

    for (int i = 0; i < s.size(); i++)
        ans += (!f[i]) ? s[i] : (s[i] == '0' ? '1' : '0');

    return ans;
}

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int n, l;
        cin >> n >> l;

        vector<string> v1(n), v2(n);

        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> v2[i];
        }

        int ans = -1;

        for (int i = 0; i < n; i++) {
            vector<bool> used(n);

            vector<bool> flip(l);

            for (int j = 0; j < l; j++)
                flip[j] = v1[0][j] != v2[i][j];

            multiset<string> s(v2.begin(), v2.end());

            bool possible = true;

            for (int j = 0; j < n; j++) {
                string s2 = flip_s(v1[j], flip);

                if (s.count(s2) == 0) {
                    possible = false;
                    break;
                } else {
                    s.erase(s.find(s2));
                }
            }

            if (possible) {
                int cnt = count_if(flip.begin(), flip.end(), [](bool i) { return i; });

                ans = (ans == -1) ? cnt : min(ans, cnt);
            }
        }

        cout << "Case #" << tc << ": ";

        if (ans != -1)
            cout << ans << '\n';
        else
            cout << "NOT POSSIBLE\n";
    }

    return 0;
}
