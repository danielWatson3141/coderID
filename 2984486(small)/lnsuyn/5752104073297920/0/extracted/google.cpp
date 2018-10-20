#include <stdio.h>

double p[1010][1010] ,p2[1010][1010];
double anss[1010];
int c[1010];
int ans2[1010];
double tempa2[1010];
int tempa[1010] ,tempb[1010];
void mergesort(double *a ,int *b ,int n1 ,int n2);
void mergesort2(int *a ,int *b ,int n1 ,int n2);
int main(void)
{
	int t ,i ,j ,ii ,j2;
//	double ans;
	int n;
	int k;
	
	n=1000;
	for (i=0 ; i<n ; i++)
	{
		for (j=0 ; j<n ; j++)
		{
			p[i][j]=0;	
		}	
		p[i][i]=1000;
	}
	for (ii=0 ; ii<n ; ii++)
	{
		for (i=0 ; i<n ; i++)
		{
			if (i==ii)
			{
				for (j=0 ; j<n ; j++)
				{
					p2[i][j]=0;	
				}				
				for (j2=0 ; j2<n ; j2++)
				{
					for (j=0 ; j<n ; j++)
					{
						p2[i][j]+=p[j2][j];	
					}
				}
				for (j=0 ; j<n ; j++)
				{
					p2[i][j]/=n;	
				}								
			}
			else
			{
				for (j=0 ; j<n ; j++)
				{
					p2[i][j]=(p[i][j]*(n-1))/n+p[ii][j]/n;	
				}
			}	
		}
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<n ; j++)
			{
				p[i][j]=p2[i][j];
			}	
		}
	}
/*		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<n ; j++)
			{
				printf("%f " ,p[i][j]);
			}	
			printf("\n");
		}	
	
	scanf(" ");
	
	*/
	
/*	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		ans=0;
		scanf("%d" ,&n);
		for (j=0 ; j<n ; j++)
		{
			scanf("%d" ,&k);
			ans+=p[j][k];	
		}
//		printf("%f  " ,ans);
		if (ans>1000)
		{
			printf("Case #%d: BAD\n" ,i);
		}
		else
		{
			printf("Case #%d: GOOD\n" ,i);
		}
	}*/
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		anss[i]=0;
		scanf("%d" ,&n);
		for (j=0 ; j<n ; j++)
		{
			scanf("%d" ,&k);
			anss[i]+=p[j][k];	
		}
//		printf("%f  " ,ans);
		c[i]=i;
	}
	mergesort(anss,c,1,t);
	for (i=t/2 ; i ; i--)
	{
		ans2[i]=1;	
	}
	for (i=(t/2)+1 ; i<=t ; i++)
	{
		ans2[i]=0;	
	}
	mergesort2(c,ans2,1,t);
	for (i=1 ; i<=t ; i++)
	{
		if (ans2[i]==0)
		{
			printf("Case #%d: BAD\n" ,i);
		}
		else
		{
			printf("Case #%d: GOOD\n" ,i);
		}		
	}
	
	return 0;
}

void mergesort2(int *a ,int *b ,int n1 ,int n2)
{
	int a1 ,a2 ,n12;
	int i ,j;
	
	if (n1<n2)
	{	
		n12=(n1+n2)/2;
		mergesort2(a,b,n1,n12);
		mergesort2(a,b,n12+1,n2);
		for (i=n1 ; i<=n2 ; i++)
		{
			tempa[i]=a[i];	
			tempb[i]=b[i];
		}
		a1=n1;
		a2=n12+1;
		for (i=n1 ; (a1<=n12 && a2<=n2) ;i++)
		{
			if (tempa[a1]<tempa[a2])
			{
				a[i]=tempa[a1];
				b[i]=tempb[a1];
				a1++;
			}
			else
			{
				a[i]=tempa[a2];
				b[i]=tempb[a2];
				a2++;				
			}
		}
		if (a1>n12)
		{
			for (j=a2 ; j<=n2 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}
		}
		else
		{
			for (j=a1 ; j<=n12 ; j++ , i++)
			{
				a[i]=tempa[j];
				b[i]=tempb[j];
			}			
		}
	}
}

void mergesort(double *a ,int *b ,int n1 ,int n2)
{
	int a1 ,a2 ,n12;
	int i ,j;
	
	if (n1<n2)
	{	
		n12=(n1+n2)/2;
		mergesort(a,b,n1,n12);
		mergesort(a,b,n12+1,n2);
		for (i=n1 ; i<=n2 ; i++)
		{
			tempa2[i]=a[i];	
			tempb[i]=b[i];
		}
		a1=n1;
		a2=n12+1;
		for (i=n1 ; (a1<=n12 && a2<=n2) ;i++)
		{
			if (tempa2[a1]<=tempa2[a2])
			{
				a[i]=tempa2[a1];
				b[i]=tempb[a1];
				a1++;
			}
			else
			{
				a[i]=tempa2[a2];
				b[i]=tempb[a2];
				a2++;				
			}
		}
		if (a1>n12)
		{
			for (j=a2 ; j<=n2 ; j++ , i++)
			{
				a[i]=tempa2[j];
				b[i]=tempb[j];
			}
		}
		else
		{
			for (j=a1 ; j<=n12 ; j++ , i++)
			{
				a[i]=tempa2[j];
				b[i]=tempb[j];
			}			
		}
	}
}
