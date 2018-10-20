#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn=1111;
const int maxm=11111;
const int INF=0x3f3f3f3f;
int head[maxn];
int to[maxm];
int next[maxm];
int edge;
void prepare(){
    memset(head,-1,sizeof(head));
    edge=0;
}
void addedge(int u,int v){
    to[edge]=v,next[edge]=head[u],head[u]=edge++;
}
int n;
int size[maxn];
int num[maxn];
//int a[maxn],cnt;
int solve(int u,int p){
    int son=0;
    num[u]=1;
    int lson,rson;
    lson=0,rson=0;
    for (int i=head[u];i!=-1;i=next[i]){
        int v=to[i];
        if (v==p) continue;
        //a[son++]=v;
        son++;
        if (lson==0) lson=v;
        else if (rson==0) rson=v;
        int tmp=solve(v,u);
        size[v]=tmp;
        //cout<<"size "<<v<<" ="<<tmp<<endl;
        num[u]+=num[v];
    }
    //cout<<"u="<<u<<"--- son="<<son<<endl;
    //cout<<"------"<<endl;
    if (son==0) return 0;
    else if (son==1) return num[u]-1;
    else if (son==2) return size[lson]+size[rson];
    else {
        int mx=0;
        int mxp=0;
        int mx2=0;
        int mx2p=0;
        int res=INF;
        for (int i=head[u];i!=-1;i=next[i]){
            int v=to[i];
            if (v==p) continue;
            for (int j=head[u];j!=-1;j=next[j]){
                int v2=to[j];
                if (v2==p) continue;
                if (v2==v) continue;
                if (size[v]+size[v2]+num[u]-1-num[v]-num[v2]<res)res=size[v]+size[v2]+num[u]-1-num[v]-num[v2];
            }
        }
        return res;
    }
}

int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("out999.txt","w",stdout);
    int T;
    int cas=0;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        prepare();
        for (int i=0;i<n-1;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        int ans=INF;
        for (int i=1;i<=n;i++) {
            int tmp=solve(i,0);
            //cout<<i<<"  ---  "<<tmp<<endl;
            if (tmp<ans) ans=tmp;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
