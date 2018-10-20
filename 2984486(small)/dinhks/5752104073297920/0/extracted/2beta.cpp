#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[2000];
int main()
{
    freopen("E:\\in","r",stdin);
    freopen("E:\\out","w",stdout);
    int i,j,t,n;
    cin>>t;
    int nGood=0;
    int nBad=0;
    long long sum=0;
    for(int tt=1;tt<=t;++tt)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;++i)
            cin>>a[i];
        for(i=0;i<n;++i)
            sum+=a[i]*i;
        double rate1=(sum*1.0)/(n*(n-1)*(n-1)/4.0);
        //cout<<rate1<<"\n";
        sum=0;
        for(i=0;i<n;++i)
            for(j=i+1;j<n;++j)
            if(a[i]<a[j])
            sum++;
        double rate2=sum/(n*(n-1)/4.0);
        //cout<<rate2<<"\n";
        double rate=(rate1+rate2)/2;
        //cout<<rate<<"\n";
        if(rate>1.012)
            {
                cout<<"Case #"<<tt<<": BAD\n";
                nBad++;
            }
        else
            {
                cout<<"Case #"<<tt<<": GOOD\n";
                nGood++;

            }
    }
//cout<<nGood<<"  "<<nBad<<"\n";
}
