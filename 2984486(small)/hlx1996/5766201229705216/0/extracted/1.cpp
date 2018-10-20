#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int n,ans=2000000000;
vector<int> a[1005];
int fa[1005],size[1005];
void dfs(int u){
    size[u]=1;
    int s1=-1,s2=-1;
    for (int i=0;i<a[u].size();i++)
        if (fa[u]!=a[u][i]) {fa[a[u][i]]=u; dfs(a[u][i]);
        if (size[a[u][i]]>s1) {s2=s1; s1=size[a[u][i]];}
        else if (size[a[u][i]]>s2) {s2=size[a[u][i]];}
        }
    if (s2!=-1) size[u]+=(s1+s2);
}

int main(){
    int ttt,tt=0;
    cin>>ttt;
    while (tt++<ttt){
        scanf("%d",&n);
        ans=n;
        int x,y;
        for (int i=1;i<=n;i++)
            a[i].clear();
        for (int i=1;i<n;i++){
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i=1;i<=n;i++){
            memset(size,0,sizeof(size));
            memset(fa,0,sizeof(fa));
            dfs(i);
            ans=min(n-size[i],ans);
        }
        printf("Case #%d: %d\n",tt,ans);
    }
}
