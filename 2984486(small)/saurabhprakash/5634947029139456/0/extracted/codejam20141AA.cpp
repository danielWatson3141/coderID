#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

string a[160],b[160];
int n,l,c;
bool flag;
void rec(int ind)
{
    int i;
    sort(b,b+n);
    for(i=0;i<n;i++)
        if(a[i]!=b[i])
            break;
    if(i==n)
        flag=true;
    if(ind==l)
        return;
    if(!flag)
    {
        rec(ind+1);
        if(!flag)
        {
            for(i=0;i<n;i++)
                b[i][ind]=b[i][ind]=='1'?'0':'1';
            c++;
            rec(ind+1);
            if(!flag)
            {
                c--;
                for(i=0;i<n;i++)
                    b[i][ind]=b[i][ind]=='1'?'0':'1';
            }
        }
    }
}
int main()
{
    int t,cas;
    scanf("%d",&t);
    for(cas=1;cas<=t;cas++)
    {
        int i,j;
        scanf("%d %d",&n,&l);
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
            cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
        flag=false;
        c=0;
        rec(0);
        printf("Case #%d: ",cas);
        if(!flag)
            printf("NOT POSSIBLE\n");
        else
            printf("%d\n",c);
    }

    return 0;
}
