#include <stdio.h>

int con[4010] ,l[4010];
int st[1010];
void f(int p ,int g);
int yn[1010];
int que[1010][1010];
int r1s[1010][1010];
int r2s[1010][1010];
int r1 ,r2;
int ans;
int main(void)
{
	int t ,i;
	int n ,j;
	int p;
	int a ,b;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf("%d" ,&n);
		for (j=1 ; j<=n ; j++)
		{
			st[j]=j;	
		}
		p=n;
		for (j=1 ; j<n ; j++)
		{
			scanf("%d %d" ,&a ,&b);
			l[st[a]]=++p;
			st[a]=p;
			con[p]=b;
			l[st[b]]=++p;
			st[b]=p;
			con[p]=a;			
		}
		for (j=1 ; j<=n ; j++)
		{
			l[st[j]]=0;	
			yn[j]=1;
		}
		yn[1]=0;
		ans=1;
		f(1,1);
		printf("Case #%d: %d\n" ,i ,n-ans);
	}

	return 0;
}

void f(int p ,int g)
{
	int ppp;
	int n ,i;
	int m1 ,m2;
	int l1 ,l2 ,l3;
	int temp ,temp2;
	
	yn[p]=0;
	ppp=p;
	n=0;
	while (l[ppp])
	{
		ppp=l[ppp];
		if (yn[con[ppp]])
		{
			que[g][++n]=con[ppp];
		}
	}
	if (n==0)
	{
		r1=1;
		r2=0;
	}
	else
	{
		for (i=1 ; i<=n ; i++)
		{
			f(que[g][i],g+1);
			r1s[g][i]=r1;
			r2s[g][i]=r2;
		}		
		if (n>=3)
		{
			temp=1;
			m1=0;
			m2=0;
			for (i=1 ; i<=n ; i++)
			{
				if (r1s[g][i]>m1)
				{
					m2=m1;
					m1=r1s[g][i];	
				}
				else if (r1s[g][i]>m2)
				{
					m2=r1s[g][i];	
				}
			}			
			temp+=m1+m2;
			if (temp>ans)
			{
				ans=temp;	
			}
			r1=temp;
			
			l1=0;
			l2=0;
			l3=0;
			r2s[g][0]=0;
			for (i=1 ; i<=n ; i++)
			{
				if (r2s[g][i]>r2s[g][l1])
				{
					l3=l2;
					l2=l1;
					l1=i;
				}
				else if (r2s[g][i]>r2s[g][l2])
				{
					l3=l2;
					l2=i;
				}
				else if (r2s[g][i]>r2s[g][l3])
				{
					l3=i;
				}				
			}
//////////////////////////////////////						
			temp=1;
			m1=0;
			m2=0;
			for (i=1 ; i<=n ; i++)
			{
				if (i!=l1)
				{
					if (r1s[g][i]>m1)
					{
						m2=m1;
						m1=r1s[g][i];	
					}
					else if (r1s[g][i]>m2)
					{
						m2=r1s[g][i];	
					}
				}
			}			
			temp+=m1+m2+r2s[g][l1];
			if (temp>ans)
			{
				ans=temp;	
			}			
//////////////////////////////////////			
			temp=1;
			m1=0;
			m2=0;
			for (i=1 ; i<=n ; i++)
			{
				if (i!=l2)
				{
					if (r1s[g][i]>m1)
					{
						m2=m1;
						m1=r1s[g][i];	
					}
					else if (r1s[g][i]>m2)
					{
						m2=r1s[g][i];	
					}
				}
			}			
			temp+=m1+m2+r2s[g][l2];
			if (temp>ans)
			{
				ans=temp;	
			}
//////////////////////////////////////					
			temp=1;
			m1=0;
			m2=0;
			for (i=1 ; i<=n ; i++)
			{
				if (i!=l3)
				{
					if (r1s[g][i]>m1)
					{
						m2=m1;
						m1=r1s[g][i];	
					}
					else if (r1s[g][i]>m2)
					{
						m2=r1s[g][i];	
					}
				}
			}			
			temp+=m1+m2+r2s[g][l3];
			if (temp>ans)
			{
				ans=temp;	
			}
//////////////////////////////////////			
			m1=0;
			m2=0;
			r1s[g][0]=0;
			for (i=1 ; i<=n ; i++)
			{
				if (r1s[g][i]>r1s[g][m1])
				{
					m2=m1;
					m1=i;	
				}
				else if (r1s[g][i]>r1s[g][m2])
				{
					m2=i;	
				}
			}
			if (m1!=l1)
			{
				r2=1+r1s[g][m1]+r2s[g][l1];
			}
			else
			{
				temp=1+r1s[g][m1]+r2s[g][l2];
				temp2=1+r1s[g][m2]+r2s[g][l1];
				if (temp2>temp)
				{
					temp=temp2;
				}
				r2=temp;
			}			
		}
		else if (n==2)
		{
			temp=1;
			m1=0;
			m2=0;
			for (i=1 ; i<=n ; i++)
			{
				if (r1s[g][i]>m1)
				{
					m2=m1;
					m1=r1s[g][i];	
				}
				else if (r1s[g][i]>m2)
				{
					m2=r1s[g][i];	
				}
			}			
			temp+=m1+m2;
			if (temp>ans)
			{
				ans=temp;	
			}
			r1=temp;
			temp=r2s[g][1]+1;
			if (temp>ans)
			{
				ans=temp;	
			}
			temp=r2s[g][2]+1;
			if (temp>ans)
			{
				ans=temp;	
			}			
			temp=1+r1s[g][1]+r2s[g][2];
			temp2=1+r1s[g][2]+r2s[g][1];
			if (temp2>temp)
			{
				temp=temp2;
			}				
			r2=temp;		
		}
		else
		{
			temp=r2s[g][1]+1;
			if (temp>ans)
			{
				ans=temp;	
			}
			r1=1;
			r2=r1s[g][1]+1;
		}
	}
}
