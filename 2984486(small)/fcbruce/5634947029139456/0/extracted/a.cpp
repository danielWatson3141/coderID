#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

LL ol[222];
LL de[222];
char s[55];
int n,l;

LL bit[50];

void init()
{
    bit[1]=1;
    for (int i=2;i<55;i++)
        bit[i]=bit[i-1]<<1;
}

bool check()
{
    bool f=true;
    for (int i=0;i<n && f;i++)
        if (ol[i]!=de[i])   f=false;
    return f;
}

int dfs(int b,int t)
{
    if (check())    return t;
    if (b>l)    return INF;
    for (int i=0;i<n;i++)
    {
        ol[i]^=bit[b];
    }
    sort(ol,ol+n);

    int t1=dfs(b+1,t+1);

    for (int i=0;i<n;i++)
    {
        ol[i]^=bit[b];
    }
    sort(ol,ol+n);
    int t2=dfs(b+1,t);

    return min(t1,t2);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
		freopen("t1","w",stdout);
	#endif

	init();

	int tt;
	scanf("%d",&tt);

	for (int t=1;t<=tt;t++)
    {
        scanf("%d%d",&n,&l);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            ol[i]=0;
            for (int j=0;j<l;j++)
            {
                ol[i]<<=1;
                if (s[j]=='1')
                {
                    ol[i]|=1;
                }
            }
        }
        for (int i=0;i<n;i++)
        {
            scanf("%s",s);
            de[i]=0;
            for (int j=0;j<l;j++)
            {
                de[i]<<=1;
                if (s[j]=='1')
                {
                    de[i]|=1;
                }
            }
        }
        sort(ol,ol+n);
        sort(de,de+n);
        int cnt=dfs(1,0);


        if (cnt==INF)
            printf("Case #%d: NOT POSSIBLE\n",t);
        else
            printf("Case #%d: %d\n",t,cnt);
    }

	return 0;
}
