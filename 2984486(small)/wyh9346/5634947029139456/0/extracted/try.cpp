#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long a[200],b[200],c[200];
int cal(long long dt)
{
    int res=0;
    while (dt)
    {
        res+=dt&1;
        dt/=2;
    }
    return res;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tk,tk1=0,i,j,n,l;
    char x[100];
    scanf("%d",&tk);
    while (tk--)
    {
        tk1++;
        int ans=1000;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%d %d",&n,&l);
        for (i=0;i<n;i++)
        {
            scanf("%s",x);
            for (j=0;j<l;j++)
                a[i]=a[i]*2+(long long)(x[j]-'0');
        }
        for (i=0;i<n;i++)
        {
            scanf("%s",x);
            for (j=0;j<l;j++)
                b[i]=b[i]*2+(long long)(x[j]-'0');
        }
		sort(a,a+n);
		sort(b,b+n);
		for (i=0;i<n;i++)
			if (a[i]!=b[i])
				break;
		if (i==n)
			ans=0;

        for (i=0;i<n;i++)
        {
            long long dt=a[0]^b[i];
            for (j=0;j<n;j++)
                c[j]=a[j]^dt;
            sort(c,c+n);
            for (j=0;j<n;j++)
                if(b[j]!=c[j])
                    break;
            if (j==n)
            {
                ans=min(ans,cal(dt));
            }
        }
        if (ans>100)
        {
            printf("Case #%d: NOT POSSIBLE\n",tk1);
            continue;
        }
        printf("Case #%d: %d\n",tk1,ans);
    }
    return 0;
}
