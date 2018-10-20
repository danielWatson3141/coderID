#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int o=0;o<t;o++){
        cout << "Case #" << o+1 << ": ";
        int n,l;
        cin >> n >> l;
        vector<string> a, b;
        a.assign(n, "");
        b.assign(n, "");
        for (int i=0;i<n;i++)
            cin >> a[i];
        for (int i=0;i<n;i++)
            cin >> b[i];
        int ans=1000;
        vector<int>  c;
        sort(b.begin(),b.end());
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                bool f = true;
                vector<string> r(n,"");
                for (int k=0;k<n;k++)
                    r[k] = a[k];
                int tmp=0;
                c.clear();
                for (int k=0;k<l;k++){
                    if (a[i][k] != b[j][k]){
                        c.push_back(k);
                        tmp++;
                    }
                }
                for (int k=0;k<n;k++){
                    for (int h=0;h<c.size();h++){
                        if (a[k][c[h]] == '0')
                            r[k][c[h]] = '1';
                        else
                            r[k][c[h]] = '0';
                    }
                }
                sort(r.begin(),r.end());
                for (int k=0;k<n;k++)
                    if (r[k] != b[k])
                        f = false;
                if (f)
                    ans = min(ans, tmp);
            }
        }
        if (ans != 1000)
            cout << ans << endl;
        else
            cout << "NOT POSSIBLE" << endl;
    }
    return 0;
}
