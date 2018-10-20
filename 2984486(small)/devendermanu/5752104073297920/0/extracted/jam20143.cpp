#include<stdio.h>
int main()
{ int t,n,arr[1001],i,x,eq;
scanf("%d",&t);
for(x=1;x<=t;x++)
{ scanf("%d",&n);
eq=0;
for(i=0;i<n;i++)
{ scanf("%d",&arr[i]);
if(arr[i]==i) eq++;
}
printf("case #%d: ",x);
printf(eq>1?"BAD\n":"GOOD\n");
}
return 0;
}
