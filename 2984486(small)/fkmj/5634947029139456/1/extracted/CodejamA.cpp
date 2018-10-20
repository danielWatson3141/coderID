#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
string o[151],d[151],cc[151];
int xo[151];
int work(int n_case)
{
    char c[400];
    c['1']='0';
    c['0']='1';
    long long ans=0;
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++)
        cin>>o[i],cc[i]=o[i];
    for(int i=0;i<n;i++)
        cin>>d[i];
    int sw=100000;
    int th;
    bool ye;
    sort(d,d+n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            th=0;
            ye=1;
            for(int k=0;k<l;k++)
            {
                if(o[i][k]!=d[j][k])
                    xo[k]=1,th++;
                else
                    xo[k]=0;
            }
            for(int k=0;k<n;k++)
                for(int w=0;w<l;w++)
                {
                    if(xo[w])
                        cc[k][w]=c[o[k][w]];
                    else
                        cc[k][w]=o[k][w];
                }
            sort(cc,cc+n);
            for(int k=0;k<n;k++)
                if(cc[k]!=d[k])
                    ye=0;
            if(ye)
                sw=min(sw,th);
        }

    cout<<"Case #"<<n_case<<": ";
    if(sw==100000)
        cout<<"NOT POSSIBLE\n";
    else
        cout<<sw<<"\n";
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A3.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        work(i);
    }
}
