#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;

int n,l;
string o[200],d[200];
int k[200];

int fun2()
{
    int s[200]={0};
    int res=0;
    int si=0;
    for(int i=0;i<l;i++)
        if(k[i]==1)
            res++;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j]==1)
                continue;
            int si2=0;
            for(int ij=0;ij<l;ij++)
            {
                int aux=o[i][ij]-'0';
                if(k[ij]==1)
                    aux=1-aux;
                if(aux==d[j][ij]-'0')
                    si2++;
            }
            if(si2==l)
            {
                si++;
                s[j]=1;
                break;
            }
        }
    }
    if(si==n)
        return res;
    else
        return 1<<30;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin>>T;
    for(int I=1;I<=T;I++)
    {
        cin>>n>>l;
        for(int i=0;i<n;i++)
            cin>>o[i];
        for(int i=0;i<n;i++)
            cin>>d[i];
        int res=1<<30;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<l;j++)
                k[j]=0;
            for(int j=0;j<l;j++)
                if(d[0][j]!=o[i][j])
                    k[j]=1;
            res=min(res,fun2());
        }

        cout<<"Case #"<<I<<": ";
        if(res==1<<30)
            cout<<"NOT POSSIBLE"<<endl;
        else
            cout<<res<<endl;
    }
}
