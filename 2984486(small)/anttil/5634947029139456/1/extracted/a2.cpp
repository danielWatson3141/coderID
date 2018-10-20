#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n, l;
vector<string> a;
vector<string> b;

int main() {
    cin >> t;
    for (int x = 0; x < t; x++) {
        cin >> n >> l;
        a.clear();
        b.clear();
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            a.push_back(s);
        }
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            b.push_back(s);
        }
        sort(a.begin(), a.end());
        int t = 999999999;
        for (int i = 0; i < n; i++) {
            int m[1010] = {0};
            int c = 0;
            for (int j = 0; j < l; j++) {
                if (a[0][j] != b[i][j]) {m[j] = 1;c++;}
            }
            vector<string> u;
            for (int j = 0; j < n; j++) {
                string s = b[j];
                for (int k = 0; k < l; k++)
                    if (m[k]) s[k] = '0'+'1'-s[k];
                u.push_back(s);
            }
            sort(u.begin(), u.end());
            if (a == u && c < t) t = c;
        }
        cout << "Case #" << x+1 << ": ";
        if (t == 999999999) cout << "NOT POSSIBLE\n";
        else cout << t << "\n";
    }
}
