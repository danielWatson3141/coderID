/* 
	Pranshul Agarwal
	CSE B.tech 3rd year
	MNNIT Allahabad
*/

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <climits> 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip> 
#include <iostream> 
#include <limits>
#include <list>
#include <map> 
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream>> ostring stream<<
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <stack>
#include <string>  
#include <utility>   
#include <vector> 


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector < int > vi;
typedef pair< int ,int > ii;
typedef istringstream iss;
typedef ostringstream oss;

#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)

#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))

#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))

#define INF (int(1e5))
#define INFL (LL(1e18))
#define ESP (1e-9)
#define MOD 1000000007

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

#define found(A, x) (A.find(x) != A.end()) 
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz size()
#define ln length()


#define rep(i,n) for(int i=0;i<n;i++)
#define inc(i,a,n) for(int i=a;i<=n;i++)
#define dec(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 

#define in(n) scanf("%d",&n)
#define in2(n,m) scanf("%d%d",&n,&m)
#define inll(n) scanf("%lld",&n)
#define ins(s) scanf("%s",s)

#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define outs(s) printf("%s\n",s)

#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
/*
long long gcd(long long a,long long b)
{
	while(b)
		b^=a^=b^=a%=b;
	return a;
}
long long int power(long long int b,long long int e)
{
	long long ans=1,temp;
	while(e>0)
	{
		if(e%2)
			ans=(ans*b)%MOD;
		b=(b*b)%MOD;
		e/=2;
	}
	return ans;
}*/
int n,L;
char ar[200][50],br[200][50],cr[200][50];
string cr_[200],br_[200];
int fun(int idx,ll bit)
{
	if(idx==L)
	{
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<L;i++)
				br[j][i]=ar[j][i];
		}
		for(int i=0;i<L;i++)
		{
			if(bit & ((1LL)<<i))
			{
				for(int j=0;j<n;j++)
				{
					if(ar[j][i]=='0')
						br[j][i]='1';
					else
						br[j][i]='0';
				}
			}
		}
		for(int j=0;j<n;j++)
			br_[j]=(string)(br[j]);
		sort(br_,br_+n);
		for(int j=0;j<n;j++)
		{
			if(cr_[j]!=br_[j])
				return INF;
		}
		return 0;
	}
	ll x,y,ans;
	x=fun(idx+1,bit);
	y=fun(idx+1,bit ^ ((1LL)<<idx));
	ans=min(x,1+y);
	if(ans>=INF)
		ans=INF;
	return ans;
}
int main()
{
	int t,tc,x;
	for(scanf("%d",&tc),t=1;t<=tc;t++)
	{
		memset(br,0,sizeof(br));
		in2(n,L);
		for(int i=0;i<n;i++)
			scanf("%s",ar[i]);
		for(int i=0;i<n;i++)
			cin>>cr_[i];
		sort(cr_,cr_+n);
		x=fun(0,0);
		if(x==INF)
			printf("Case #%d: NOT POSSIBLE\n",t);
		else
			printf("Case #%d: %d\n",t,x);
	}
	return 0;
}