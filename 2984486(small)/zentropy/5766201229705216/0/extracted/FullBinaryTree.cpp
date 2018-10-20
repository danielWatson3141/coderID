#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using std::vector;
using std::string;

size_t slove_small(const vector< vector<bool> >& g)
{
	size_t size = g.size(),ans = size + 1;
	for(unsigned int imask = 0;imask < (1<<size);++imask)
	{
		size_t countbit = 0;
		for(unsigned int ibit = 0;ibit < size;++ibit)
		{
			if(imask&(1<<ibit)) ++ countbit;
		}
		if(countbit >= ans) continue;

		vector<unsigned int> nodes;
		vector< vector<bool> > gtmp = g;
		for(unsigned int ibit = 0;ibit < size;++ibit)
		{
			if(0 == (imask&(1<<ibit))) continue;
			nodes.push_back(ibit);
			for(size_t i = 0;i < size;++i) { gtmp[ibit][i] = false;gtmp[i][ibit] = false; }
		}

		size_t count2 = 0,count0 = 0,count3 = 0,count1 = 0,count = 0;
		for(size_t i = 0;i < size;++i)
		{
			size_t degree = 0;
			for(size_t k = 0;k < size;++k) degree += gtmp[i][k];
			if(0 == degree)
			{
				if(!std::binary_search(nodes.begin(),nodes.end(),i)) ++count0;
			}
			else if(1 == degree) ++ count1;
			else if(2 == degree) ++count2;
			else if(3 == degree) ++count3;
			else ++count;
		}
		if(count != 0) continue;						// 
		if(count2 != 1 && count2 != 0) continue;
		if(0 == count2)
		{
			if(1 != count0) continue;
			if(0 != count1) continue;
			if(0 != count3) continue;
		}
		else
		{
			if(0 != count0) continue;
			if(2 + count3 != count1) continue;
		}
		ans = countbit;
	}
	assert(ans < size);
	return ans;
}

size_t slove_large(const vector< vector<bool> >& g)
{
	size_t size = g.size(),ans = size + 1;
	return ans;
}

int main()
{
	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,x = 0,y = 0;scanf("%d",&n);
		vector< vector<bool> > g(n,vector<bool>(n,false));
		for(unsigned int i = 1;i < n;++i)
		{
			scanf("%d%d",&x,&y);--x;--y;
			g[x][y] = true;g[y][x] = true;
		}
		size_t ans = slove_small(g);
		printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}