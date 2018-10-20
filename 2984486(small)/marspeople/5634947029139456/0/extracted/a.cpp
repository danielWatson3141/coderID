#include <cstdio>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<n; i++)
typedef long long int64;

int gpop(string &s) {
    int res=0;
    REP(i,s.size())
        res+=(s[i]=='1');
    return res;
}

string gxo(string &a, string &b) {
    string r;
    REP(i,a.size())
        r+='0'+(a[i]-'0')^(b[i]-'0');

    return r;
}

#define N 200
string ef[N], d[N];
bool us[N];

int main() {
    int nt,n,k;

    scanf("%d",&nt);
    REP(ct,nt) {
        scanf("%d %d",&n,&k);

        int res=INF;
        REP(i,n)
            cin >> ef[i];
        REP(i,n)
            cin >> d[i];

        REP(x0,n) {
            string p = gxo(ef[0], d[x0]);

            memset(us,0,sizeof(us));

            bool deu=1;
            us[x0]=1;
            for (int i=1;i<n;i++) {
                bool ok=0;
                REP(j,n)
                    if (!us[j] && gxo(p,ef[i])==d[j]) {
                        ok=1;
                        us[j]=1;
                        break;
                    }

                if (!ok) deu=0;
            }
            if (deu)
                res=min(res, gpop(p));
        }

        printf("Case #%d: ",ct+1);
        if (res==INF) printf("NOT POSSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
