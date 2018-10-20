#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
lint a[155],b[155],c[155];
lint dec(string s){
	lint ret=0;
	rep(i,s.size()) ret=ret*2+(s[i]-'0');
	return ret;
}
int main()
{
	string s;int t,n,l;
	cin>>t;
	rep(i,t){
		cin>>n>>l;
		rep(j,n) cin>>s,a[j]=dec(s);
		rep(j,n) cin>>s,b[j]=dec(s);
		sort(a,a+n);
		int ret=114514;
		printf("Case #%d: ",i+1);
		rep(j,n){
			lint v=b[0]^a[j];
			rep(k,n) c[k]=b[k]^v;
			sort(c,c+n);
			int f=0;
			rep(k,n){
				if(c[k]!=a[k]) f=1;
			}
			if(f<1) ret=min(ret,__builtin_popcountll(v));
		}
		if(ret>=114514) cout<<"NOT POSSIBLE"<<endl;
		else cout<<ret<<endl;
	}
}
