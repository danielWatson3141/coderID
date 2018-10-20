#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char c[11][11];
char ds[11][11];
int  flgds[11];

bool isEqual(int N,int L)
{
	bool ret = false;

	bool flg[11];
	memset(flg,0,sizeof(flg));
	int i=0;
	for(i=0;i<N;++i)
	{
		bool fg = false;
		for(int j=0;j<N;++j)
		{
			if(!flg[j])
			{
				if(strcmp(c[i],ds[j])==0)
				{
					flg[j]=1;
					fg  = true;
					break;
				}
			}
		}
		if(!fg)
		{
			break;
		}
	}
	if(i>=N)
		ret=true;
	return ret;
}
int minRet;
void fn(int l,int L,int N,int cnt)
{
	if(l==L)
	{
		if(isEqual(N,L))
		{
			minRet = minRet>cnt?cnt:minRet;
		}
		return ;
	}

	int flgc =0;
	
		for(int k=0;k<N;++k)
		{
			if(c[k][l]=='1')
			{
				flgc++;
			}
		}

	if(flgc==flgds[l])
	{
		fn(l+1,L,N,cnt);
	}

	if(N-flgc==flgds[l])
	{
		for(int k=0;k<N;++k)
		{
			if(c[k][l]=='1')
			{
				c[k][l]='0';
			}
			else
			{
				c[k][l]='1';
			}
		}

		++cnt;
		if(cnt<minRet)
		{
			fn(l+1,L,N,cnt);
			for(int k=0;k<N;++k)
			{
				if(c[k][l]=='1')
				{
					c[k][l]='0';
				}
				else
				{
					c[k][l]='1';
				}
			}
		}
	}
}
int main()
{
	FILE *f,*fout;
	f = fopen("ina.txt","r");
	fout = fopen("outa.txt","w+");
	int n;
	fscanf(f,"%d",&n);


	for(int i=0;i<n;++i)
	{
		memset(c,0,sizeof(c));
		memset(ds,0,sizeof(ds));
		memset(flgds,0,sizeof(flgds));
		int N,L;
		fscanf(f,"%d %d",&N,&L);
		minRet = L+5;
		for(int j=0;j<N;++j)
		{
			fscanf(f,"%s",c[j]);
		}
		for(int j=0;j<N;++j)
		{
			fscanf(f,"%s",ds[j]);
		}
		for(int j=0;j<L;++j)
		{
			for(int k=0;k<N;++k)
			{
				if(ds[k][j]=='1')
				{
					flgds[j]++;
				}
			}
		}
		fn(0,L,N,0);
		if(minRet<=L)
		{
			fprintf(fout,"Case #%d: %d\n",i+1,minRet);
		}
		else
		{

			fprintf(fout,"Case #%d: NOT POSSIBLE\n",i+1);
		}
		
	}

	fclose(f);
	fclose(fout);


	return 1;
}