#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int INF=1000000000;

const int MaxN=210;
const int MaxL=50;

int N,L;
bitset<MaxL> a[MaxN],b[MaxN];
string as[MaxN],bs[MaxN];

bool check(bitset<MaxL> &d)
{
	for (int i=1;i<=N;++i)
		as[i]=(a[i]^d).to_string();
	sort(as+1,as+N+1);
	for (int i=1;i<=N;++i)
		if (as[i]!=bs[i]) return false;
	return true;
}

int main()
{
	freopen("try.in","r",stdin);
	freopen("try.out","w",stdout);
	int T;
	cin>>T;
	for (int TT=1;TT<=T;++TT)
	{
		printf("Case #%d: ",TT);
		cin>>N>>L;
		for (int i=1;i<=N;++i)
			cin>>a[i];
		for (int i=1;i<=N;++i)
		{
			cin>>b[i];
			bs[i]=b[i].to_string();
		}
		sort(bs+1,bs+N+1);
		int ans=INF;
		for (int i=1;i<=N;++i)
		{
			bitset<MaxL> d=a[1]^b[i];
			if (check(d)) ans=min(ans,(int)d.count());
		}
		if (ans==INF)
			puts("NOT POSSIBLE");
		else
			cout<<ans<<endl;
	}
	return 0;
}
