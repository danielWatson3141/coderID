#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
#define eps 1e-7
using namespace std;

#ifdef __int64
    typedef __int64 LL;
#else
    typedef long long LL;
#endif

#define maxn 2000
#define maxe 8010

struct Edge{
    int from,to,dis,next;
}edge[maxe];
int head[maxn];
int n,m,cnt;
void add(int q,int h,int len=0) {
    edge[cnt].from=q;
    edge[cnt].to=h;
    edge[cnt].dis=len;
    edge[cnt].next=head[q];
    head[q]=cnt;
    cnt++;
}
void init(){
	cnt=0;
	memset(head,-1,sizeof(head));
}

int dfs(int pos,int pre){
    int a=0,b=0,cnt=0,now;
    for(int i=head[pos];i!=-1;i=edge[i].next){
        int to = edge[i].to;
        if(to==pre)continue;
        cnt++;
        now = dfs(to,pos);
        if(now>a)b=a,a=now;
        else if(now>b)b=now;
    }
    if(cnt==0){
        return 1;
    }else if(cnt==1){

        return 1;
    }else{

        return a+b+1;
    }
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int t,n,q,h;
    int i,j,k,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init();
        for(i=0;i<n-1;i++){
            scanf("%d%d",&q,&h);
            add(q,h);
            add(h,q);
        }
        int tmp = 0;
        for(i=1;i<=n;i++){
            tmp = max(tmp,dfs(i,0));
        }
        printf("Case #%d: %d\n",++cas,n-tmp);
    }
    return 0;
}
