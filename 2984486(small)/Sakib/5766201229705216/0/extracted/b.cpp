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

vector <int> v[1005];
int n;

pair<int,int> dfs(int x,int p)
{
    int i,j,k,r=0,c=1,a,b;

    vector <int > now;
    pair<int,int> tmp;

    for(i=0;i<v[x].size();i++)
    {
        j=v[x][i];

        if(j==p) continue;

        tmp=dfs(j,x);

        c+=tmp.second;

        now.push_back(tmp.second-tmp.first);
    }

    if(now.size()==0) return make_pair(0,c);

    if(now.size()==1) return make_pair(c-1,c);

    a=-1;
    b=-1;

    for(i=0;i<now.size();i++)
    {
        k=now[i];

        if(k>=a)
        {
            b=a;
            a=k;
        }

        else if(k>=b) b=k;
    }

    return make_pair(c-1-a-b,c);
}

int main()
{
    int i,j,k,T,cas,ret=0;

    freopen("B-small-attempt0(3).in","r",stdin);
    freopen("b-small.txt","w",stdout);

    scanf("%d",&T);

    for(cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);

        for(i=1;i<=n;i++) v[i].clear();

        for(i=1;i<n;i++)
        {
            scanf("%d %d",&j,&k);

            v[j].push_back(k);
            v[k].push_back(j);
        }

        ret=n-1;

        for(i=1;i<=n;i++)
        {
            ret=min(ret,dfs(i,0).first);
        }

        printf("Case #%d: %d\n",cas,ret);
    }

    return 0;
}
