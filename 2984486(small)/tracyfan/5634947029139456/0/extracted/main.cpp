#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

string flow[155];
string targ[155];
string tmp_flow[155];

int main(int argc, const char * argv[])
{
    freopen("A1.txt", "r", stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;

    for (int cas = 1; cas <= T; cas++) {
        int n, L;
        cin >> n >> L;
            int mi = 1000000;
        for (int i = 0; i < n; i++) {
            cin >> flow[i];
        }
        for (int i = 0;i < n;i ++) {
            cin >> targ[i];
        }
        for (int i = 0;i < n;i ++) {
            for (int j=0;j<n;j++) {
                tmp_flow[j] = flow[j];
            }
            int tmpa = 0;
            for (int j = 0;j < L;j++)
                if (targ[0][j] != flow[i][j]) {
                    tmpa++;
                    for (int k=0;k<n;k++) {
                        if (tmp_flow[k][j] == '1') {
                            tmp_flow[k][j] ='0';
                        } else {
                            tmp_flow[k][j]='1';
                        }
                    }
                }
            long long a[155], b[155];
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            for (int j=0;j<n;j++)
                for (int k=0;k<L;k++) {
                    a[j] = a[j]*2LL + (tmp_flow[j][k]-'0');
                    b[j]=b[j]*2LL+(targ[j][k]-'0');
                }
            sort(a,a+n);
            sort(b,b+n);
            bool flag = false;
            for (int j=0;j<n;j++) {
                if (a[j]!=b[j]) flag = true;
            }
            if (!flag) mi = min(mi, tmpa);
        }
        printf("Case #%d: ", cas);
        if (mi >= 10000) puts("NOT POSSIBLE");
        else printf("%d\n",mi);
    }
    
}

