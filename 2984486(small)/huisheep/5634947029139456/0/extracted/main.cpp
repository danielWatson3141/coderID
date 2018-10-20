#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long cnt[200];
int n,l,state[50],f[200];
char s1[200][50],s2[200][50];
int change(int t,int k)
{
    long long num=0;
    for(int i=0;i<l;i++)
    {
        num=num*2;
        int ch=s1[t][i]-48;
        if(state[i]==k)
            ch=1-ch;
        num+=ch;
    }
    int left=0,right=n;
    while(left+1<right)
    {
        int mid=(left+right)/2;
        if(cnt[mid]>num)
            right=mid;
        else
            left=mid;
    }
    if(cnt[left]==num)
        return left;
    else
        return -1;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int tt,ii,i,j;
    scanf("%d",&tt);
    for(ii=1;ii<=tt;ii++)
    {
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            scanf("%s",s1[i]);
        for(i=0;i<n;i++)
        {
            scanf("%s",s2[i]);
            cnt[i]=0;
            for(j=0;j<l;j++)
                cnt[i]=cnt[i]*2+s2[i][j]-48;
        }
        sort(cnt,cnt+n);
        memset(f,0,sizeof(f));
        memset(state,0,sizeof(f));
        int num,ans=1000000;
        for(j=0;j<n;j++)
        {
            num=0;
            for(i=0;i<l;i++)
                if(s1[0][i]!=s2[j][i])
                {
                    state[i]=j+1;
                    num++;
                }
            int flag=1;
            for(i=0;i<n;i++)
            {
                int now=change(i,j+1);
                if(now==-1||f[now]==j+1)
                {
                    flag=0; break;
                }
                else
                    f[now]=j+1;
            }
            if(flag) ans=min(ans,num);
        }
        if(ans==1000000)
            printf("Case #%d: NOT POSSIBLE\n",ii);
        else
            printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
