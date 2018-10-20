// Nipun Poddar , CSE, MNNIT Allahabad

#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<algorithm>

#define in(n) scanf("%d",&n)
#define in2(n,m) scanf("%d%d",&n,&m)
#define in3(n,m,p) scanf("%d%d%d",&n,&m,&p)
#define inll(n) scanf("%lld",&n)
#define inll2(n,m) scanf("%lld%lld",&n,&m)
#define out(n) printf("%d\n",n)
#define out2(n,m) printf("%d %d\n",n,m)
#define outll(n) printf("%lld\n",n)
#define outll2(n,m) printf("%lld %lld\n",n,m)
#define inc(n) scanf("%c",&n)
#define minm(a,b) (a<b?a:b)
#define maxm(a,b) (a<b?b:a)
#define loop(n) for(i=0;i<n;i++)
#define loop1(n) for(i=1;i<=n;i++)
#define fill0(x) memset(x,0,sizeof(x))
#define fill1(x) memset(x,-1,sizeof(x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define pii pair<int,int>
#define ppi pair<int,pii>

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int ui;


#define MOD 1000000007
#define MOD_INV 1000000006
#define MAX 1009
#define INF 999999999

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

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
}
/*
#define getcx getchar_unlocked
inline void inp( int &n )//fast input function
{
   n=0;
   int ch=getcx();int sign=1;
   while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}

   while(  ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
   n=n*sign;
}
*/
using namespace std;

vector<int> V[MAX];
int vis[MAX];
int subtree[MAX];


int stamp;
void dfs_size(int u)
{
	vis[u]=stamp;
	subtree[u]=1;
	for(int i=0;i<V[u].size();i++)
	{
		if(vis[V[u][u]]!=stamp)
		{
			dfs_size(V[u][i]);
			subtree[u]+=subtree[V[u][i]];
		}
	}
}

void dfs_sol(int u,int par)
{
	//cout<<par<<" "<<u<<endl;
	if(V[u].size()==1 && par!=-1)
	{
		vis[u]=stamp;
		subtree[u]=1;
		return ;
	}
	else if(V[u].size()==2 && par!=-1)
	{
		subtree[u]=1;
		vis[u]=stamp;
		return;
	}
	else
	{
		subtree[u]=1;
		vis[u]=stamp;
		vector<pii> tmp;
		if(par==-1 && V[u].size()<2)
		{
			return;
		}
		for(int i=0;i<V[u].size();i++)
		{
			if(vis[V[u][i]]!=stamp)
			{
				dfs_sol(V[u][i],u);
				//cout<<"DFS "<<u<<" "<<V[u][i]<<" "<<subtree[u]<<" "<<subtree[V[u][i]]<<endl;
				subtree[u]+=subtree[V[u][i]];
				tmp.PB(MP(subtree[V[u][i]],V[u][i]));
			}
		}
		sort(tmp.rbegin(),tmp.rend());
		for(int i=2;i<tmp.size();i++)
		{
			subtree[u]-=tmp[i].F;
			subtree[tmp[i].S]=0;
		}
	}
}

int main()
{
	int t,i,j,n,ans,u,v;
	in(t);
	int tmp;
	int x=1;
	while(t--)
	{
		in(n);
		stamp=0;
		for(i=0;i<n;i++)
		{
			V[i].clear();
			vis[i]=0;
			subtree[i]=0;
		}
		loop(n-1)
		{
			in2(u,v);
			u--;v--;
			V[u].PB(v);
			V[v].PB(u);
		}
		ans=INF;
		for(i=0;i<n;i++)
		{
			//stamp++;
			//dfs_size(i);
			stamp++;
			dfs_sol(i,-1);
			tmp=n-subtree[i];
			if(tmp<ans)
				ans=tmp;
		}
		printf("Case #%d: %d\n",x,ans);
		x++;
	}
	return 0;
}
