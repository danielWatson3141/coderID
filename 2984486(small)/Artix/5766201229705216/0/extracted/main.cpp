#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<int> arcs[1005];

int dfs(int id, int noeud, int del, int pere=-1)
{
    int tt = 0;

    if(del==1)
    {
        tt=1;
        for(int i = 0; i < arcs[noeud].size(); i++)
        {
            int dst = arcs[noeud][i];
            if(dst==pere)continue;
            tt += dfs(id, dst, 1, noeud);
        }
        return tt;
    }

    if(arcs[noeud].size() == (1-(pere==-1)) || arcs[noeud].size()==(3-(pere==-1)))
    {
        for(int i = 0; i < arcs[noeud].size(); i++)
        {
            int dst = arcs[noeud][i];
            if(dst==pere)continue;

            tt += dfs(id, dst, 0, noeud);
        }
        return tt;
    }

    vector<int> val;
    tt = dfs(id, noeud, 1, pere)-1;

    for(int i = 0; i < arcs[noeud].size(); i++)
    {
        int dst = arcs[noeud][i];
        if(dst==pere)continue;

        val.push_back(-dfs(id, dst, 1, noeud) + dfs(id, dst, 0, noeud));
    }

    sort(val.begin(), val.end());
    if(val.size() == 1)
    {
        //tt += val[0];
        //if(tt == 0 && noeud==id) printf("wtfF : val=%d, noeud=%d\n", val[0], noeud);
        return tt;
    }

    for(int i = 0; i < 2; i++)
        tt+=val[i];

    //if(tt == 0) printf("wtf");
    return tt;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        scanf("%d", &N);

        for(int i = 0; i < N-1; i++)
        {
            int a,b;
            scanf("%d%d", &a,&b);
            arcs[a].push_back(b);
            arcs[b].push_back(a);
        }

        int best=N;

        for(int i = 1; i <= N; i++)
        {
            best=min(best, dfs(i,i,0));
        }

        printf("Case #%d: %d\n", t, best);

        for(int i = 0; i <= N; i++)
            arcs[i].clear();
    }

    return 0;
}
