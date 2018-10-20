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
int ar[1009],pr[1009],ap[1009],temp[1009];
string aa;
int find(int a,int n,int m)
{
    int s,d,f,g,h,j,k,l;
    for(s=1;s<=n;s++)
    {
        temp[s]=pr[s];
    }
    //cout<<a<<endl;
    for(s=0;s<m;s++)
    {
        if((a & (1<<s)))
        {
            //cout<<s<<" ";
            for(d=1;d<=n;d++)
            {
                temp[d] ^= 1 << s;
                //cout<<temp[d]<<" ";
            }
            //cout<<endl;
        }
    }
    //cout<<endl;
    sort(temp+1,temp+n+1);
    for(s=1;s<=n;s++) if(ar[s]!=temp[s]) return 0;
    return 1;
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
int make()
{
    int a,s,d,f,g,h,j,k,l;
    a=aa.size();
    reverse(aa.begin(),aa.end());
    s=0;
    d=1;
    for(f=0;f<a;f++)
    {
        if(aa[f]=='1') s=s+d;
        d=d*2;
    }
    //cout<<s<<" ";
    return s;
}
int main()
{
    int a,s,d,f,g,h,j,k,l,q,ans,flag;
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
    cin>>a;
    for(s=1;s<=a;s++)
    {
        cin>>d>>f;
        for(g=1;g<=d;g++)
        {
            cin>>aa;
            ar[g]=make();
        }
        for(g=1;g<=d;g++)
        {
            cin>>aa;
            pr[g]=make();
        }
        sort(ar+1,ar+1+d);
        ans=1000;
        flag=0;
        l=1<<f;
        for(g=0;g<l;g++)
        {
            //cout<<g<<" ";
            h=find(g,d,f);
            if(h)
            {
                j=check(g);
                //cout<<j<<" ";
                ans=min(ans,j);
                flag=1;
            }
        }
        if(flag) printf("Case #%d: %d\n",s,ans);
        else printf("Case #%d: NOT POSSIBLE\n",s);
    }
}
