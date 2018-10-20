#include <iostream> 
#include <fstream>
#include <sstream> 
#include <cstring>
#include <string> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <utility> 
#include <functional> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) FOR(i,0,a)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr) 
#define X first
#define Y second
#define PB push_back
#define MP make_pair
int n,l;
#define ll long long
string s;
ll a[200],b[200],tmp[200],tb[200];
ll s2l(string &x){
	ll res=0L;
	for(int i=0;i<x.size();++i){
		res<<=1;
		res+=x[i]-'0';
	}
	return res;
}
bool check(){
	sort(tmp,tmp+n);sort(tb,tb+n);
	rep(i,n)if(tmp[i]!=tb[i])return false;
	return true;
}
int main() {
	int T;cin>>T;
	rep(t,T){
		int best=100;
		printf("Case #%d: ", t+1);
		cin>>n>>l;
		rep(i,n){cin>>s;a[i]=s2l(s);}
		rep(i,n){cin>>s;b[i]=s2l(s);}
		rep(i,n){
			ll x=a[0]^b[i];
			rep(j,n)tb[j]=b[j];
			rep(j,n)tmp[j]=a[j]^x;
			if(check()){
				int res=0;
				rep(k,l)if(x&(1LL<<k))++res;
				best=min(best,res);
			}
		}
		if(best==100)printf("NOT POSSIBLE\n");
		else printf("%d\n", best);
	}
 	return 0;
}
