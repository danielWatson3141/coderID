#include<iostream>
#include<stdio.h>
using namespace std;
main()
{
    freopen("C-small-attempt10.in","r",stdin);
    freopen("C-small-attempt8.out","w+",stdout);
    int n,i,j,r,c,m,t,o,mt,k,p,l,a[51][51];
    cin>>l;
    for(mt=1; mt<=l; mt++)
    {
        cin>>r>>c>>t;
        n=r;
        m=c;
        k=0;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                a[i][j]=0;
        if(t==n*m-1)
        {
            cout<<"Case #"<<mt<<":"<<endl;
            a[0][0]=2;
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    if(a[i][j]==2)cout<<"c";else cout<<"*";
                }
                cout<<endl;
            }
            continue;
        }
        if(((n==1)||(m==1))&&(t>=n*m)){cout<<"Case #"<<mt<<":"<<endl<<"Impossible"<<endl; continue;}
        if((n==1||m==1)&&t<n*m)
        {
            cout<<"Case #"<<mt<<":"<<endl;
            k=0;
            a[n-1][m-1]=2;
            if(t==0)k=-1;
            for(i=0; i<n; i++)
            {
                for(j=0; j<m; j++)
                {
                    //if(a[i][j]==1)cout<<"*";
                    if(a[i][j]==0&&k!=-1){cout<<"*";k++;if(k==t)k=-1;continue;}
                    if(k==t)k=-1;
                    if(k==-1&&a[i][j]!=2)cout<<".";
                    if(a[i][j]==2)cout<<"c";
                }
                cout<<endl;
            }
            continue;
        }
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                a[i][j]=0;
        k=0;
        if(t>n*m-4){cout<<"Case #"<<mt<<":"<<endl<<"Impossible"<<endl; continue;}
        a[n-2][m-2]=-1;
        a[n-2][m-1]=-1;
        a[n-1][m-2]=-1;
        a[n-1][m-1]=2;
        cout<<"Case #"<<mt<<":"<<endl;
        if(t==0)k=-1;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(a[i][j]==0&&k!=-1){cout<<"*";k++;if(k==t)k=-1;continue;}
               // if(k==t)k=-1;
                if(a[i][j]==-1||(a[i][j]==0&&k==-1))cout<<".";
                if(a[i][j]==2)cout<<"c";
            }
            cout<<endl;
        }
    }
}
