#include<stdio.h>
#include<set.h>
FILE *in,*out;
char i[256][64];
char i2[256][64];
char j[256][64];
int k;
struct cmp1
{
	bool operator()(int x,int y)
	{
		int a;
		for(a=0;a<k;a++)
		{
			if( i2[x][a]<i2[y][a] ) return true;
			if( i2[x][a]>i2[y][a] ) return false;
		}
		return x<y;
	}
};
struct cmp2
{
	bool operator()(int x,int y)
	{
		int a;
		for(a=0;a<k;a++)
		{
			if( j[x][a]<j[y][a] ) return true;
			if( j[x][a]>j[y][a] ) return false;
		}
		return x<y;
	}
};
set<int,cmp1> h1;
set<int,cmp2> h2;
int p1[256];
int p2[256];
int main()
{
	in=fopen("a.in","r");
	out=fopen("a.out","w");
	int tc,test;
	int n,c,o;
	int a,s,d;
	bool t;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		fscanf(in,"%d%d",&n,&k);
		for(a=0;a<n;a++) fscanf(in,"%s",&i[a]);
		for(a=0;a<n;a++) fscanf(in,"%s",&j[a]);
		h2.clear();
		for(a=0;a<n;a++) h2.insert(a);
		for(a=0;a<n;a++)
		{
			p2[a]=*h2.begin();
			h2.erase(p2[a]);
		}
		o=k+1;
		for(a=0;a<n;a++)
		{
			c=0;
			for(s=0;s<k;s++)
			{
				if( i[a][s]==j[0][s] )
				{
					for(d=0;d<n;d++) i2[d][s]=i[d][s];
				}
				else
				{
					for(d=0;d<n;d++)
					{
						i2[d][s]='0'+'1'-i[d][s];
					}
					c++;
				}
			}
			h1.clear();
			for(s=0;s<n;s++) h1.insert(s);
			for(s=0;s<n;s++)
			{
				p1[s]=*h1.begin();
				h1.erase(p1[s]);
			}
			t=true;
			for(s=0;s<n;s++)
			{
				for(d=0;d<k;d++)
				{
					if( i2[p1[s]][d]!=j[p2[s]][d] )
					{
						t=false;
						s=n; d=k;
					}
				}
			}
			if( t==true ) if( c<o ) o=c;
		}
		fprintf(out,"Case #%d: ",test);
		if( o==k+1 ) fprintf(out,"NOT POSSIBLE");
		else fprintf(out,"%d",o);
		fprintf(out,"\n");
	}
	return 0;
}