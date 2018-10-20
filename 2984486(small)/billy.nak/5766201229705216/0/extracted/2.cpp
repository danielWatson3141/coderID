#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 2000

bool vis[MAX];
vector<vector< int> > edges(MAX);


int dfs(int x)
{
    if ( vis[x] ) return 0;
    vis[x] = true;
    vector<int> v;
    for (int i=0;i<edges[x].size();i++)
    {   
        if ( vis[edges[x][i]] ) continue;
        v.push_back(dfs(edges[x][i]));
    }
    if ( v.size() == 0 ) return 1;
    if ( v.size() == 1 ) return 1;

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
   

    int a= v[0];
    int b = v[1];
    v.clear();
    return a + b + 1;
}

void solve()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    int ans = n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
            vis[j] = false;
        ans = min(ans,n - dfs(i));

 
    }

    for (int i=0;i<n;i++)
        edges[i].clear();

    printf("%d\n",ans);
}


int main()
{

    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }

}
