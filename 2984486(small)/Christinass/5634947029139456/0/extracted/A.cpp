#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAXN 205
#define INF 10000
int n,l;
string a[MAXN],b[MAXN],c[MAXN];
map<char,char> ma;
map<string,int> p;

bool check(int stat)
{
    for (int i=0;i<n;i++)
    {
        c[i]=a[i];
        for (int j=0;j<l;j++)
            if ((stat>>j)&1) c[i][j]=ma[c[i][j]];
    }
    sort(c,c+n);
    for (int i=0;i<n;i++)
        if (b[i]!=c[i]) return 0;
    return 1;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    ma['0']='1';
    ma['1']='0';
    int cas;
    scanf("%d",&cas);
    for (int h=1;h<=cas;h++)
    {
        p.clear();
        scanf("%d%d",&n,&l);
        for (int i=0;i<n;i++) cin>>a[i];
        for (int i=0;i<n;i++) cin>>b[i];
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
            {
                string tmp="";
                for (int k=0;k<l;k++)
                {
                    if (a[i][k]==b[j][k]) tmp+="0";
                    else tmp+="1";
                }
                p[tmp]++;
            }
        int ans=INF;
        for (map<string,int>::iterator it=p.begin();it!=p.end();++it)
        {
            if (it->second==n)
            {
                string tmp=it->first;
                int res=0;
                for (int i=0;i<l;i++)
                    res+=(tmp[i]=='1');
                ans=min(ans,res);
            }
        }
        if (ans>100)
            printf("Case #%d: NOT POSSIBLE\n",h);
        else
            printf("Case #%d: %d\n",h,ans);
    }
    return 0;
}
