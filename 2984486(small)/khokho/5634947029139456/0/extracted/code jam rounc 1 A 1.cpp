#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
using namespace std;
    int t,l,n,i,c,j,w,r,max1,o,p,k[40];
    string a[1000],b[1000],d[1000];
main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("out.out","w+",stdout);
    cin>>t;
    for(o=0; o<t; o++)
    {
        cin>>n>>l;
        p=0;
        for(i=0; i<n; i++)
            cin>>a[i];

        for(i=0; i<n; i++)
            cin>>b[i];

        r=1;
        for(i=0; i<l; i++)
            r *= 2;
        for(i=0; i<n; i++)
            d[i]=a[i];
        sort(b,b+n);
        for(i=0; i<l; i++)
            k[i]=0;
        max1=500;
        for(w=0; w<r; w++)
        {
            p=0;
            for(j=0; j<l; j++)
            {
                    if(k[j]==1)p++;
                    for(c=0; c<n; c++)
                    {
                        if(a[c][j]=='1'&&k[j]==1)d[c][j]='0';
                        if(a[c][j]=='0'&&k[j]==1)d[c][j]='1';
                        if(a[c][j]=='1'&&k[j]==0)d[c][j]='1';
                        if(a[c][j]=='0'&&k[j]==0)d[c][j]='0';
                    }
            }

            sort(d,d+n);
            c=0;
            for(i=0; i<n; i++)
                if(d[i]!=b[i])c=1;

            if(c==0&&max1>p){max1=p;}

            j=0;
            while(k[j]>=1)
            {
                k[j]=0;
                j++;
            }
            k[j]++;
        }
        if(max1<500)cout<<"Case #"<<o+1<<": "<<max1<<endl;
        if(max1==500)cout<<"Case #"<<o+1<<": "<<"NOT POSSIBLE"<<endl;
    }

}
