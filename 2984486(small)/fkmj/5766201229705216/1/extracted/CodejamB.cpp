#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <deque>
using namespace std;
int n;
vector<int> ed[1010];
deque<int> qu;
int now;
int vv[1010],vi[1010],al[1010],de[1010];
long long anno;
int alt(int n)
{
    if(al[n]!=-1)
        return al[n];
    int r=1;
    vv[n]=1;
    for(int j=0;j<ed[n].size();j++)
        if(!vv[ed[n][j]])
            r+=alt(ed[n][j]);
    al[n]=r;
    return al[n];
}
int dl(int n)
{
    if(de[n]!=-1)
        return de[n];
    vi[n]=1;
    int r=0,ch=0,m1=10000000,m2=10000000,t;
    for(int j=0;j<ed[n].size();j++)
        if(!vi[ed[n][j]])
            ch++;
    if(ch==0)
        de[n]=0;
    if(ch==2)
    {
        for(int j=0;j<ed[n].size();j++)
            if(!vi[ed[n][j]])
                r+=dl(ed[n][j]);
        de[n]=r;
    }
    if(ch==1)
    {
        for(int j=0;j<ed[n].size();j++)
            if(!vi[ed[n][j]])
                r+=alt(ed[n][j]);
        de[n]=r;
    }
    int suc=0;
    if(ch>2)
    {
        for(int j=0;j<ed[n].size();j++)
        {
            if(!vi[ed[n][j]])
            {
                r+=alt(ed[n][j]);
                t=dl(ed[n][j])-alt(ed[n][j]);
                if(t<m2)
                {
                    swap(m2,t);
                    if(m2<m1)
                        swap(m1,m2);
                }
            }
        }
        de[n]=r+m2+m1;
    }
    return de[n];
}
int ty(int no)
{
    anno=0;
    now=no;
    for(int i=0;i<1010;i++)
        vi[i]=0,de[i]=-1,al[i]=-1,vv[i]=0;
    alt(no);
    return dl(no);
}
int work(int n_case)
{
    long long ans=0;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)
        ed[i].clear();
    for(int i=1;i<n;i++)
        cin>>a>>b,ed[a].push_back(b),ed[b].push_back(a);
    int an=10000;
    for(int i=1;i<=n;i++)
    {
        an=min(an,ty(i));
    }
    cout<<"Case #"<<n_case<<": "<<an<<"\n";
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("BL.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        work(i);
    }
}
