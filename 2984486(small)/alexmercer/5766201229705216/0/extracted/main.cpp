#define FROM_FILE
#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
ifstream fin("in.txt");
#define cin fin
#endif

#ifdef TO_FILE
ofstream fout("out.txt");
#define cout fout
#endif

const int MAXN=1000 + 10;
//const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;
vector<int> g[MAXN];
//int sz[MAXN];
int dp[MAXN];

void dfs(int u,int par)
{
    vector<int> op;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==par)continue;
        dfs(v,u);
        op.PB(dp[v]);
    }
    sort(All(op));
    if(op.size()<2)//bayad bekanamesh
        dp[u]=1;
    else
        dp[u]=1+op.back()+op[op.size()-2];

}

int bst(multiset<int>& s)
{
    if(s.size()<2)
        return 1;
    multiset<int>::iterator it;
    it=s.end();
    it--;
    int ans=*it;
    it--;
    ans+=*it;
    ans++;
    return ans;
}

int fans=0;

void dfs2(int u,int par,int dpar)
{
    multiset<int> op;
    if(dpar!=-1)
        op.insert(dpar);
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==par)continue;
        op.insert(dp[v]);
    }
    fans=max(fans,bst(op));
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==par)continue;
        op.erase(op.find(dp[v]));
        dfs2(v,u,bst(op));
        op.insert(dp[v]);
    }
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)g[i].clear();
        fans=0;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            u--;v--;
            g[u].PB(v);
            g[v].PB(u);
        }
        dfs(0,-1);
        dfs2(0,-1,-1);
        cout<<"Case #"<<z<<": "<<n-fans<<endl;
    }
    return 0;
}
