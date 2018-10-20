#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
#define DEBUG
string tmpstring;
struct node{
    char s[41];
    bool operator < (const node &a )const{
        int len = strlen(s);
        for(int i=0;i<len;i++)
            if(s[i]!=a.s[i]) return s[i]<a.s[i];
        return true;
    }
}bx[150],cx[150];
int cmp1(const void *a,const void *b)
{
    node *aa= (node*)a;
    node *bb= (node*)b;
    int len = strlen(aa->s);
    for(int i=0;i<len;i++)
        if(aa->s[i]!=bb->s[i])
            return aa->s[i]>bb->s[i];
    return 1;
}
int cmp2(const void *a,const void *b)
{
    node *aa= (node*)a;
    node *bb= (node*)b;
    int len = strlen(aa->s);
    for(int i=0;i<len;i++)
        if(aa->s[i]!=bb->s[i])
            return aa->s[i]<bb->s[i];
    return 1;
}
set<string> s;
bool ext[1010];
int main()
{
#ifdef DEBUG
freopen("A-large.in","r",stdin);
freopen("A-large.out","w",stdout);
#endif
    int casecnt=1,t,ans,tmpans;
    int n,l;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case #%d: ",casecnt++);
        ans = 200;
        s.clear();
        scanf("%d %d",&n,&l);
        for(int i=0;i<n;i++)
            scanf("%s",bx[i].s);
        for(int i=0;i<n;i++)
        {
            scanf("%s",cx[i].s);
            s.insert(cx[i].s);
        }
        for(int i=0;i<n;i++)
        {
            tmpans = 0;
            for(int j=0;j<l;j++)
                if(bx[i].s[j]!=cx[0].s[j])
                {
                    ext[j]=true;
                    tmpans++;
                }
                else
                {
                    ext[j]=false;
                }
            bool check =true;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    char s0[1010];
                    for(int k=0;k<l;k++)
                    {
                        if( ext[k] ) s0[k] = 1-( bx[j].s[k] - '0' )+'0';
                        else s0[k] = bx[j].s[k];
                    }
                    s0[l]='\0';
                    tmpstring = s0;
                    if(s.find(tmpstring)==s.end())
                    {
                        check=false;
                        break;
                    }
                }
            }
            if(check) ans = min( ans , tmpans );
        }
        if(ans == 200)
            printf("NOT POSSIBLE\n");
        else printf("%d\n",ans);
    }

    return 0;
}
