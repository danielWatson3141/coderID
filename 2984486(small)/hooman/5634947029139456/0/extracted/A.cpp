#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

int N,L;

set<long long> A,B;

int ones(int n)
{
	int ret =0;
	while(n)
	{
		n= n & (n-1);
		ret++;
	}
	return ret;
}

int main()
{
	FILE *in,*out;
	char line[1000];
	int T, t;
	int i, j;
	in = fopen("A.in","r");
	out = fopen("A.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
		fscanf(in,"%d %d ",&N, &L);
//		fgets(line,999,in);//empty line
		long long a,b;
		A.clear();
		for(i = 0; i< N; i++)
		{
			fscanf(in,"%s ",line);
			a = 0;
			for(j=0; j< L; j++)
			{
				a<<=1;
				if(line[j] == '1')
					a |= 1;
				
			}
			A.insert(a);
		}
		B.clear();
		for(i = 0; i< N; i++)
		{
			fscanf(in,"%s ",line);
			b = 0;
			for(j=0; j< L; j++)
			{
				b<<=1;
				if(line[j] == '1')
					b |= 1;
				
			}
			B.insert(b);
		}
		for(i=0;i<=L;i++)
		{
			for(j=0; j<(1<<L); j++)
			{
				if(ones(j)==i)
				{
					set<long long>::iterator it1,it2;
					for(it1 = A.begin(); it1 != A.end(); it1++)
						if(B.find((*it1)^j)==B.end())
							break;
					if(it1 == A.end())
						goto finish;
				}
			}
		}
		finish:
		if(i==L+1)
			fprintf(out, "Case #%d: NOT POSSIBLE\n",t);
		else
			fprintf(out, "Case #%d: %d\n",t,i);
	}
	fclose(in);
	fclose(out);
}
