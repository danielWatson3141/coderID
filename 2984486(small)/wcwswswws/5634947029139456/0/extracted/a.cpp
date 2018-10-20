#include<stdio.h>
#include<algorithm>
#include<string.h>
struct str
{
    char s[50];
    bool operator<(str b) const
    {
        int l=strlen(s);
        for (int i=0;i<l;i++)
        {
            if (s[i]<b.s[i]) return true;
            if (s[i]>b.s[i]) return false;
        }
        return false;
    }
    bool operator==(str b) const
    {
        int l=strlen(s);
        for (int i=0;i<l;i++) if (s[i]!=b.s[i]) return false;
        return true;
    }
    str operator=(str b)
    {
        int l=strlen(s);
        for (int i=0;i<l;i++) this->s[i]=b.s[i];
    }
} s[150],st[150];

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int n,l;
        scanf("%d%d",&n,&l);
        for (int i=0;i<n;i++) scanf("%s",s[i].s);
        for (int i=0;i<n;i++) scanf("%s",st[i].s);
        std::sort(s,s+n);
        std::sort(st,st+n);
        int a[50];
        int ans=1e9;
        for (int i=0;i<n;i++)
        {
            a[0]=0;
            bool used[150];
            memset(used,false,sizeof(used));
            used[i]=true;
            bool check=true;
            for (int j=0;j<l;j++) if (s[0].s[j]!=st[i].s[j]) a[++a[0]]=j;
            for (int j=1;j<n;j++)
            {
                str temp=s[j];
                check=false;
                for (int k=1;k<=a[0];k++) temp.s[a[k]]=((temp.s[a[k]]-'0')^1)+'0';
                for (int k=0;k<n;k++)
                if ((!used[k])&&(temp==st[k]))
                {
                    used[k]=true;
                    check=true;
                    break;
                }
                if (!check) break;
            }
            if (check) ans=(ans<a[0]?ans:a[0]);
        }
        printf("Case #%d: ",t);
        if (ans<1e9) printf("%d\n",ans); else printf("NOT POSSIBLE\n");
    }
    return 0;
}
