#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <complex>
#include <numeric>
#include <map>
#include <time.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<ll,ll> pll;
typedef pair<double,int> pdi;
typedef pair<double,double> pdd;
typedef vector<double> vec;
typedef vector<vec> mat;
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define repn(i,a,n) for (int (i) = (a); (i) < (n); (i)++)
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define SORT(x) sort((x).begin(),(x).end())
#define SORTN(x,n) sort((x),(x)+(n))
#define ERASE(x) (x).erase(unique((x).begin(),(x).end()),(x).end())
#define COUNT(x,c) count((x).begin(),(x).end(),(c))
#define REMOVE(x,c) (x).erase(remove((x).begin(),(x).end(),(c)),(x).end())
#define REVERSE(x) reverse((x).begin(),(x).end())
#define FORIT(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define LB(x,a) lower_bound((x).begin(),(x).end(),(a))-(x).begin()
#define lb(x,a) lower_bound((x).begin(),(x).end(),(a))
#define LBN(x,a,n) lower_bound((x),(x)+(n),(a))-(x)
#define lbN(x,a,n) lower_bound((x),(x)+(n),(a))
#define UB(x,a) upper_bound((x).begin(),(x).end(),(a))-(x).begin()
#define ub(x,a) upper_bound((x).begin(),(x).end(),(a))
#define BS(x,a) binary_search((x).begin(),(x).end(),(a))
#define NB(x) (((x)&~((x)+((x)&-(x))))/((x)&-(x))>>1)|((x)+((x)&-(x)))
#define NP(x) next_permutation((x).begin(),(x).end())
#define MM(x,p) memset((x),(p),sizeof(x))
#define SQ(x) (x)*(x)
#define SC(c1,c2) strcmp(c1,c2)==0
#define mp make_pair
#define INF (1<<30)
#define INFL (1LL<<56)
#define fi first
#define se second
#define MOD 1000000007
#define EPS 1e-9

int T;
int N,L;
ll A[150],B[150];
string s;

int main()
{
	scanf("%d",&T);
	repn(_,1,T+1)
	{
		scanf("%d%d",&N,&L);
		rep(i,N)
		{
			A[i]=0;
			cin>>s;
			rep(j,L)A[i]=A[i]*2+(s[j]=='1');
		}
		rep(i,N)
		{
			B[i]=0;
			cin>>s;
			rep(j,L)B[i]=B[i]*2+(s[j]=='1');
		}
		int ans=INF;
		rep(cc,N)
		{
			ll df=A[0]^B[cc];
			multiset<ll> st;
			rep(i,N)st.insert(B[i]);
			bool ok=true;
			rep(i,N)
			{
				multiset<ll>::iterator it=st.lower_bound(A[i]^df);
				if(*it!=(A[i]^df))ok=false;
				else st.erase(it);
			}
			if(ok)
			{
				int tt=0;
				rep(i,L)tt+=(df>>i&1);
				ans=min(ans,tt);
			}
		}
		printf("Case #%d: ",_);
		if(ans==INF)puts("NOT POSSIBLE");
		else printf("%d\n",ans);
	}
}
