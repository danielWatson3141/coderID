#include<stdio.h>

int main()
{
	int t,i,n,l,tt,comb,j,k,tempj,bit,numflips,match;
	scanf("%d",&tt);

	for(t=1;t<=tt;t++)
	{
		scanf("%d%d",&n,&l);

		char present[n][l+1];
		char required[n][l+1];
		char temp[n][l+1];
		int marked[n];

		for(i=0;i<n;i++)
		{
			scanf("%s",present[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%s",required[i]);
		}


		comb=1<<l;
		comb-=1;

		//printf("comb=%d\n",comb);
		for(j=0;j<=comb;j++)
		{

			bit=l-1;
			tempj=j;

			for(i=0;i<n;i++)
			{
				strcpy(temp[i],present[i]);
			}

			numflips=0;match=0;

			while(tempj!=0){

			//traversing through bit pattern of j
			if(tempj&1)//last bit is 1
			{
				numflips++;
				for(i=0;i<n;i++)
				{
					if(temp[i][bit]=='1')temp[i][bit]='0';
					else temp[i][bit]='1';
				}
			}

			tempj>>=1;
			bit--;
			}
			//after all setting is done..
			match=0;
			for(i=0;i<n;i++)marked[i]=0;

			for(i=0;i<n;i++)
			{
				for(k=0;k<n;k++)
				{
					if(strcmp(temp[i],required[k])==0&& !marked[k])
					{
						//printf("match %s %s\n",temp[i],required[k]);
						match++;marked[k]=1;break;
					}
				}
			}

			if(match==n)
			{
				break;
			}
		}

		if(match==n)
		{
			printf("Case #%d: %d\n",t,numflips);
		}
		else
			printf("Case #%d: NOT POSSIBLE\n",t);

	}

	return 0;
}
