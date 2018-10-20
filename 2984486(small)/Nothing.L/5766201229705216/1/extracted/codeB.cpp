#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> e[1005];
bool use[1005]={false};
int dfs(int root)
{

    int childnum = 0;
    for(int i=0;i<e[root].size();i++)
        if(!use[e[root][i]]) ++childnum;
    use[root] = true;
    if(childnum < 2)
        return 1;
    else
    {
        vector<int> vt;
        for(int i=0;i<e[root].size();i++)
            if(!use[e[root][i]])
                vt.push_back(dfs(e[root][i]));
        sort(vt.begin(),vt.end());
        return vt[vt.size()-1] + vt[vt.size()-2] + 1;
    }
}
int main()
{
    int T;
    int out=1;
    int n,a,b;
    //freopen("c:\\codejam\\B-small-attempt1.in","r",stdin);
    //freopen("c:\\codejam\\B-small-attempt1.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(e,0,sizeof(e));
        scanf("%d",&n);
        int ans = n-1;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&a,&b);
            e[a].push_back(b);
            e[b].push_back(a);
        }
        for(int i=1;i<=n;i++)
        {
            memset(use,false,sizeof(use));
            int cnt = dfs(i);
            ans = min(ans,n-cnt);
        }
        printf("Case #%d: %d\n",out++,ans);
    }
    return 0;
}
