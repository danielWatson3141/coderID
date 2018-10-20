#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#define ll long long
using namespace std;

int deg[1002];
vector<int>v[1002];
int ddeg[20];
bool bi[1002];
bool df[1002];

int h;

int is[1002];
int isnot[1002];
int sz[1002];
int p[1002];

void dfs(int i)
{
    bi[i]=true;
    int a,b,c,d,cst_is,cst_isnt;
    int ch;
    ch=0;
    sz[i]=1;
    cst_is=cst_isnt=0;
    //cout<<"DFS at "<<i<<endl;
    for(a=0;a<v[i].size();a++)
    {
        //cout<<v[i][a]<<" "<<bi[v[i][a]]<<endl;
        if(!bi[v[i][a]])
        {
            ch++;
            c=v[i][a];
            p[ c ]=i;
            dfs(c);
            sz[i]=sz[i]+sz[c];
            cst_is=cst_is+is[c];
            cst_isnt=cst_isnt+isnot[c];
        }
    }
    isnot[i]=sz[i];
    if(ch==0)
    {
        is[i]=0;
        return;
    }
    if(ch==2)
    {
       is[i]=min(cst_is,cst_isnt);
       return;
    }
    if(ch==1)
    {
        is[i]=cst_isnt;
        return;
    }
    int z=-1;
    for(a=0;a<v[i].size();a++)
    {
        c=v[i][a];
        if(c==p[i]) continue;
        for(b=a+1;b<v[i].size();b++)
        {
            d=v[i][b];
            if(d==p[i]) continue;
            if(z==-1)
            {
                z=is[c]+is[d]+cst_isnt-isnot[c]-isnot[d];
            }
            else z=min(z,is[c]+is[d]+cst_isnt-isnot[c]-isnot[d]);
        }
    }
    is[i]=z;
    return;
}


int main()
{
    freopen("0.in","r",stdin);
    freopen("000.out","w",stdout);

    int a,b,c,d,e,x,y,z,t,n,l;

    cin>>t;

    for(int i=1;i<=t;i++)
    {
        cin>>n;

        for(a=1;a<=n;a++) v[a].clear();

        for(a=0;a<n-1;a++)
        {
            cin>>b>>c;
            v[b].push_back(c);
            v[c].push_back(b);
        }
        if(n==2)
        {
            //cout<<1<<" "<<v[1][0]<<endl;
            printf("Case #%d: 1\n",i);
            continue;
        }
        int ans=-1;

        for(a=1;a<=n;a++)
        {
            //cout<<"Starting with "<<a<<endl;
            for(b=1;b<=n;b++) bi[b]=false;
            dfs(a);
            if(ans==-1) ans=is[a];
            else ans=min(ans,is[a]);
            //for(b=1;b<=n;b++) cout<<b<<"->"<<is[b]<<" "<<isnot[b]<<endl;
        }


        printf("Case #%d: ",i);
        if(ans==-1) cout<<"NOT POSSIBLE"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}
