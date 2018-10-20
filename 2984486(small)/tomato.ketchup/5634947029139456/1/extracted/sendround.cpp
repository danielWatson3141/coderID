#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
int n,l;
int check(int shi[40],int x,char sw[150][40],char de[150][40])
{
	char s[150][40],d[150][40];
	for(int i=0;i<n;i++)
	{
		strcpy(s[i],sw[i]);
		strcpy(d[i],de[i]);	
	}
	for(int i=0;i<x;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[j][shi[i]]=='0')
			{
				s[j][shi[i]]='1';
			}
			else if(s[j][shi[i]]=='1')
			{
				s[j][shi[i]]='0';
			}
		}
	}
	int *check,te,ch=0;
	check=(int*)calloc(n,sizeof(int));
	/*for(int i=0;i<n;i++)
	{
		printf("%s %s\n",s[i],d[i]);	
	}*/
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
				te=strcmp(d[i],s[j]);
				/*printf("te at i=%d j=%d:%d\n",i,j,te);*/
				if(te==0&&check[j]!=1)
				{
					check[j]=1;
					ch++;
					j=n+1;
				}
			
		}
	}
	/*printf("ch=%d\n",ch);*/
	if(ch==n)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int t;
	FILE *p,*w;
	w=fopen("C:\\Users\\Shikhar\\Desktop\\A-large.in","r");
	p=fopen("C:\\Users\\Shikhar\\Desktop\\out.in","w");
	char sw[150][40],de[150][40];	
	fscanf(w,"%d\n",&t);
	for(int x=1;x<=t;x++)
	{
		fscanf(w,"%d %d\n",&n,&l);
		for(int i=0;i<n;i++)
		{
			fscanf(w,"%s",sw[i]);
		}
		fscanf(w,"\n");
		for(int i=0;i<n;i++)
		{
			fscanf(w,"%s",de[i]);
		}
		fscanf(w,"\n");
		int y=41;
		for(int i=0;i<n;i++)
		{
			int z=0,shi[40];
			for(int j=0;j<l;j++)
			{
				if(sw[i][j]!=de[0][j])
				{
					shi[z]=j;
					z++;
				}
				
			}
		/*	printf("z=%d\n",z);*/
	
			if(z<y)
				{
					
					if(check(shi,z,sw,de)==1)
					{
						y=z;
					}
				}
		}
		if(y==41)
		{
			printf("Case #%d: NOT POSSIBLE\n",x);
			fprintf(p,"Case #%d: NOT POSSIBLE\n",x);
		}
		else
		{
			printf("Case #%d: %d\n",x,y);
			fprintf(p,"Case #%d: %d\n",x,y);
		}
		
	}
}