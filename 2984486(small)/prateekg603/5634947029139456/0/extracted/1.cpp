#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <fstream>

using namespace std;

int ones[42];
int zeros[42];

int req_ones[42];
int req_zeros[42];

int main()
{
    int t,n,l;
    string s;
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    for ( int L = 1; L <= t; L++ ) {
        cin >> n >> l;
        vector <string> v1,v2;
        for ( int i = 0; i < n; i++ ) {
            cin >> s;
            v1.push_back(s);
        }
        for ( int i = 0; i < n; i++ ) {
            cin >> s;
            v2.push_back(s);
        }
        int ans = 1000000;
        for ( int i = 0; i < n; i++ ) {
            int a[42];
            int vis[152];
            memset(a, 0, sizeof(a));
            memset(vis, 0, sizeof(vis));
            int ct = 0;
            for ( int j = 0; j < l; j++ ) {
                if ( v2[0][j] != v1[i][j] ) {
                   a[j] = 1;
                   ct++;
                }
            }
            int fl = 0;
            vis[i] = 1;
            for ( int j = 1; j < n; j++ ) {
                s = "";
                for ( int k = 0; k < l; k++ ) {
                    int z = (v2[j][k]-48)^a[k];
                    s.push_back((char)(z+48));   
                }
                int flag = 0;
                for ( int k = 0; k < n; k++ ) {
                    if ( vis[k] ) continue;
                    if ( s == v1[k] ) {
                       vis[k] = 1;
                       flag = 1;
                    }
                }
                if ( flag == 0 ) {
                     fl = 1;
                     break;
                }
            }          
            if ( fl ) continue;
            ans = min(ans, ct);  
        }
        cout << "Case #" << L << ": ";
        if ( ans == 1000000 ) cout << "NOT POSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}
