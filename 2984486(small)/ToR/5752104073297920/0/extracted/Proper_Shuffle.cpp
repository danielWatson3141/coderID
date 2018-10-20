#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<time.h>
using namespace std;
#define INF 1000000000
int a[1005];
int b[1005];
int c[1005];
main()
{
 	freopen("C-small-attempt0.in","r",stdin);
	freopen("xxx.out","w",stdout);
	int t;
	int n;
	srand(time(NULL));
	scanf("%d",&t);
	int tcase_=1;
	while(t--)
	{
		scanf("%d",&n);
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int d=0;
		/*for(i=0;i<n-1;i++)
		{
			for(j=0;j<n;j++)
			{
				if(a[j]==i+1){ d+=abs(j-i); break; }
			}
		}*/
		//int c1=0,c2=0,c3=0;
		double mid=0;
		int N=0;
		for(int C=0;C<1;C++)
		{
			for(i=0;i<n;i++) b[i]=i;
			for(i=0;i<n;i++)
			{
				int r=(rand()%(n-i))+i;
				swap(b[i],b[r]);
			}
			for(i=0;i<n;i++) c[i]=i;
			for(i=0;i<n;i++)
			{
				int r=(rand()%n);
				swap(c[i],c[r]);
			}
			int d1=0,d2=0;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(b[i]>b[j]) d1++;
				}
			}
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(c[i]>c[j]) d2++;
				}
			}
			mid+=(double)(d1+d2)/2;
			N++;
		}
		int d3=0;
		mid/=(double)N;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j]) d3++;
			}
		}
		
		if(d3>mid) printf("Case #%d: GOOD\n",tcase_++);
		else printf("Case #%d: BAD\n",tcase_++);
			
			/*if(d1<d2) c1++;
			else if(d1==d2) c2++;
			else c3++;*/
			/*printf("\n%d\n",d1);
			for(i=0;i<n;i++) printf("%d ",b[i]);
			printf("\n");
			
			printf("%d\n",d2);
			for(i=0;i<n;i++) printf("%d ",c[i]);
			printf("\n");*/
		//}
		//printf("%d %d %d\n",c1,c2,c3);
	}
}

