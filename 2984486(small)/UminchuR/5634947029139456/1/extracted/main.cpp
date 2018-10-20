#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <queue>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <complex>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;

//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define MT(a,b,c) MP(a, MP(b, c))

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define MOD 1000000007

int bitcount(LL k){
	int ret=0;
	while(k){
		ret+=k%2;
		k>>=1;
	}
	return ret;
}

bool possible(VLL &v1, VLL &v2, LL m){
	int n=v1.size();
	REP(i,n)v1[i]^=m;
	SORT(v1);
	bool flag = true;
	REP(i,n)if(v2[i]!=v1[i])flag=false;
	REP(i,n)v1[i]^=m;
	return flag;
}

void solve(){
	int n,l,ret=666;
	scanf("%d%d", &n, &l);
	VLL v1(n), v2(n), vr(n);
	char str[55];
	REP(i,n){
		scanf("%s", str);
		REP(j,l){
			v1[i]<<=1;
			v1[i]|=(str[j]=='1');
		}
	}
	vr=v1;
	REP(i,n){
		scanf("%s", str);
		REP(j,l){
			v2[i]<<=1;
			v2[i]|=(str[j]=='1');
		}
	}
	SORT(v2);
	REP(i,n){
		if(possible(v1, v2, vr[0]^v2[i])){
			ret=min(ret, bitcount(vr[0]^v2[i]));
		}
	}
	if(ret==666)printf("NOT POSSIBLE\n");
	else printf("%d\n", ret);
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin>>T;
	REP(t,T){
		printf("Case #%d: ", t+1);
		solve();
	}
	return 0;
}