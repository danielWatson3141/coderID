#include<stdio.h>
#include<vector.h>
FILE *in,*out;
vector<int> g[1024];
int dfs(int w,int x)
{
	int y;
	int c,a;
	int v,o1,o2;
	int t;
	c=g[x].size();
	o1=-1;
	o2=-1;
	for(a=0;a<c;a++)
	{
		y=g[x][a];
		if( y==w ) continue;
		v=dfs(x,y);
		if( v>o2 ) o2=v;
		if( o2>o1 ) { t=o1; o1=o2; o2=t; }
	}
	if( o2==-1 ) return 1;
	return 1+o1+o2;
}
int main()
{
	in=fopen("b.in","r");
	out=fopen("b.out","w");
	int tc,test;
	int n,a,s,d;
	int v,o;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		fscanf(in,"%d",&n);
		for(a=0;a<n;a++) g[a].clear();
		for(a=0;a<n-1;a++)
		{
			fscanf(in,"%d%d",&s,&d); s--; d--;
			g[s].push_back(d);
			g[d].push_back(s);
		}
		o=-1;
		for(a=0;a<n;a++)
		{
			v=dfs(-1,a);
			if( v>o ) o=v;
		}
		fprintf(out,"Case #%d: ",test);
		fprintf(out,"%d",n-o);
		fprintf(out,"\n");
	}
	return 0;
}