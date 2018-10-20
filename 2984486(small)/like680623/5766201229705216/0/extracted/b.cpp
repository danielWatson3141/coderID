#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <vector>
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

int n, x[20], y[20];
bool de[20];

bool used[20];
int uh;
int b[20][20];

bool isTree(int x) {
    used[x] = 1;
    uh++;

    int g = 0;
    for (int i = 1; i <= n; i++)
        if (b[i][x] && !used[i])
        {
            g++;
        }
    if (g == 0)return 1;
    if (g == 2) {

        int x1, x2, u = 0;

        for (int i = 1; i <= n; i++)
            if (b[i][x] && !used[i]) {
                u++;
                if (u == 1)x1 = i;
                else x2 = i;
            }
        if (u != 2)return 0;
        return (isTree(x1) && isTree(x2));
    }
    return 0;

}




bool fun() {

    int u = 0;
    int k = 0;

    for (int i = 1; i <= n; i++) {
        int h = 0;
        for (int j = 1; j <= n; j++)
            if (b[i][j])
                h++;
        if (h == 2) {
            u = i;
            k++;
        }
    }

    if (k != 1)return 0;
   // cout << "u: " << u << endl;
    uh = 0;
    memset(used, 0, sizeof(used));
    return isTree(u);
}





int main() {

    int tt;

    ifstream cin("B-small-attempt0.in");
    ofstream cout("a.txt");

    cin >> tt;

    for (int c = 1; c <= tt; c++)
    {

        cin >> n;
        for (int i = 0; i < n - 1; i++)
            cin >> x[i] >> y[i];


        int ret = n;
        bool v[20];

        for (int i = 0; i < (1 << n); i++)
        {
            memset(v, 0, sizeof(v));
            int t = 0;

            for (int j = 0; j < n; j++)
                if (i & (1 << j))
            {
                v[j + 1] = 1;
                //cout << j + 1 << " ";
                t++;
            }

            //cout << endl;

            memset(b, 0, sizeof(b));

            for (int j = 0; j < n - 1; j++)
            {
                if (!v[x[j]] && !v[y[j]]){
                    b[x[j]][y[j]] = b[y[j]][x[j]] = 1;
                }
            }


            if (n - t <= 1) {
                ret = min(ret, t);
            }
            else if (fun()) {
                //cout << "ok   "  << uh << endl;
                if (uh == n - t)
                //{
                    ret = min(ret, t);
                //}
            }
        }

        cout << "Case #" << c << ": ";
        cout << ret << endl;
    }
}
