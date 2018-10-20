#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define  inf 0x0f0f0f0f

using namespace std;

const double pi=acos(-1.0);
const double eps=1e-8;
typedef pair<int,int>pii;

char str1[151][50],str2[151][50];


int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,L,t,sum,mmax,a[151];
    bool flag;
    scanf("%d",&t);
    for (int k=1;k<=t;k++)
    {
        printf("Case #%d: ",k);
        sum=0;
        mmax=999999999;
        flag=true;
        scanf("%d%d",&n,&L);
        for (int i=0;i<n;i++) scanf("%s",str1[i]);
        for (int i=0;i<n;i++) scanf("%s",str2[i]);
        for (int i=0;i<n;i++) a[i]=i;
        for (int i=0;i<L;i++)
        {
            bool f=false;
            for (int j=0;j<n;j++)
            {
                if (str1[a[j]][i]!=str2[j][i])
                f=true;
            }
            if (f)
            {
                for (int l=0;l<n;l++)
                {
                    if (str1[a[l]][i]=='0')
                    {
                        if (str2[l][i]!='1') {flag=false;break;}
                    }
                    if (str1[a[l]][i]=='1')
                    {
                        if (str2[l][i]!='0') {flag=false;break;}
                    }
                }
            }
            if (!flag) break;
            if (flag && f) sum++;
        }
        if(flag)mmax=min(mmax,sum);
        while (next_permutation(a,a+n))
        {
            sum=0;
            flag=true;
            for (int i=0;i<L;i++)
            {
                bool f=false;
                for (int j=0;j<n;j++)
                {
                    if (str1[a[j]][i]!=str2[j][i])
                    {f=true;break;}
                }
                if (f)
                {
                    for (int l=0;l<n;l++)
                    {
                        if (str1[a[l]][i]=='0')
                        {
                            if (str2[l][i]!='1') {flag=false;break;}
                        }
                        if (str1[a[l]][i]=='1')
                        {
                            if (str2[l][i]!='0') {flag=false;break;}
                        }
                    }

                }
                if (!flag) break;
                if (flag && f) sum++;
            }
            if(flag) mmax=min(sum,mmax);
        }
        if (mmax<152) printf("%d\n",mmax);
        else printf("NOT POSSIBLE\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
