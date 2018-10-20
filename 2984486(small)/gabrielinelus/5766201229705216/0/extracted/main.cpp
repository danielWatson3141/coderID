#include <cstdio>
#include <vector>
#include <algorithm>

#define Nmax 1005

using namespace std;
vector<int> G[Nmax];
int N,grades[Nmax];
int root,good[Nmax];
int tstNR;

void read()
{
    scanf("%d",&N);
    int a,b;
    for(int i = 1; i < N; ++i)
    {
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        grades[a] ++;
        grades[b] ++;
    }
}
int nrn;

int DFS(int k,int dad)
{
    if(grades[k] == 1)
        return 1;
    for(vector<int>::iterator it= G[k].begin(); it != G[k].end(); ++it)
        if(*it != dad)
            good[*it] = DFS(*it,k);
    vector<int> sol;
    int ans = 0;
    if(k == root && grades[k] >= 2 || grades[k] != 2)
    {
        for(vector<int>::iterator it = G[k].begin(); it != G[k].end(); ++it)
            if(*it != dad)
                sol.push_back(good[*it]);
        sort(sol.begin(),sol.end());
        ans = sol.back();
        sol.pop_back();
        ans += sol.back();
    }
    return ans + 1;
}
int best = 9999;
void solve()
{
    best = 9999;
    int crt;
    for(int i = 1; i <= N; ++i)
    {
        root = i;
        nrn = 0;
        crt = DFS(i,0);
        if(best > N - crt)
            best = N - crt;
    }
    printf("Case #%d: %d\n",tstNR,best);
}

void init()
{
    for(int i = 1; i <= N; ++i)
    {
        G[i].clear();
        grades[i] = 0;
        good[i] = 0;
    }
}

int main()
{
    freopen("binary.in","r",stdin);
    ///freopen("binary.out","w",stdout);
    freopen("binary.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ++tstNR;
        read();
        solve();
        init();
    }
    return 0;
}
