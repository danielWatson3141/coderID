#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define DEBUG
char s[1000];
struct node{
    char s[41];
    bool operator < (const node &a )const{
        int len = strlen(s);
        for(int i=0;i<len;i++)
            if(s[i]!=a.s[i]) return s[i]<a.s[i];
        return true;
    }
}bx[150],cx[150],dx[150];
int main()
{
#ifdef DEBUG
freopen("A-small-attempt3.in","r",stdin);
freopen("A-small-attempt3.out","w",stdout);
#endif
    int casecnt=1,t,n,l;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        int ans =200,num;
        scanf("%d %d",&n,&l);
        num=1<<l;
        for(int i=0;i<n;i++)
            scanf("%s",bx[i].s);
        for(int i=0;i<n;i++)
            scanf("%s",cx[i].s);
        sort(cx,cx+n);
        bool check;
        for(int i=0;i<num;i++)
        {
            check= true;
            int cnt=0,tmp=i;
            for(int j=0;j<n;j++)
                dx[j]=bx[j];
            int dit=0;
            while(tmp)
            {
                if(tmp&1)
                {
                    cnt++;
                    for(int j=0;j<n;j++)
                        dx[j].s[dit] = 1-(dx[j].s[dit]-'0')+'0';
                }
                tmp>>=1;
                dit++;
            }
            sort(dx,dx+n);
            for(int j=0;j<n;j++)
                for(int k=0;k<l;k++)
                    if(dx[j].s[k]!=cx[j].s[k])
                        check = false;
            if(check)ans = min( ans , cnt );
        }
        if(ans==200) printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);

    }

    return 0;
}
