#include <stdio.h>

int a[200] ,b[200] ,aa[200];
int tempa[200];
void mergesort(int *a ,int n1 ,int n2);
int main(void)
{
	int t ,i ,j ,j2 ,jj ,jjj;
	int n ,l;
	char s[50];
	int ta;
	int p;
	int z;
	int temp;
	int ans;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf("%d %d" ,&n, &l);
		for (j=1 ; j<=n ; j++)
		{
			scanf("%s" ,s);
			ta=0;
			p=1;
			for (j2=0 ; j2<l ; j2++)
			{
				if (s[j2]=='1')
				{
					ta+=p;	
				}
				p<<=1;
			}
			a[j]=ta;
		}
		for (j=1 ; j<=n ; j++)
		{
			scanf("%s" ,s);
			ta=0;
			p=1;
			for (j2=0 ; j2<l ; j2++)
			{
				if (s[j2]=='1')
				{
					ta+=p;	
				}
				p<<=1;
			}			
			b[j]=ta;
		}	
		ans=10000;
		jj=1<<l;
		for (j2=0 ; j2<jj ; j2++)
		{
			for (j=1 ; j<=n ; j++)
			{
				aa[j]=a[j]^j2;
			}
			mergesort(aa,1,n);
			mergesort(b,1,n);
			z=1;
			for (j=1 ; j<=n ; j++)
			{
				if (aa[j]!=b[j])
				{
					z=0;
					break;	
				}
			}
			if (z)
			{
				jjj=j2;
				temp=0;
				while (jjj)
				{
					if (jjj&1)
					{
						temp++;
					}	
					jjj>>=1;
				}
				if (temp<ans)
				{
					ans=temp;	
				}
			}			
		}
		if (ans==10000)
		{
			printf("Case #%d: NOT POSSIBLE\n" ,i);
		}
		else
		{
			printf("Case #%d: %d\n" ,i ,ans);
		}
	}

	return 0;
}

void mergesort(int *a ,int n1 ,int n2)
{
	int a1 ,a2 ,n12;
	int i ,j;
	
	if (n1<n2)
	{	
		n12=(n1+n2)/2;
		mergesort(a,n1,n12);
		mergesort(a,n12+1,n2);
		for (i=n1 ; i<=n2 ; i++)
		{
			tempa[i]=a[i];	
		}
		a1=n1;
		a2=n12+1;
		for (i=n1 ; (a1<=n12 && a2<=n2) ;i++)
		{
			if (tempa[a1]<=tempa[a2])
			{
				a[i]=tempa[a1];
				a1++;
			}
			else
			{
				a[i]=tempa[a2];
				a2++;				
			}
		}
		if (a1>n12)
		{
			for (j=a2 ; j<=n2 ; j++ , i++)
			{
				a[i]=tempa[j];
			}
		}
		else
		{
			for (j=a1 ; j<=n12 ; j++ , i++)
			{
				a[i]=tempa[j];
			}			
		}
	}
}
