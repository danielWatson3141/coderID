#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int i,j,k,n,l,m,t,flag,ans,x,cnt,sco;
	string s;
	vector<string> a,b,c;
	int sig[100];
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		a.clear();
		b.clear();
		c.clear();
		flag=0;ans=100;
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++)
		{
			cin >> s;
			a.push_back(s);
		}
		for(i=0;i<n;i++)
		{
			cin >> s;
			b.push_back(s);
		}
		sort(b.begin(),b.end());
		for(i=0;i<l;i++)	sig[i]=-1;
		for(i=0;i<(1<<l);i++)
		{
			x=i;
			c=a;
			cnt=0;
			sco=0;
			while(x)
			{
				if(x&1)
				{
					for(j=0;j<n;j++)
					{
						if(c[j][cnt]=='1')	c[j][cnt]='0';
						else c[j][cnt]='1';
					}
					sco++;
				}
				cnt++;
				x=x>>1;
			}
			flag=0;
			sort(c.begin(),c.end());
			for(j=0;j<n;j++)
			{
				if(c[j]!=b[j])
				{
					flag=1;
					break;
				}
			}
			if(!flag) ans=min(ans,sco);
		}
		if(ans==100) printf("Case #%d: NOT POSSIBLE\n",k);
		else	printf("Case #%d: %d\n",k,ans);
	}
	return 0;
}
