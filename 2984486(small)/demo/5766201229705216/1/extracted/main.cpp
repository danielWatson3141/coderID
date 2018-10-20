#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include<cstdio>
using namespace std;

int n;
const int N=1010;
vector<int> sons[N];
vector<int> con[N];
bool v[N];
int ts[N];
void buildtree(int x)
{
    for(int i=0;i<con[x].size();i++)
    {
        int y=con[x][i];
        if(v[y]) continue;
        v[y]=true;
        sons[x].push_back(y);
        buildtree(y);
    }
}

int getTreesize(int x)
{
    if(ts[x]!=-1) return ts[x];
    if(sons[x].size()==0) return ts[x]=1;
    int t=1;
    for(int i=0;i<sons[x].size();i++)
        t+=getTreesize(sons[x][i]);
    return ts[x]=t;
}

int del[N];
int getMin(int x)
{
    if(del[x]!=-1) return del[x];
    int n=sons[x].size();
    if(n==0) return del[x]=0;
    if(n==1) return del[x]=getTreesize(sons[x][0]);
    int m1=100000,m2=100000;
  //  printf("n = %d\n",n);
    for(int i=0;i<n;i++)
    {
        int y=sons[x][i];
        int t=getMin(y)-getTreesize(y);
        if(t<m1)
        {
            m2=m1;
            m1=t;
        }
        else if(t<m2) m2=t;
     //   printf("t=%d\n",t);
     //   printf("%d %d %d\n",t,m1,m2);
    }
 //   printf("\n");
    return del[x]=getTreesize(x)-1+m1+m2;
}



int main()
{
    freopen("B.in","r",stdin);
    freopen("B.txt","w",stdout);
    int t;
    int cs=0;
  //  cin>>t;
  scanf("%d",&t);
    while(t--)
    {
       // cin>>n;
       scanf("%d",&n);
        for(int i=1;i<=n;i++) con[i].resize(0);
        for(int i=1;i<=n-1;i++)
        {
            int x,y;
          //  cin>>x>>y;
          scanf("%d%d",&x,&y);
            con[x].push_back(y);
            con[y].push_back(x);
        }
        int root;
        int ans=n+1;
        for(root=1;root<=n;root++)
        {
            for(int i=1;i<=n;i++) sons[i].resize(0);
            memset(v,false,sizeof(v));
            v[root]=true;
            buildtree(root);
            memset(ts,-1,sizeof(ts));
         //   getTreesize(root);
         //   cout<<"size root "<<ts[root]<<endl;
            memset(del,-1,sizeof(del));
            ans=min(ans,getMin(root));
    //         printf("root = %d del = %d\n",root,getMin(root));
        }
        printf("Case #%d: %d\n",++cs,ans);
     //   cout<<"Case #"<<++cs<<": "<<ans<<endl;
    }
    return 0;
}







