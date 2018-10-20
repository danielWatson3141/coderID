#include<iostream>
#include<algorithm>
#include<fstream>
#include<cstdio>
#include<cstring>
using namespace std;
bool u[2000];
string a[2000],b[2000];
int n,l,t,best,c;
bool g,match;
int main()
{
    freopen("alarge.in","r",stdin);
    freopen("alarge.out","w",stdout);
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        cin>>n>>l;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        best=l+1;
        for(int i=1;i<=n;i++) //b[i]->a[1]
        {
            memset(u,0,sizeof(u));
            u[i]=1;
            g=true;
            c=0;
            for(int j=0;j<l;j++)
                if(a[1][j]!=b[i][j])
                    c++;
            for(int j=2;j<=n;j++)
            {
                match=false;
                for(int k=1;k<=n;k++)
                    if(!u[k])
                    {
                        match=true;
                        for(int m=0;m<l;m++)
                            if(a[j][m]==b[k][m]&&a[1][m]!=b[i][m])
                                match=false;
                            else if(a[j][m]!=b[k][m]&&a[1][m]==b[i][m])
                                match=false;
                        if(match)
                        {
                            u[k]=true;
                            break;
                        }
                    }
                if(!match)
                {
                    g=false;
                    break;
                }
            }
            if(g)
                best=min(best,c);
        }
        printf("Case #%d: ",test);
        if(best==l+1)
            cout<<"NOT POSSIBLE"<<endl;
        else
            cout<<best<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
