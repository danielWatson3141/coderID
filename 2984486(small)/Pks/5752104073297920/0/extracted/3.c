#include<stdio.h>
int main()
{
	int n,tc,i,j,v,sum;
	int arr[1000];
	scanf("%d",&tc);
	for(i=1;i<=tc;i++)
	{
	  v=0,sum=0;
	  scanf("%d",&n);
	  for(j=0;j<n;j++)
	  {
		scanf("%d",&arr[j]);
		if(arr[j]-j<0)
		  v+=(j-arr[j]);
		else
		  v+=(arr[j]-j);
	  }
	  for(j=0;n-1-j>=0;j++)
	    sum+=n-1-j;
	  if(v>sum)
	    printf("Case #%d: GOOD\n",i);
	  else
	    printf("Case #%d: BAD\n",i);
	}
	return 0;
}
