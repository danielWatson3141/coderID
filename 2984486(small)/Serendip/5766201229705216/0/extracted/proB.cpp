#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
vector<int> nd[1005];
int fn(int cur,int father,int &allsum,int &needsum)
{
	int ret = 0;
// 	vector<int>all;
// 	vector<int>del;
	vector<int>need;
	for(int i=0;i<nd[cur].size();++i)
	{
		if(nd[cur][i]!=father)
		{
			int nall =0,nneed=0;
			fn(nd[cur][i],cur,nall,nneed);
			//all.push_back(nall);
			need.push_back(nneed);
			allsum+=nall;
		}
	}
	allsum+=1;

	if(need.size()==2)
	{
		needsum = need[0]+need[1];
	}
	else if(need.size()>2)
	{
		int maxi=0;
		for(int i=0;i<need.size();++i)
		{
			if(need[i]>need[maxi])
				maxi=i;
		}
		needsum+=need[maxi];
		need[maxi] = 0;
		maxi=0;
		for(int i=0;i<need.size();++i)
		{
			if(need[i]>need[maxi])
				maxi=i;
		}
		needsum+=need[maxi];
		need[maxi] = 0;

	}
	needsum+=1;
	ret = allsum-needsum;

	return ret;
}
int main()
{
	FILE *f,*fout;
	f = fopen("inb.txt","r");
	fout = fopen("outb.txt","w+");
	int t;
	fscanf(f,"%d",&t);


	for(int i=0;i<t;++i)
	{
		int n;
		fscanf(f,"%d",&n);
		for(int j=0;j<1005;++j)
			nd[j].clear();
		for(int j=0;j<n-1;++j)
		{
			int a,b;
			fscanf(f,"%d %d",&a,&b);
			nd[a].push_back(b);
			nd[b].push_back(a);
		}
		int minRet = 10000;
		for(int j=1;j<=n;++j)
		{
			int all=0,needsum=0;
			int ret = fn(j,0,all,needsum);
			minRet=minRet>ret?ret:minRet;
		}
		fprintf(fout,"Case #%d: %d\n",i+1,minRet);
	}

	fclose(f);
	fclose(fout);


	return 1;
}