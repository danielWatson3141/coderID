#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> edge[1005];
int degree[1005];
int n;
int dfs(int node,int pre)
{
    int big1 = -1;
    int big2 = -1;
    for(int i=0;i<edge[node].size();++i)
    {
        int to = edge[node][i];
        if(to==pre)
            continue;
        //cout<<"current "<<node<<endl;
        int t = dfs(to,node);
        //cout<<to<<" "<<t<<endl;
        if(big1==-1)
        {
            big1 = t;
            continue;
        }
        if(big1<t)
        {
            big2 = big1;
            big1 = t;
            continue;
        }
        if(big1==t)
        {
            big2 = t;
            continue;
        }
        if(big1>t)
        {
            big2 = max(big2,t);
            continue;
        }
    }
   // cout<<"return "<<node<<" "<<big1<<" "<<big2<<endl;
    if(big1==-1 && big2==-1)
        return 1;
    if(big2==-1)
        return 1;
    return big1+big2+1;
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out4.txt","w",stdout);
    int cas = 1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            degree[i]=0;
            edge[i].clear();
        }
        for(int i=1;i<n;++i)
        {
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        int ans = 0;
        for(int i=1;i<=n;++i)
        {
         //   if(degree[i]>=2)
         //   {
                int t= dfs(i,-1);
                //cout<<"node "<<i<<" "<<t<<endl;
                ans = max(ans,t);
         //   }
        }
        cout<<"Case #"<<cas++<<": ";
        cout<<n-ans<<endl;
    }
    return 0;
}
