#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
using namespace std;

#define SZ(x) (int(x.size()))
#define clr(a, b) (memset(a, (b), sizeof(a)))
int toInt(string s){ istringstream sin(s); int t; sin>>t; return t;}
template<class T> string toString(T x){ ostringstream sout; sout<<x; return sout.str();}
// BEGIN CUT HERE
typedef long long ll;
ll toInt64(string s){ istringstream sin(s); ll t; sin>>t;return t;}
template<class T> T gcd(T a,T b){ if(a<0) return gcd(-a,b);if(b<0) return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
// END CUT HERE

#define ll unsigned long long

const ll mod = 1000000007;



int main() {


    ifstream cin("A-small-attempt0.in");
    ofstream cout("a.txt");

    int tt;

    cin >> tt;

    for (int c = 1; c <= tt; c++)
    {
        int n, l;
        cin >> n >> l;
        string a[50], b[50];

        for (int i = 0; i < n; i++)
            cin >>a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int ans = 50;

        for (int i = 0; i < (1 << l); i++)
        {
            int t = 0;
            for (int j = 0; j < l; j++)
                if (i & (1 << j))
            {
                t++;
                for (int k = 0; k < n; k++)
                    if (a[k][j] == '0')a[k][j] = '1';
                    else a[k][j] = '0';
            }
            bool f[20];
            memset(f, 0, sizeof(f));
            int x = 1;

            for (int j = 0; j < n; j++)
            {
                int d = 0;
                for (int k = 0; k < n; k++)
                    if (b[j] == a[k] && !f[k])
                {
                    f[k] = 1;
                    d = 1;
                    break;
                }
                if (!d) {
                     x = 0;
                     break;
                }
            }
            if (x) {
                ans = min(ans, t);
            }
            for (int j = 0; j < l; j++)
                if (i & (1 << j))
            {
                for (int k = 0; k < n; k++)
                    if (a[k][j] == '0')a[k][j] = '1';
                    else a[k][j] = '0';
            }
        }
        cout << "Case #" << c << ": ";
        if (ans == 50)
            cout << "NOT POSSIBLE" << endl;
        else cout << ans << endl;
    }


    return 0;
}
