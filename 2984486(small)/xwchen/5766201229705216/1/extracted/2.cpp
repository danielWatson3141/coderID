#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

int n;
const int N = 1005;
vector<int> e[N];
int res;

int dfs(int u,int pre) {
    vector<int> son;
    for(int i=0; i<e[u].size(); ++i) {
        if(e[u][i]!=pre) {
            son.push_back(e[u][i]);
        }
    }
    //printf("%d have :",u);for(int i=0;i<son.size();++i){printf("%3d",son[i]);}puts("");
    if(son.size()==2) {
        return 1+dfs(son[0],u)+dfs(son[1],u);
    } else if(son.size()<2)
    {
        return 1;
    }
    else
    {
        vector<int> mx;
        for(int i=0;i<son.size();++i)
        {
            int tmp = dfs(son[i],u);
            mx.push_back(tmp);
        }
        sort(mx.rbegin(),mx.rend());
        return 1+mx[0]+mx[1];
    }
}



int main() {
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; ++t) {
        for(int i=0; i<N; ++i)e[i].clear();
        scanf("%d",&n);
        for(int i=1; i<n; ++i) {
            int u,v;
            scanf("%d %d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        res=n-1;
        for(int i=1; i<=n; ++i) {
            int now = dfs(i,i);
            //printf("now = %d\n",now);
            if(res>n-now) {
                res= n-now;
                //printf("now = %d\n",now);
                //printf("i = %d\n",i);
            }
        }
        printf("Case #%d: ",t);
        printf("%d\n",res);
    }
    return 0;
}
