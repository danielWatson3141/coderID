//GCJ round 1A a
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define MAXN 20
#define INF 1000000000
using namespace std;
int N;
struct EDGE
{
    int t;
}tmp;
vector<EDGE>edge[MAXN];
int num[MAXN],cnt,ans;
bool v[MAXN];
int DFS(int x,int root)
{
    v[x]=1;
    if(root==1)
    {
        if(num[x]==1)
        {
            for(int i=0;i<edge[x].size();++i)
            {
                int y=edge[x][i].t;
                int z=DFS(y,2);
                v[x]=0;
                return z;
            }
        }
        else if(num[x]>=2)
        {
            int tmp=0,sum=0;
            vector<int>L;
            for(int i=0;i<edge[x].size();++i)
            {
                int y=edge[x][i].t;
                if(v[y]) continue;
                int z=DFS(y,0);
                int w=DFS(y,2);
                //cout<<w<<" "<<z<<"\n";
                sum+=w;
                L.push_back(w-z);
            }
            tmp=sum;
            //cout<<tmp<<"\n";
            sort(L.begin(),L.end());
            //cout<<L[0]<<L[1]<<"\n";
            for(int i=L.size()-1;i>=0;--i)
            {
                if(i>=L.size()-2) tmp-=L[i];
            }
            v[x]=0;
            return tmp;
        }
    }
    else if(root==0)
    {
        if(num[x]==1)
        {
            v[x]=0;
            return 0;
        }
        else if(num[x]==2)
        {
            for(int i=0;i<edge[x].size();++i)
            {
                int y=edge[x][i].t;
                if(v[y]) continue;
                int z=DFS(y,2);
                v[x]=0;
                return z;
            }
        }
        else
        {
            int tmp=0,sum=0;
            vector<int>L;
            for(int i=0;i<edge[x].size();++i)
            {
                int y=edge[x][i].t;
                if(v[y]) continue;
                int z=DFS(y,0);
                int w=DFS(y,2);
                sum+=w;
                L.push_back(w-z);
            }
            tmp=sum;
            sort(L.begin(),L.end());
            for(int i=L.size()-1;i>=0;--i)
            {
                if(i>=L.size()-2) tmp-=L[i];
            }
            v[x]=0;
            return tmp;
        }
    }
    else if(root==2)
    {
        int sum=1;
        for(int i=0;i<edge[x].size();++i)
        {
            int y=edge[x][i].t;
            if(v[y]) continue;
            sum+=DFS(y,2);
        }
        v[x]=0;
        return sum;
    }
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int Case;
    scanf("%d",&Case);
    for(int ca=1;ca<=Case;++ca)
    {
        for(int i=0;i<MAXN;++i)
            edge[i].clear();
        memset(num,0,sizeof(num));
        scanf("%d",&N);
        int a,b;
        ans=INF;
        for(int i=0;i<N-1;++i)
        {
            scanf("%d%d",&a,&b);
            tmp.t=b;
            edge[a].push_back(tmp);
            tmp.t=a;
            edge[b].push_back(tmp);
            num[a]++;
            num[b]++;
        }
        for(int i=1;i<=N;++i)
        {
            memset(v,0,sizeof(v));
            cnt=DFS(i,1);
            ans=min(ans,cnt);
        }
        printf("Case #%d: %d\n",ca,ans);

    }
    return 0;
}
