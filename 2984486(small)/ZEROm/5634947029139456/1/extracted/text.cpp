#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string a[200],b[200],c[200];
int main()
{
    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        for(int i=0;i<n;++i)
            cin>>a[i];
        for(int i=0;i<n;++i)
            cin>>b[i];
        sort(b,b+n);
        int flag=0,ans=l;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
            {
                int ind=0;
                for(int k=0;k<n;++k)
                {
                    string y="";
                    for(int o=0;o<l;++o)
                        if(a[i][o]==b[j][o])y+=a[k][o];
                        else y+=1-(a[k][o]-'0')+'0',++ind;
                    c[k]=y;
                }
                ind/=n;
                sort(c,c+n);
                int u=1;
                for(int k=0;k<n;++k)
                    if(b[k]!=c[k])u=0;
                if(u)flag=1,ans=min(ans,ind);
            }
        printf("Case #%d: ",++Case);
        if(flag)printf("%d\n",ans);
        else printf("NOT POSSIBLE\n");
    }
}
