#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <memory.h>
#include <string>

int connect[16];
vector <vector <int> > linked;
bool used[16];
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
        int num = dfs(linked[root][i]);
        node.push_back(num);
    }
    sort(node.begin(),node.end(),cmp);
    return node[0]+node[1]+1;
}

int main()
{
    int T;

   freopen("B-small-attempt0.in","r",stdin);
   freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    int x,y;
    for(int cnt = 1;cnt<=T;cnt++)
    {
        int N;
        cin>>N;
        memset(connect,0,sizeof(connect));
        linked.resize(N+1);
        for(int i=0;i<linked.size();i++) linked[i].clear();
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
            ans = MAX(ans,dfs(i));
        }
        printf("Case #%d: ",cnt);
        printf("%d\n",N-ans);
    }
    return 0;
}
