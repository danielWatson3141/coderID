#include<stdio.h>
#include<math.h>

/*void disp(char A[150][41],int n1,int n2)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		printf("%s",A[i]);
		printf("\n");
	}
}*/

void sort_B(int,int);
void sort_tmpA(int,int);
int cmp(char *,char *);
int match(int);

char A[150][41],B[150][41],tmpA[150][41];
int main()
{
	int T,t=0,n1,n2,i,len,k,j,tmp1,tmp2,flag,flip,tmp3,i2,result,i3,i4,i5;
	scanf("%d",&T);
	while(++t<=T)
	{
		scanf("%d %d",&n1,&n2);
		for(i=0;i<n1;i++)
			scanf("%s",A[i]);
		for(i=0;i<n1;i++)
			scanf("%s",B[i]);
		sort_B(n1,n2);
	//	printf("Sort A and B done\n");
		//disp(B,n1,n2);
		len=(int)pow(2,n2);
		//printf("len = %d\n",len);
		result=50;
		flag=0;
		for(k=0;k<len;k++)
		{
			//printf("k = %d\n",k);
			tmp1=k;
			flip = 0;
			for(i2=0;i2<n1;i2++)
			{
				for(i3=0;i3<=n2;i3++)
				{
					tmpA[i2][i3]=A[i2][i3];
				}
			}
			
			for(j=1;j<len;j=j*2)
			{
				tmp2 = tmp1&j;
				if(tmp2)
				{	
					flip++;
					if(j==1)
						tmp3 = 0;
					else
						tmp3=log(j)/log(2);
				//	printf("tmp3 = %d\n",tmp3);
					//printf("%d %d\n",j,tmp3);
					for(i5=0;i5<n1;i5++)
					{
						if(tmpA[i5][tmp3]=='0')
							tmpA[i5][tmp3]='1';
						else
							tmpA[i5][tmp3]='0';
					}
				}
			}
			sort_tmpA(n1,n2);
			//printf("Sort tmpA done\n");
		//	disp(tmpA,n1,n2);
			i4 = match(n1);
			//printf("match = %d\nflip = %d\n",i4,flip);
			if(i4)
			{
				flag = 1;
				if(result>flip)
					result=flip;
			}
		}
		if(flag)
			printf("Case #%d: %d\n",t,result);
		else
			printf("Case #%d: NOT POSSIBLE\n",t);
	}
	return 0;
}

void sort_B(int k,int k2)
{
	int i,j,l;
	char tmp;
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(cmp(B[i],B[j])==1)
			{
				for(l=0;l<k2;l++)
				{
					tmp=B[i][l];
					B[i][l]=B[j][l];
					B[j][l]=tmp;
				}
			}
		}
	}
}

void sort_tmpA(int k,int k2)
{
	int i,j,l;
	char tmp;
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(cmp(tmpA[i],tmpA[j])==1)
			{
				for(l=0;l<k2;l++)
				{
					tmp=tmpA[i][l];
					tmpA[i][l]=tmpA[j][l];
					tmpA[j][l]=tmp;
				}
			}
		}
	}
}

int cmp(char *t,char *t2)
{
	int i;
	for(i=0;t[i]!='\0';i++)
	{
		if(t[i]>t2[i])
			return 1;
		else if(t[i]<t2[i])
			return -1;
	}
	return 0;
}

int match(int k)
{
	int i;
	for(i=0;i<k;i++)
	{
		if(cmp(tmpA[i],B[i])!=0)
		{
			return 0;
		}
	}
	return 1;
}
