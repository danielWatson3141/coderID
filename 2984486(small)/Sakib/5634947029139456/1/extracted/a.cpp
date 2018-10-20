#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

int n,l;
string d[200],b[200],tmp[200];

string xr(string p,string q)
{
    int i,j,k;
    string r="";

    for(i=0;i<p.length();i++)
    {
        if(p[i]==q[i]) r+="0";
        else r+="1";
    }

    return r;
}


int main()
{
    int i,j,k,T,cas,ret=0,now;
    string s,t,x;

    freopen("A-large(4).in","r",stdin);
    freopen("a-large.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d %d",&n,&l);

        for(i=0;i<n;i++) cin>>b[i];
        for(i=0;i<n;i++) cin>>d[i];

        sort(d,d+n);

        ret=1000;

        for(i=0;i<n;i++)
        {
            x=xr(d[0],b[i]);

           // cout<<x<<endl;

            for(j=0;j<n;j++) tmp[j]=xr(b[j],x);

            sort(tmp,tmp+n);

            for(j=0;j<n;j++)
            {
                if(tmp[j]!=d[j]) break;

            }

            //printf(":THIS : %d\n",j);

            if(j<n) continue;

            now=0;

            for(j=0;j<l;j++) if(x[j]=='1') now++;

            ret=min(ret,now);
        }

        printf("Case #%d: ",cas);

        if(ret<1000) printf("%d\n",ret);
        else printf("NOT POSSIBLE\n");
    }

    return 0;
}
