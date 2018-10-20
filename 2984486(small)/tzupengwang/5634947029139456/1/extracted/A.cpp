#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<set>
using namespace std;

int n,l;
struct S
{
    char s[45];
    bool operator < (const S &x)const{
        for (int i=0;i<l;i++)
        {
            if (s[i]<x.s[i])return 1;
            else if (s[i]>x.s[i])return 0;
        }
        return 0;
    }
}a[150],b[150];
bool ch[45];
set<string> stt;

int SOLVE()
{
    stt.clear();
    scanf("%d%d",&n,&l);
    for (int i=0;i<n;i++)scanf("%s",a[i].s);
    for (int i=0;i<n;i++)
    {
        scanf("%s",b[i].s);
        string ss(b[i].s);
        stt.insert(ss);
    }
    int ans=100000000;
    char tmp[45];
    for (int i=0;i<n;i++)
    {
        int ct=0;
        memset(ch,false,sizeof ch);
        for (int j=0;j<l;j++)
        {
            if (a[0].s[j]!=b[i].s[j])ch[j]=true,ct++;
        }
        for (int j=0;j<n;j++)
        {
            for (int k=0;k<l;k++)
            {
                if (ch[k])tmp[k]=(a[j].s[k]=='0')?'1':'0';
                else tmp[k]=(a[j].s[k]=='1')?'1':'0';
            }tmp[l]='\0';
            string ss(tmp);
            if (stt.count(ss)==false){ct=-1;break;}
        }
        //printf("   %d\n",ct);
        if (ct!=-1)ans=min(ans,ct);
    }
    if (ans==100000000)return -1;
    printf("%d\n",ans);
    return ans;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int amm;
    scanf("%d",&amm);
    for (int cnt=1;cnt<=amm;cnt++)
    {
        printf("Case #%d: ",cnt);
        if (SOLVE()==-1)puts("NOT POSSIBLE");
    }
    return 0;
}
/*
1
2 10

0000001110 1101101100

0010010111 1111110101

*/
