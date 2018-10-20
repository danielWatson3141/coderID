#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

set<int> node[1000];

int N;
int getDepth(int n)
{
	if(node[n].size() < 2)
		return 1;
	int max1 = 0, max2 = 0;
	set<int>::iterator it;
	for(it = node[n].begin(); it != node[n].end(); it++)
	{
		node[*it].erase(n);	
		int tmp = getDepth(*it);
		if(tmp >= max1)
		{
			max2 = max1;
			max1 = tmp;
		}
		else if(tmp > max2)
			max2 = tmp;
		node[*it].insert(n);	
	}
	return max1+max2+1;
}

int solve()
{
	int ret = 0;
	int i,j;
	for(i=0;i<N;i++)
	{
		set<int>::iterator it;
		for(it = node[i].begin(); it != node[i].end(); it++)
			cout << (*it) << ' ';
		cout << endl;
		j = getDepth(i);
		if(j>ret)
			ret = j;
	}
	return (N-ret);
}

int main()
{
	FILE *in,*out;
//	char line[1000];
	int T, t;
	int i, j, a, b;
	in = fopen("B.in","r");
	out = fopen("B.out","w+");
//	fgets(line,999,in);
//	sscanf(line,"%d",&T);
	fscanf(in,"%d ",&T);
	for(t = 1; t <= T; t++)
	{
//		fgets(line,999,in);//empty line
		fscanf(in,"%d ", &N);
		for(i=0; i < N; i++)
			node[i].clear();
		for(i=0; i < N-1; i++)
		{
			fscanf(in,"%d %d ",&a, &b);
			a--;
			b--;
			node[a].insert(b);
			node[b].insert(a);
		}
		fprintf(out, "Case #%d: %d\n",t,solve());
	}
	fclose(in);
	fclose(out);
}
