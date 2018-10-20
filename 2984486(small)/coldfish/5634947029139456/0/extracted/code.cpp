#include <stdio.h>
#include <istream>

int max=100000,n,l;
char Str[150][40]={0,};
char Crt[150][40]={0,};
void check(int a,int ll,int num)
{
	if(num>=max|| ll==l)
		return;
	int i,j,t,flag=0;
	if(a==1)
	{
		for(i=0;i<n;i++)
		{
			if(Str[i][ll]=='0')
				Str[i][ll]='1';
			else
				Str[i][ll]='0';
		}
	}

	for(i=0;i<n;i++)
	{
		for(t=0;t<n;t++)
		{
			for(j=0;j<l;j++)
			{
				if(Str[i][j]!=Crt[t][j]) break;
			}
			if(j==l) break;
		}
		if(t==n) break;
	}
	if(i==n)
	{
		max=num;
		
		if(a==1)
		{
			for(i=0;i<n;i++)
			{
				if(Str[i][ll]=='0')
					Str[i][ll]='1';
				else
					Str[i][ll]='0';
			}
		}
		return;
	}
	check(1,ll+1,num+1);
	check(0,ll+1,num);

	
	if(a==1)
	{
		for(i=0;i<n;i++)
		{
			if(Str[i][ll]=='0')
				Str[i][ll]='1';
			else
				Str[i][ll]='0';
		}
	}
}
int main()
{
	FILE *fs,*fp;
	fs=fopen("input.in","rt");
	fp=fopen("output.out","wt");

	int m;

	fscanf(fs,"%d",&m);

	for(int i=0;i<m;i++)
	{
		max=10000000;
		fscanf(fs,"%d %d\n",&n,&l);


		for(int j=0;j<n;j++)
			fscanf(fs,"%s",Str[j]);
		for(int j=0;j<n;j++)
			fscanf(fs,"%s",Crt[j]);

		check(1,0,1);
		check(0,0,0);
		if(max!=10000000)
			fprintf(fp,"Case #%d: %d\n",i+1,max);
		else
			fprintf(fp,"Case #%d: NOT POSSIBLE\n",i+1);
	}

	fclose(fs);
	fclose(fp);
	return 0;
}