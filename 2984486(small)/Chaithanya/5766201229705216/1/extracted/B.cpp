//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL
int vis[2000];
vector<int> g[2000];
int dfs(int root)
{
    int max1,max2,i,len,k;
    max1=max2=-INF;
    vis[root]=1;
    len=g[root].size();
    for(i=0;i<len;i++)if(!vis[g[root][i]])
    {
        k=dfs(g[root][i]);
        if(k>max1){max2=max1;max1=k;}
        else if(k>max2)max2=k;
    }
    if(max1==-INF || max2==-INF)return 1;
    else return max1+max2+1;
}
int main()
{
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    int test_cases,Testno;
    int i,n,x,y,maxx;

    cin>>test_cases;
    for(Testno=1;Testno<=test_cases;Testno++)
    {
        printf("Case #%d: ",Testno);
//___________________________________________

        cin>>n;
        for(i=1;i<n;i++)
        {
            cin>>x>>y;
            g[x-1].push_back(y-1);
            g[y-1].push_back(x-1);
        }
        for(i=0,maxx=-INF;i<n;i++)
        {
            init(vis,0);
            maxx=max(dfs(i),maxx);
        }
        cout<<n-maxx;
        for(i=0;i<n+20;i++)g[i].clear();

//___________________________________________
        Done: printf("\n");
    }

return 0;
}
