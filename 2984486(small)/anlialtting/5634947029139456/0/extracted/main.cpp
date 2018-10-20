// By An-Li Alt Ting. Default code 2014-03-28.
#include<stdint.h>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<valarray>
#include<vector>
//#include<bits/extc++.h>
//#include<bits/stdc++.h>
//#include<ext/algorithm>
//#include<ext/numeric>
//#include<ext/rope>
//#include<ext/slist>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_cxx;
//using namespace __gnu_pbds;
typedef long long	LL;	// long long
typedef double		LF;	// long float
typedef map<int,int>	MI;	// map int
typedef pair<int,int>	PI;	// pair int
typedef queue<int>	QI;	// queue int
typedef set<int>	SI;	// set int
typedef vector<int>	VI;	// vector int
//typedef tree<int,char,less<int>,rb_tree_tag,tree_order_statistics_node_update>TI;
//typedef tree<PI,char,less<PI>,rb_tree_tag,tree_order_statistics_node_update>TPI;
//typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>TII;
//typedef tree<PI,int,less<int>,rb_tree_tag,tree_order_statistics_node_update>TPII;
#define x first
#define y second
#define pb push_back
#define it iterator
#define F(n) FO(i,n)				// for i in [0,$n)
#define FO(i,n) FI(i,0,n)			// for $i in [0,$n)
#define FI(i,f,l) for(int i=(f),ei=(l);i<ei;i++)
#define FD(i,f,l) for(int i=(f),ei=(l);i>ei;i--)
#define FA(a) for(__typeof((a).begin())it=(a).begin(),ea=(a).end();\
		it!=ea;++it)		// for *it in a
/*inline LL GI(){    // getchar input integer
	char s,d;
	while(s=getchar(),s==' '||s=='\n');
	LL x=s=='-'?0:s-'0';
	while(d=getchar(),'0'<=d&&d<='9')x=x*10+d-'0';
	return s=='-'?-x:x;
}*/
/*struct sv{	// union-find tree
	sv*p;
	sv():p(this){}
	sv*r(){return p==this?p:(p=p->r());}
	sv&operator=(sv&v){return*(r()->p=v.r());}
	bool operator==(sv&v){return r()==v.r();}
};*/
const int mn=150;
int n,l;
int a[mn],b[mn];
int in(int&k){
	k=0;
	F(l){
		int m;scanf("%1d",&m);
		k=2*k+m;
	}
}
int f(int d){
	int msk=1<<l-d-1;
	F(n)if(a[i]/msk!=b[i]/msk)return 1;
	return 0;
}
int flp(int d){
	int msk=1<<l-d-1;
	F(n)b[i]^=msk;
}
int ans;
int con(int d=0,int k=0){
	if(d==l){
		ans=min(ans,k);
		return 1;
	}
	sort(b,b+n);if(f(d)==0)con(d+1,k);flp(d);
	sort(b,b+n);if(f(d)==0)con(d+1,k+1);flp(d);
	return 0;
}
int main(int argc,char*argv[]){
	//freopen("i.txt","r",stdin);
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	//ios_base::sync_with_stdio(0);
	int t;cin>>t;
	F(t){
		cin>>n>>l;
		F(n)in(a[i]);
		F(n)in(b[i]);
		sort(a,a+n);
		ans=100;
		con();
		printf("Case #%i: ",i+1);
		if(ans==100)puts("NOT POSSIBLE");
		else printf("%i\n",ans);
	}
	return EXIT_SUCCESS;
}
