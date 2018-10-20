#include <stdio.h>
#include <vector>
#include<algorithm>
using namespace std;
int t,n,l;
struct node {
	char str[41];
	bool operator < (const  node &o) const { for(int i=0;i<l;i++) if(str[i]!=o.str[i]) return str[i]<o.str[i]; return  1;}
}a[155],b[155],c[155],d[155];

int main(int argc, char *argv[])
{
	scanf("%d",&t);
	for(int rr=1;rr<=t;rr++)
	{
		scanf("%d %d",&n,&l);
		for(int i=0;i<n;i++)
		{
			scanf("%s",a[i].str);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",c[i].str);
		}
		int ans = l+1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				b[j]=a[j];
				d[j]=c[j];
			}
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<l;k++)
				{
					b[j].str[k]^=a[i].str[k];
					d[j].str[k]^=c[0].str[k];
				}
			}
			sort(&b[0],&b[n]);
			sort(&d[0],&d[n]);
			bool mark=0;
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<l;k++)
				{
					if(b[j].str[k]!=d[j].str[k])
					{
						mark=1;
					}
				}
			}
			if(!mark)
			{
				int nub=0;
				for(int k=0;k<l;k++)
				{
					if(a[i].str[k]!=c[0].str[k])
					{
						nub++;
					}
				}
				ans=min(ans,nub);
			}
		}
		printf("Case #%d: ",rr);
		if(ans!=l+1)
		printf("%d\n",ans);
		else
		printf("NOT POSSIBLE\n");
	}	
	return 0;
}
