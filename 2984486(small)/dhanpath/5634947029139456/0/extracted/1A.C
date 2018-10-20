#include <stdio.h>
#include<string.h>

int tt,t,n,l,i,j,k,r,z,x,v,pv;
char a[160][50],b[160][50],c[160][50];
char temp[60];

int rec()
{
	int ii,jj;
	for(ii=1;ii<=n;ii++)
	{
		for(jj=0;jj<n-1;jj++)
		{
			if(strcmp(c[jj],c[jj+1])>0)
			{
				strcpy(temp,c[jj]);
				strcpy(c[jj],c[jj+1]);
				strcpy(c[jj+1],temp);
			}
		}
	}	
	x=0;
	for(z=0;z<n;z++) if(strcmp(a[z],c[z])==0) x++;
	if(x==n) return 1;
	return 0;
}

int main()
{
	scanf("%d",&tt);
	for(t=1;t<=tt;t++)
	{
		pv=99999;
		scanf("%d%d",&n,&l);
		for(i=0;i<n;i++)
			scanf("%s",a[i]);
		for(i=1;i<=n;i++)
		{
			for(j=0;j<n-1;j++)
			{
				if(strcmp(a[j],a[j+1])>0)
				{
					strcpy(temp,a[j]);
					strcpy(a[j],a[j+1]);
					strcpy(a[j+1],temp);
				}
			}
		}
		for(i=0;i<n;i++)
			scanf("%s",b[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				v=0;
				for(k=0;k<l;k++)
				{
					if(a[i][k]==b[j][k]) for(r=0;r<n;r++)c[r][k]=b[r][k];
					else
					{
						v++;
						for(r=0;r<n;r++)
						if(b[r][k]=='1')c[r][k]='0';
						else c[r][k]='1';
					}
				}
				for(z=0;z<n;z++)c[z][l]='\0';
				if(rec())
					if(pv>v) pv=v;
			}
		}
		if(pv==99999) printf("Case #%d: NOT POSSIBLE\n",t);
		else printf("Case #%d: %d\n",t,pv);
	}
	return 0;
}
