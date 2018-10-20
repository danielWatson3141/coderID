#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int s[200];
int t[200];
int trans[200];
char str1[200][50];
char str2[200][50];
int get(char str[50])
{
    int l=strlen(str);
    int ret = 0;
    for(int i=0;i<l;i++){
        if(str[i] == '1') ret += 1;
        ret<<=1;
    }
    return ret;
}

int ones(int a)
{
    int ret = 0;
    while(a)
    {
        if(a&1) ret+=1;
        a>>=1;
    }
    return ret;
}

int main()
{
    int T;
    int out=1;
    int n,l;
    //freopen("c:\\codejam\\A-small-attempt0.in","r",stdin);
    //freopen("c:\\codejam\\A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        int ans = 100;
        memset(s,0,sizeof(s));
        memset(t,0,sizeof(t));
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        scanf("%d %d",&n,&l);
        for(int i=0;i<n;i++)
            scanf("%s",str1[i]);
        for(int i=0;i<n;i++)
            scanf("%s",str2[i]);
        for(int i=0;i<n;i++)
            s[i] = get(str1[i]);
        for(int i=0;i<n;i++)
            t[i] = get(str2[i]);
        sort(t,t+n);
        for(int i=0;i<(1<<l);i++)
        {
            for(int j=0;j<n;j++)
                trans[j] = s[j]^i;
            sort(trans,trans+n);
            bool ok = true;
            for(int j=0;j<n;j++)
                if(trans[j] != t[j]) ok = false;
            if(ok)
                ans = min(ans,ones(i));
        }
        printf("Case #%d: ",out++);
        if(ans == 100)
            puts("NOT POSSIBLE");
        else
            printf("%d\n",ans);
    }
    return 0;
}
