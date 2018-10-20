#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

unsigned int slove_small(unsigned int L,const vector<string>& src,const vector<string>& dst)
{
	unsigned int ans = L + 1;
	for(unsigned int imask = 0;imask < (1<<L);++imask)
	{
		vector<string> tmp = src;
		size_t count = 0;
		for(unsigned int ibit = 0;ibit < L;++ibit)
		{
			if(0 == (imask&(1<<ibit))) continue;
			++ count;
			for(size_t i = 0;i < tmp.size();++i)
			{
				tmp[i][ibit] = '0' + '1' - tmp[i][ibit];
			}
		}
		if(count >= ans) continue;
		std::sort(tmp.begin(),tmp.end());
		bool allok = true;
		for(size_t i = 0;i < tmp.size() && allok;++i)
		{
			if(tmp[i] != dst[i]) allok = false;
		}
		if(allok) ans = count;
	}
	return ans;
}

unsigned int slove_large(unsigned int L,const vector<string>& src,const vector<string>& dst)
{
	unsigned int ans = L + 1;
	size_t size = src.size();
	for(size_t i = 0;i < size;++i)
	{
		unsigned int imask = 0,count = 0;
		for(unsigned int ibit = 0;ibit < L;++ibit)
		{
			if(src[i][ibit] != dst[0][ibit]) ++count,imask |= (1<<ibit);
		}
		if(count >= ans) continue;

		vector<string> tmp = src;
		for(unsigned int ibit = 0;ibit < L;++ibit)
		{
			if(0 == (imask&(1<<ibit))) continue;
			for(size_t i = 0;i < tmp.size();++i)
			{
				tmp[i][ibit] = '0' + '1' - tmp[i][ibit];
			}
		}
		std::sort(tmp.begin(),tmp.end());
		bool allok = true;
		for(size_t i = 0;i < tmp.size() && allok;++i)
		{
			if(tmp[i] != dst[i]) allok = false;
		}
		if(allok) ans = count;

	}
	return ans;
}

int main()
{
	static const size_t buff_size = 100;

	unsigned int nCases = 0;scanf("%d",&nCases);
	for(unsigned int iCases = 1;iCases <= nCases;++iCases)
	{
		unsigned int n = 0,L = 0;scanf("%d%d",&n,&L);
		char buff[buff_size] = { 0 };
		vector<string> src(n),dest(n);
		for(unsigned int i = 0;i < n;++i) { scanf("%s",buff);src[i] = buff; }
		for(unsigned int i = 0;i < n;++i) { scanf("%s",buff);dest[i] = buff; }
		std::sort(dest.begin(),dest.end());

		//unsigned int ans = slove_small(L,src,dest);
		unsigned int ans = slove_large(L,src,dest);
		if(ans > L) printf("Case #%u: NOT POSSIBLE\n",iCases);
		else printf("Case #%u: %u\n",iCases,ans);
	}
	return 0;
}