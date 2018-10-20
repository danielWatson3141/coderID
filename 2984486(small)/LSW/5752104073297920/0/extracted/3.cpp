#include <stdio.h>
#include <algorithm>
using namespace std;

FILE *in=fopen("input.txt","r");
FILE *out=fopen("output.txt","w");

int case_n;
int m;
int a[10000];

int main()
{
	fscanf(in,"%d",&case_n);

	for(int p=0;p<case_n;p++)
	{
		int dab=0;

		fscanf(in,"%d",&m);

		for(int i=0;i<m;i++)
			fscanf(in,"%d",&a[i]);

		for(int i=m-1;i>0;i--)
		{
			int t=-1;

			for(int j=i-1;j>=0;j--)
			{
				if(a[j]==i)
				{
					t=j;
					break;
				}
			}

			if(t==-1)
			{
				dab=1;
				break;
			}
			swap(a[i],a[t]);
		}

		if(dab==1)
			fprintf(out,"Case #%d: BAD\n",p+1);
		else
			fprintf(out,"Case #%d: GOOD\n",p+1);
	}
	
	return 0;
}