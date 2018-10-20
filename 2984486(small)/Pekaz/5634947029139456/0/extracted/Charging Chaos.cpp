#include <stdio.h>
#include <string>
#include <algorithm>
#include <stdlib.h>

using namespace std;

bool strslt(string a,string b)
{
	if(a.compare(b)<0)
		return 1;
	else
		return 0;
}

int main()
{
	FILE *in,*out;
	in=fopen("A-small-attempt0.in","r");
	out=fopen("output.txt","w");

	int t,tcase;
	int n,l,re,chk;
	string orig[155],comp[155],temp[155];
	int changed[44],changeCnt;
	char inp[44];

	fscanf(in,"%d",&tcase);
	
	for(t=0;t<tcase;t++)
	{
		re=44;
		fscanf(in,"%d",&n);
		fscanf(in,"%d",&l);

		for(int i=0;i<n;i++)
		{
			fscanf(in,"%s",inp);
			orig[i]=inp;
		}
		for(int i=0;i<n;i++)
		{
			fscanf(in,"%s",inp);
			comp[i]=inp;
		}
		sort(&comp[0],&comp[n],strslt);
		for(int i=0;i<n;i++)
		{
			changeCnt=0;
			for(int j=0;j<l;j++)
			{
				if(orig[0].at(j) != comp[i].at(j))
					changed[changeCnt++]=j;
			}

			for(int j=0;j<n;j++)
			{
				temp[j]=orig[j];
				for(int z=0;z<changeCnt;z++)
					temp[j][changed[z]]=(temp[j][changed[z]]=='1'?'0':'1');
			}
			chk=0;
			sort(&temp[0],&temp[n],strslt);
			for(int j=0;j<n;j++)
			{
				if(temp[j].compare(comp[j])!=0)
				{
					chk=1;
					break;
				}
			}
			if(chk==0 && re > changeCnt)
				re=changeCnt;
		}
		fprintf(out,"Case #%d: ",t+1);
		if(re==44)
			fprintf(out,"NOT POSSIBLE\n");
		else
			fprintf(out,"%d\n",re);
	}

	return 0;
}