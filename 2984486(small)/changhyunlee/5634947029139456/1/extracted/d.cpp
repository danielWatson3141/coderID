#include <vector>
#include <numeric>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    vector<string> str[2];
    int t;

    ifstream in("input.txt");
    ofstream out("output.txt");
    in >> t;
    for (int l=1; l<=t; l++) {
        in >> n >> m;
        for (int i=0; i<2; i++) {
            str[i].clear();
            for (int j=0; j<n; j++) {
                string s;
                in >> s;
                str[i].push_back(s);
            }
        }

        int res = m+1;;
        for (int i=0; i<n; i++) {
            vector<int> s;
            s.resize(m);
            for (int j=0; j<m; j++) {
                str[0][0][j]!=str[1][i][j]?s[j]=1:s[j]=0;
            }
//            for (int i=0; i<m; i++) {
//                cout << s[i];
//            }
//            cout << endl;

            int chk[150];
            int cnt = 0;
            fill(chk, chk+150, 0);
            for (int j=0; j<n; j++) {
                string ss = str[0][j];
                for (int k=0; k<m; k++) {
                    if (s[k]==1) {
                        if (ss[k]=='0') ss[k] = '1';
                        else ss[k] = '0';
                    }
                }
                for (int k=0; k<n; k++) {
                    if (ss == str[1][k] && !chk[k]) {
                        chk[k] = 1;
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt==n) {
                res = min(res, accumulate(s.begin(),s.end(),0));
            }
        }
        out << "Case #" << l << ": ";
        if (res==m+1) {
            out << "NOT POSSIBLE" << endl;
        } else {
            out << res << endl;
        }
    }
    return 0;
}
