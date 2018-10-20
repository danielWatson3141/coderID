#include<cstdio>
#include<bitset>
#include<algorithm>

using namespace std;

const int inf=1e9;

int t,n,l;
long long a[160],c[160];
int aa[160][50],bb[160][50];
char str[50];
bitset<160> v;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	scanf("%d",&t);
	
	for(int t1=1;t1<=t;t1++)
	{
		scanf("%d%d",&n,&l);
		
		int ans=inf;
		
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&str);
			long long temp=0;
			for(int j=1;j<=l;j++)
			{
				temp<<=1;
				aa[i][j]=(int)(str[j-1]-'0');
				temp|=aa[i][j];
			}
			a[i]=temp;
		}
		
		sort(a+1,a+n+1);
		
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&str);
			for(int j=1;j<=l;j++)
				bb[i][j]=(int)(str[j-1]-'0');
		}
		
		for(int i=1;i<=n;i++)
		{
			v.reset();
			
			for(int j=1;j<=n;j++)
				c[j]=0;
			
			for(int j=1;j<=l;j++)
				if(aa[1][j]!=bb[i][j])
					v.set(j);
			
			if(v.count()>ans)continue;
			
			for(int k=1;k<=n;k++)
				for(int j=1;j<=l;j++)
				{
					c[k]<<=1;
					c[k]|=(bb[k][j]^v[j]);
				}
			
			sort(c+1,c+n+1);
			
			bool flag=true;
			for(int j=1;j<=n;j++)
				if(a[j]!=c[j])
				{
					flag=false;
					break;
				}
			
			if(flag)ans=v.count();
		}
		
		printf("Case #%d: ",t1);
		
		if(ans!=inf)
			printf("%d\n",ans);
		else
			printf("NOT POSSIBLE\n");
	}
	
	return 0;
}
