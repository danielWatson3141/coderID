#include<stdlib.h>
#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int x=1;x<=t;x++)
	{
		scanf("%d",&n);
		int *tree;
		tree=(int*)calloc(n,sizeof(int));
		int a,b;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			tree[a-1]+=1;			
			tree[b-1]+=1;
		}
		int y=0;
		
		int flag=0;
		for(int i=0;i<n;i++)
		{
			if(!(tree[i]==1||tree[i]==3))
			{
			y++;
				
			}
				if(tree[i]==2&&flag==0)
				{
				y--;
				flag=1;
				}
		}
		printf("Case #%d: %d\n",x,y);
		
	}
	
}