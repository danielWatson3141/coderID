#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");

struct data{
	char str[201];
};

int case_n;
int n,m;
int realdab;
data my[201];
data dab[201];

int compare(data ta,data tb)
{
	if(strcmp(ta.str,tb.str)==1)	return 1;
	return 0;
}

void recu(int x,int cnt)
{
	if(cnt>=realdab)	return;
	if(x==m)
	{
		if(realdab>cnt)
			realdab=cnt;
	}
	else
	{
		int cnt1=0;
		int cnt2=0;
		int flag=0;

		for(int i=0;i<n;i++)
		{
			if(my[i].str[x]=='1')
				cnt1++;
			if(dab[i].str[x]=='1')
				cnt2++;
			if(my[i].str[x]!=dab[i].str[x])	flag=1;
		}

		if(cnt1!=cnt2 && cnt1+cnt2!=n)	return;
		if(flag==0)
			recu(x+1,cnt);

		for(int i=0;i<n;i++)
		{
			if(my[i].str[x]=='1')
				my[i].str[x]='0';
			else
				my[i].str[x]='1';
		}

		sort(my,my+n,compare);

		flag=0;

		for(int i=0;i<n;i++)
		{
			if(my[i].str[x]!=dab[i].str[x])	flag=1;
		}

		if(flag==0)
			recu(x+1,cnt+1);

		for(int i=0;i<n;i++)
		{
			if(my[i].str[x]=='1')
				my[i].str[x]='0';
			else
				my[i].str[x]='1';
		}
	}
}

int main()
{
	int i,j;

	fscanf(in,"%d",&case_n);

	for(int p=0;p<case_n;p++)
	{
		fscanf(in,"%d %d",&n,&m);

		for(i=0;i<n;i++)
			fscanf(in,"%s",my[i].str);
		for(i=0;i<n;i++)
			fscanf(in,"%s",dab[i].str);

		realdab=INT_MAX;

		sort(dab,dab+n,compare);
		sort(my,my+n,compare);

		recu(0,0);

		fprintf(out,"Case #%d: ",p+1);

		if(realdab==INT_MAX)
			fprintf(out,"NOT POSSIBLE\n");
		else
			fprintf(out,"%d\n",realdab);
	}

	return 0;
}