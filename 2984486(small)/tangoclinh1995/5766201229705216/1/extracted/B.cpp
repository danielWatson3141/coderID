#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>

using namespace std;

int tcase,n;
vector<int> g[1003];

int f[1003],father[1003],big[1003];
int child[1003];
int res;

bool cmp(int a, int b) { return f[a]-big[a]<f[b]-big[b]; }

int visit(int u) {
    big[u]=1; //Include u

    for (vector<int>::iterator it=g[u].begin(); it!=g[u].end(); ++it)
        if (father[*it]==-1) {
            father[*it]=u;
            visit(*it);
            big[u]+=big[*it];
        }

    int nchild=0;

    //printf("Father %d big=%d:\n",u,big[u]);
    for (vector<int>::iterator it=g[u].begin(); it!=g[u].end(); ++it)
        if (father[*it]==u) {
            child[++nchild]=*it;
            //printf("   Child %d f=%d\n",*it,f[*it]);
        }

    if (nchild==0)
        f[u]=0;
    else if (nchild==1)
        f[u]=big[child[1]]; //Cut all
    else {
        sort(child+1,child+nchild+1,cmp);
        f[u]=(big[u]-1)+(f[child[1]]-big[child[1]])+(f[child[2]]-big[child[2]]);
    }
}

int solveForRoot(int u) {
    //printf("Root=%d\n",u);

    for (int v=1; v<=n; ++v) father[v]=-1;
    father[u]=0;
    visit(u);

    if (f[u]<res) res=f[u];
    //printf("Root=%d res=%d\n\n\n",u,f[u]);
}

int main() {
    freopen("B-large.in","r",stdin);
    freopen("B.out","w",stdout);

    scanf("%d",&tcase);

    for (int tid=1; tid<=tcase; ++tid) {
        scanf("%d",&n);

        for (int i=1; i<=n; ++i) g[i].clear();

        int u,v;

        for (int i=1; i<n; ++i) {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        res=n;
        for (v=1; v<=n; ++v) solveForRoot(v);
        printf("Case #%d: %d\n",tid,res);
    }

    return 0;
}
