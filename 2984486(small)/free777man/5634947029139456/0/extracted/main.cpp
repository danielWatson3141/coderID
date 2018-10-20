#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 
#define ALL(a) (a).begin(), (a).end() 
#define SZ(a) (int)(a).size() 
#define FOR(i,s,n) for(int i=(s);i<(n);++i) 
#define REP(i,n) FOR(i,0,(n)) 
#define PB(x) push_back((x)) 
#define CLR(a,v) memset((a),(v),sizeof((a))) 
typedef long long ll; 


int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w+", stdout);

	int T;
	scanf("%d", &T);

	FOR(ttt,1,T+1)
	{
		int N, L;
		cin>>N>>L;

		vector<string> init(N), need(N);
		REP(i,N)cin>>init[i];
		REP(i,N)cin>>need[i];

		REP(i,N)REP(j,L)init[i][j]-='0', need[i][j]-='0';

		sort(ALL(need));

		int res = 100500;
		REP(mask,1<<L)
		{
			int bc = 0, t = mask;
			while (t)
			{
				++bc;
				t&=t-1;
			}
			if(bc>=res)
				continue;

			char ok = 1;

			vector<string> mod = init;
			REP(j,L)if(mask&(1<<j))REP(i,N)
			{
				mod[i][j]=1-mod[i][j];
			}

			sort(ALL(mod));

			if(mod==need)res=bc;
		}

		if(res != 100500)
			printf("Case #%d: %d\n",ttt, res);
		else
			printf("Case #%d: NOT POSSIBLE\n",ttt);
	}

	return 0;
}