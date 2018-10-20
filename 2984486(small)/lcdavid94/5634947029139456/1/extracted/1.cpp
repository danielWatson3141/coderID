#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[200],b[200],x[200];
int n,l;
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		scanf("%d%d%*c",&n,&l);
		for (int i=0;i<n;++i)
		{
			char c;
			a[i]=0ll;
			for (int j=0;j<l;++j)
			{
				c=getchar();
				a[i]=a[i]*2+int(c=='1');
			}
			c=getchar();
		}
		for (int i=0;i<n;++i)
		{
			char c;
			b[i]=0ll;
			for (int j=0;j<l;++j)
			{
				c=getchar();
				b[i]=b[i]*2+int(c=='1');
			}
			c=getchar();
		}
		sort(a,a+n);
		int ans=-1;
		for (int i=0;i<n;++i)
		{
			ll key=a[0]^b[i];
			for (int j=0;j<n;++j)
				x[j]=b[j]^key;
			sort(x,x+n);
			int cnt=0;
			while (cnt<n&&a[cnt]==x[cnt]) ++cnt;
			if (cnt==n)
				{
					int temp=0;
					for (int k=0;k<l;++k)
					{
						temp+=key%2;
						key/=2;
					}
					if (ans==-1||temp<ans) ans=temp;
				}
		}
		printf("Case #%d: ",TT);
		if (ans==-1) printf("NOT POSSIBLE\n");
		else printf("%d\n",ans);
	}
}
