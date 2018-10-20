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
        sort(b.begin(), b.end());
        int t = 999999999;
        for (int i = 0; i < (1<<l); i++) {
            int c = 0;
            for (int j = 0; j < l; j++) if (i&(1<<j)) c++;
            vector<string> u;
            for (int j = 0; j < n; j++) {
                string s = a[j];
                for (int k = 0; k < l; k++) {
                    if (i&(1<<k)) s[k] = '0'+'1'-s[k];
                } 
                u.push_back(s);
            }
            sort(u.begin(), u.end());
            if (u == b && c < t) t = c; 
        }
        cout << "Case #" << x+1 << ": ";
        if (t == 999999999) cout << "NOT POSSIBLE\n";
        else cout << t << "\n";
    }
}
