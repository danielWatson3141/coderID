#include<stdio.h>
FILE *in,*out;
int i[1024];
int main()
{
	in=fopen("c.in","r");
	out=fopen("c.out","w");
	int tc,test;
	int n,r;
	int a,t;
	fscanf(in,"%d",&tc);
	for(test=1;test<=tc;test++)
	{
		fscanf(in,"%d",&n);
		for(r=0;r*r<n;r++)
		for(a=0;a<n;a++) fscanf(in,"%d",&i[a]);
		t=0;
		for(a=0;a<r;a++) t+=i[a];
		fprintf(out,"Case #%d: ",test);
		if( t<r*(n-1)/2+r*r*3 ) fprintf(out,"GOOD");
		else fprintf(out,"BAD");
		fprintf(out,"\n");
	}
	return 0;
}