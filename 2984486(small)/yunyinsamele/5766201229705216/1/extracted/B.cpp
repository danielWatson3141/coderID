#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <string>

int connect[1010];
vector <vector <int> > linked;
bool used[1010];
int DP[1010][1010];

int MAX(int a,int b) { return a>b?a:b; }
int RT;
bool cmp(int a,int b) { return a>b; }

int dfs(int root)
{
    used[root] = true;
    if(connect[root]==1||(root!=RT&&connect[root]==2))
    {
        return 1;
    }
    vector <int> node;
    node.clear();
    for(int i=0;i<linked[root].size();i++)
    {
        if(used[linked[root][i]]==true) continue;
        if(DP[root][i]==-1) DP[root][i] = dfs(linked[root][i]);
        node.push_back(DP[root][i]);
    }
    sort(node.begin(),node.end(),cmp);
    return node[0]+node[1]+1;
}

int main()
{
    int T;

   freopen("B-large.in","r",stdin);
   freopen("B-large.out","w",stdout);
    cin>>T;
    int x,y;
    linked.resize(1010);
    for(int cnt = 1;cnt<=T;cnt++)
    {
        cerr<<cnt<<endl;
        //cerr<<"==================="<<endl;
        int N;
        cin>>N;
        memset(connect,0,sizeof(connect));
        for(int i=0;i<N+1;i++) linked[i].clear();
        for(int i=0;i<N-1;i++)
        {
            cin>>x>>y;
            connect[x]++;
            connect[y]++;
            linked[x].push_back(y);
            linked[y].push_back(x);
        }
        int ans = 0;
        for(int i=1;i<=N;i++)
        {
            RT=i;
            memset(used,false,sizeof(used));
            memset(DP,-1,sizeof(DP));
            ans = MAX(ans,dfs(i));
        }
        printf("Case #%d: ",cnt);
        printf("%d\n",N-ans);
    }
    return 0;
}
