#include <algorithm>
#include <numeric>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cassert>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define FORD(k,a,b) for(int k(a-1); k >= (b); --k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))

vector<LL> goodcalc(LL act, const vector<LL>& flow)
{
	vector<LL> ans;
	REP(i,flow.size())
	{
		ans.push_back(act^flow[i]);
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	return ans;
}

int popcount(LL a)
{
	int res= 0;
	while(a)
	{
		a&=(a-1);
		++res;
	}
	return res;
}

int main()
{
#ifdef HOME 
	freopen("A-small-attempt0.in","rb",stdin);
	freopen("A-small-attempt0.out","w",stdout);
#endif
	int T;
	scanf("%d",&T);
	FOR(tc,1,T+1)
	{
		int N,L;
		scanf("%d %d",&N,&L);
		char c[50];
		vector<LL> outlet(N), flow(N);
		REP(i,N)
		{
			scanf("%s",c);
			LL tmp=0;
			REP(j,L)
			{
				tmp<<=1;
				if(c[j]=='1')
					tmp++;
			}
			flow[i]=tmp;
		}
		REP(i,N)
		{
			scanf("%s",c);
			LL tmp=0;
			REP(j,L)
			{
				tmp<<=1;
				if(c[j]=='1')
					tmp++;
			}
			outlet[i]=tmp;
		}
		vector<LL> good = goodcalc(outlet[0],flow);
	
		REP(i,N)
		{
			vector<LL> act = goodcalc(outlet[i],flow);
			vector<LL> actg(1000);
			vector<LL>::iterator it=set_intersection(good.begin(),good.end(),act.begin(),act.end(),actg.begin());
			actg.resize(it-actg.begin());
			actg.swap(good);
		}
		if(good.empty())
		{
			printf("Case #%d: NOT POSSIBLE\n",tc);
			continue;
		}
		int ans=1000;
		REP(i,good.size())
		{
			ans=min(ans,popcount(good[i]));
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}