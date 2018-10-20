//made by kuailezhish
//gl && hf
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stack>
#include <sstream>
#include <complex>
#include <cstring>
#include <ctime>
#define mem(a,b) memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define lINF 0x3f3f3f3f3f3f3f3fll
#define dINF 1e30
#define eps 1e-7
#define lld long long
#define sqr(x) ((x)*(x))
#define ab(x) (((x)>0) ? (x) : -(x))
#define PI 3.14159265358979323846
#define psl pair<sting,lld>
#define pll pair<lld,lld>
#define pii pair<int,int>
#define mp make_pair
#define er(i) (1ll<<(i))
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define cp complex<double>
#define here printf("!!!!!!!!\n");
#define foreach(it,v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define upmin(a,b) {if ((a)>(b)) (a)=(b);}
#define upmax(a,b) {if ((a)<(b)) (a)=(b);}
#define upmod(a,b) (a)=((a)%(b)+(b))%(b)
#define equ(a,b) (fabs(a-b)<eps)
#define rin freopen("in.txt","r",stdin)
#define pout freopen("out.txt","w",stdout)
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;

#define maxn 21000

struct node{
    int ver,nxt;
}edge[maxn];

int adj[maxn],tot;
int n;

void addedge(int u,int v){
    edge[tot].ver=v; edge[tot].nxt=adj[u]; adj[u]=tot++;
    edge[tot].ver=u; edge[tot].nxt=adj[v]; adj[v]=tot++;
}

int num[maxn];
int dp[maxn][2];

void predfs(int s,int pre){
    int i,j,tem,y;
    for (j=adj[s]; j!=-1; j=edge[j].nxt){
        y=edge[j].ver;
        if (y!=pre){
            predfs(y,s);
            num[s]+=num[y]+1;
        }
    }
}

void dfs(int s,int pre){
    int i,j,tem,y;
    dp[s][1]=num[s]; dp[s][0]=0;
    int min1,min2,t1,t2;
    min1=min2=-1;
    for (j=adj[s]; j!=-1; j=edge[j].nxt){
        y=edge[j].ver;
        if (y!=pre){
            dfs(y,s);
            if (min1==-1){min1=num[y]-dp[y][0]; t1=num[y];}
            else if (num[y]-dp[y][0]>min1){
                min2=min1; t2=t1;
                min1=num[y]-dp[y][0]; t1=num[y];
            }else{
                if (min2==-1) {min2=num[y]-dp[y][0]; t2=num[y];}
                else {
                    if (num[y]-dp[y][0]>min2){
                        min2=num[y]-dp[y][0]; t2=num[y];
                    }
                }
            }
        }
    }
    if (min2==-1) dp[s][0]=dp[s][1];
    else dp[s][0]=num[s]-min1-1-min2-1;
}

int process(int x){
    int i,j,tem;
    mem(num,0);
    predfs(x,-1);
    dfs(x,-1);
    return min(dp[x][0],dp[x][1]);
}

int main(){
    int i,j,tem,T,cas=0;
    rin;pout;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        mem(adj,-1); tot=0;
        for (i=1; i<n; i++){
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        int ans=n-1;
        for (i=1; i<=n; i++){
            tem=process(i);
            ans=min(ans,tem);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}






