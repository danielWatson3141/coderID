#include <iostream>
#include <string.h>
using namespace std;
const int maxn = 1005,oo = 0xfffffff;
struct node{
       int v,next;
       }a[maxn*2];
int first[maxn],tot;
int f[maxn],s[maxn],visited[maxn];
int child[maxn][maxn],cnt[maxn],mins,n;
void add(int u,int v)
{
     ++tot;a[tot].v=v;a[tot].next=first[u];first[u]=tot;
}
void dfs(int x)
{
     visited[x]=1;
     int i;
     cnt[x]=0;
     for(i=first[x];i!=0;i=a[i].next){
                                       if(visited[a[i].v]==0){
                                                              dfs(a[i].v);s[x]+=s[a[i].v];
                                                              ++cnt[x];child[x][cnt[x]]=a[i].v;
                                                              }
                                       }
     ++s[x];
}
void work(int x)
{
     int i,j,sum,k;
     for(i=1;i<=cnt[x];i++)work(child[x][i]);
     if(cnt[x]==1){f[x]=s[x]-1;return ;}
     if(cnt[x]==0){f[x]=0;return ;}
     sum = 0;
     f[x] = s[x]-1;
     for(i=1;i<=cnt[x];i++)sum = sum+s[child[x][i]];
     for(i=1;i<=cnt[x];i++)
     for(j=i+1;j<=cnt[x];j++)
     {
     k = sum - s[child[x][i]] - s[child[x][j]] + f[child[x][i]] + f[child[x][j]];
     if(k<f[x])f[x]=k;
     }
}
void solve()
{
     int i;
     mins = oo;
     for(i=1;i<=n;i++)
     {
                      memset(visited,0,sizeof(visited));
                      memset(cnt,0,sizeof(cnt));
                      memset(s,0,sizeof(s));                      
                      dfs(i);
                      work(i);
                      if(f[i]<mins)mins = f[i];
                      }
     printf("%d\n",mins);
}
void init()
{
     scanf("%d",&n);
     memset(first,0,sizeof(first));
     tot=0;
     int i,x,y;
     for(i=1;i<n;i++){
                      scanf("%d%d",&x,&y);
                      add(x,y);
                      add(y,x);
                      }
}
int main(void)
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    int tc,i;
    scanf("%d",&tc);
    for(i=1;i<=tc;i++){
                       printf("Case #%d: ",i);
                       init();
                       solve();
                       }
    return 0;
}
