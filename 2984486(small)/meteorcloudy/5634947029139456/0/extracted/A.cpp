#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <queue>
#include <vector>
#include <set>
#define maxn 200
#define oo 1000000000
#define clearAll(a) memset(a,0,sizeof(a))
#define sq(a) ((a)*(a))

using namespace std;

typedef long long ll;

ll a[maxn];
ll b[maxn];
ll c[maxn][maxn];
int n;
int l;
int flagx[maxn];
int flagy[maxn];

ll deal(string s){
    ll res = 0;
    int l = s.length();
    for (int i=0;i<l;i++)
        res = res * 2 + (s[i]-'0');
    return res;
}

int calc(ll x){
    int res =0;
    while (x)
    {
        res += (x%2);
        x/=2;
    }
    return res;
}

int main()
{
    freopen("E:\\codejam\\input.txt","r",stdin);
    freopen("E:\\codejam\\output.txt","w",stdout);

    int tt;
    cin >> tt;
    int id = 0;
    while (tt--)
    {
        cin >> n >> l;
        string s;

        for (int i=0;i<n;i++)
        {
            cin >> s;
            a[i] = deal(s);
        }

        for (int i=0;i<n;i++)
        {
            cin >> s;
            b[i] = deal(s);
        }

        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                c[i][j]=a[i]^b[j];

        int val;
        int ans = oo;
        for (int k=0;k<n;k++)
        {
            clearAll(flagx);
            clearAll(flagy);
            val = c[0][k];
            flagx[0]++;
            flagy[k]++;
            for (int i=1;i<n;i++){
                for (int j=0;j<n;j++){
                    if (c[i][j]==val){
                        flagx[i]++;
                        flagy[j]++;
                        break;
                    }
                }
            }
            bool flag = true;
            for (int i=0;i<n&&flag;i++)
                flag = flag && (flagx[i]==1);
            for (int i=0;i<n&&flag;i++)
                flag = flag && (flagy[i]==1);     
            if (flag)
                ans = min(ans,calc(val));
        }
        id++;
        printf("Case #%d: ",id);
        if (ans==oo)
            cout << "NOT POSSIBLE" <<endl;
        else cout << ans <<endl;

    }
    return 0;
}
