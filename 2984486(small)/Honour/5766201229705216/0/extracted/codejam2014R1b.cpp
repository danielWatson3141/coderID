//Bismillahir Rahmanir Rahim
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <sstream>
using namespace std;
int ar[20][20],pr[20][20],ap[20];
int find(int a,int n,int m)
{
    //cout<<a<<" kjkvkjzj\n\n";
    int s,d,f,g,h,j,k,l;
    for(s=1;s<=n;s++)
    {
        for(d=1;d<=n;d++)
        {
            pr[s][d]=ar[s][d];
        }
    }
    for(s=0;s<m;s++)
    {
        if((a & (1<<s)))
        {
            d=s+1;
            for(f=1;f<=n;f++)
            {
                if(ar[d][f]==1)
                {
                    pr[d][f]=0;
                    pr[f][d]=0;
                }
            }
        }
    }
    for(s=1;s<=n;s++)
    {
        for(d=1;d<=n;d++)
        {
            if(pr[s][d]!=pr[d][s])
            {
                pr[s][d]=0;
                pr[d][s]=0;
            }
        }
    }
    memset(ap,0,sizeof(ap));
    for(s=1;s<=n;s++)
    {
        for(d=1;d<=n;d++)
        {
            if(pr[s][d]) ap[s]++;
            //cout<<pr[s][d]<<" ";
        }
        //cout<<endl;
    }
    int count[5];
    memset(count,0,sizeof(count));
    l=0;
    k=0;
    for(s=1;s<=n;s++)
    {
        if(ap[s]) k++;
        if(ap[s]>3) return -1;
        if(ap[s]==2)
        {
            l++;
            if(l>1) return -1;
        }
        count[ap[s]]++;
    }
    if(count[2]!=1) return -1;
    return k;
}
int check(int a)
{
    int s=0,d;
    while(a)
    {
        d=a%2;
        if(d) s++;
        a=a/2;
    }
    return s;
}
int main()
{
    int a,s,d,f,g,h,j,k,l,q,ans,flag,big;
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    cin>>a;
    for(s=1;s<=a;s++)
    {
        memset(ar,0,sizeof(ar));
        cin>>d;
        ans=d-1;
        for(f=1;f<=d-1;f++)
        {
            cin>>g>>h;
            ar[g][h]=1;
            ar[h][g]=1;
        }
        big=1<<d;
        for(f=0;f<big;f++)
        {
            g=find(f,d,d);
            if(g!=-1)
            {
                //cout<<f<<' ';
                h=d-g;
                //cout<<h<<endl;
                ans=min(ans,h);
            }
        }
        printf("Case #%d: %d\n",s,ans);
    }
}
