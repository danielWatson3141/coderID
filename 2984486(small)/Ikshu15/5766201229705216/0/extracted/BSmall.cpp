/*
* Author: Ikshu Bhalla
* Language: C++
*/
#include<bits/stdc++.h>
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define vi vector<int>
#define vs vector<string>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define fori(s,e) for(i=s;i<=e;i++)
#define forj(s,e) for(j=s;j<=e;j++)
#define fork(s,e) for(k=s;k<=e;k++)
#define rep(i,s,e) for(int i=s;i<=e;i++)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define ull unsigned long long
#define ll long long
#define imax INT_MAX
#define imin INT_MIN
#define sz(x) (int)x.size()
#define ln(s) s.length()
#define ppb pop_back
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define pii pair<int,int>
#define psi pair<string,int>
#define in(c,x) scanf("%"#c,&x)
#define out(c,x) printf("%"#c" ",x)
#define aa first
#define bb second
#define Endl endl
using namespace std;
int readint()
{
    int t=0;
    char c,ch;
    ch=getchar();
    if (ch=='-') c=getchar();
    else c=ch;
    while(c<'0' || c>'9')
        c=getchar();
    while(c>='0' && c<='9')
    {
        t=(t<<3)+(t<<1)+c-'0';
        c=getchar();
    }
    if (ch=='-' ) return -t;
    else return t;
}
int cnt=0;
int vis[10010];
vvi adj;
void dfs(int x)
{
    int i;
    vis[x]=1;
    cnt++;
    int child=0;
    fori(0,sz(adj[x])-1)
    {
        if (!vis[adj[x][i]]) child++;
    }
    if (child==1) return;
    else
    {
        fori(0,sz(adj[x])-1)
        {
            if (!vis[adj[x][i]])
            {
                dfs(adj[x][i]);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int i,j,k,n,m,t,T;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("OutBSmall.txt","w",stdout);
    cin>>t;
    T=t;
    while(t--)
    {
        cin>>n;
        adj.resize(n);
        adj.clear();
        fori(0,n-2)
        {
            int a,b;
            cin>>a>>b;
            a--,b--;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ans=imax;
        fori(0,n-1)
        {
            mem(vis,0);
            if (sz(adj[i])<=2)
            {
                cnt=0;
                dfs(i);
                ans=min(ans,n-cnt);
            }
        }
        cout<< "Case #"<<T-t<< ": ";
        cout<<ans<<endl;
    }
    return 0;
}
