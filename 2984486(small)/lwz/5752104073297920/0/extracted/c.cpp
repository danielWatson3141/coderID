#include<cstdio>
#include<set>
using namespace std;
struct node{ int i,v; };
struct comp{ bool operator()(node x,node y){ if( x.v<y.v ) return true; if( x.v==y.v && x.i<y.i ) return true; return false; } };
set<node,comp> b;
int r[1000],o[120];
int main()
{
	int N;
	scanf("%d",&N);
	for(int T=1;T<=N;T++)
	{
		int n;
		scanf("%d",&n);
		for(int a=0;a<n;a++) scanf("%d",&r[a]);
		int c=0;
		for(int a=0;a<n;a++) if( r[a]==a ) c++;
		b.insert((node){T,c});
	}
	int c=0;
	while( b.size()>0 )
	{
		node tn=*b.begin();
		b.erase(tn);
		o[tn.i]=c;
		c++;
	}
	for(int T=1;T<=N;T++)
	{
		if( o[T]>=N/2 ) printf("Case #%d: GOOD\n",T);
		else printf("Case #%d: BAD\n",T);
	}
	return 0;
}
