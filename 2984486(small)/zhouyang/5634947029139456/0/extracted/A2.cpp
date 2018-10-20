#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include<map>
#define maxn 200
using namespace std;
int n,l;
int t;
string str[maxn],str2[maxn];
string a[maxn];
bool cmp(string a,string b)
{
    return a.compare(b)<0;
}
int flap[maxn];
int num[maxn][3],num2[maxn][3];
int main ()
{
    //freopen("A-small-attempt1.in","r",stdin);
    //freopen("A-small-attempt1.out","w",stdout);
    char ch[10];
    while(scanf("%d",&t)!=EOF)
    {
        for(int Case=1; Case<=t; ++Case)
        {
            scanf("%d%d",&n,&l);
            gets(ch);
            for(int i=0; i<n; ++i)
            {
                cin>>str[i];
            }
            for(int i=0; i<n; ++i)
            {
                cin>>str2[i];
            }
            sort(str,str+n,cmp);
            sort(str2,str2+n,cmp);
            int flag=1;
            for(int i=0; i<n; ++i)
            {
                if(str[i].compare(str2[i])!=0)
                {
                    flag=0;
                    break;
                }
            }
            printf("Case #%d: ",Case);
            if(flag)
            {
                printf("0\n");
                continue;
            }
            flag=0;
            int ans=100000;
            //cout<<endl;
            for(int i=0; i<=(1<<l); ++i)
            {
                for(int j=0;j<n;++j)a[j]=str[j];
                int temp=0;
                for(int j=0; j<l; ++j)
                {
                    if(i&(1<<j))
                    {
                        temp++;
                        for(int k=0; k<n; ++k)
                        {
                            if(a[k][j]=='0')a[k][j]='1';
                            else a[k][j]='0';
                        }
                    }
                }
                sort(a,a+n,cmp);
                flag=1;
                for(int k=0; k<n; ++k)
                {
                    if(a[k].compare(str2[k])!=0)
                    {
                        flag=0;
                        break;
                    }
                }
                //for(int i=0;i<n;++i)cout<<a[i]<<endl;
                if(flag){
                    ans=min(ans,temp);
                }
            }
            if(ans==100000)printf("NOT POSSIBLE\n");
            else printf("%d\n",ans);
        }
    }
}
