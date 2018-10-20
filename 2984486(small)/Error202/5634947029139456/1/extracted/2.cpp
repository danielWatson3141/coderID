#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
typedef unsigned long long  LL;
using namespace std ;
typedef pair<int,int> PII;

struct vec{
    int x,y;
}v[200];

int x[200],y[200];
int n,xs,ys;

int cross(const vec& a,const vec & b)
{
    return a.x*b.y-a.y*b.x;
}

bool cmp(const vec &a, const vec &b)//先按象限排序，再按极角排序，再按远近排序 
{
    if (a.y == 0 && b.y == 0 && a.x*b.x <= 0)return a.x>b.x;
    if (a.y == 0 && a.x >= 0 && b.y != 0)return true;
    if (b.y == 0 && b.x >= 0 && a.y != 0)return false;
    if (b.y*a.y <= 0)return a.y>b.y;
    return cross(a,b) > 0 || (cross(a,b) == 0 && a.x < b.x); 
}


int main(){

    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    int _,k;
    scanf("%d",&_);
    for (k=1;k<=_;k++)
    // while(~scanf("%d%d%d",&n,&xs,&ys))
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&v[i].x,&v[i].y);
        for (int i=1;i<=n;i++) v[i+n].x=-v[i].x,v[i+n].y=-v[i].y;
        sort(v+1,v+2*n+1,cmp);
        // for (int i=1;i<=2*n;i++) cout<<v[i].x<<" "<<v[i].y<<endl;
        int  nx=0,ny=0;
        for (int i=1;i<=n;i++) nx+=v[i].x,ny+=v[i].y;
        xs=ys=0;
        int ans=(nx-xs)*(nx-xs)+(ny-ys)*(ny-ys);
        for(int i=n+1;i<=2*n;i++){
            nx+=v[i].x-v[i-n].x;
            ny+=v[i].y-v[i-n].y;
            ans=max(ans,(nx-xs)*(nx-xs)+(ny-ys)*(ny-ys));
        }
        printf("%d\n",ans);
        //printf("Case %d: %.12f\n",k,l);
    }
}









int dfs(int x,int y)//当人在xy处 是否清除0的状态是k 当前的计数器为sum
{
    if (vis[x][y]) return f[x][y]//如果这个状态已经被搜索过那么直接返回答案
    if (x==n) return a[x][y];
    vis[x][y]=1;//搜索过的标记
    f[x][y]=max( dfs(x+1,y+1) , dfs(x+1,y) ) +a[x][y];
    return f[x][y];
}
