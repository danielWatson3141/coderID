// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();++i)
#define LET(x,a) __typeof(a) x(a)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair

#define EXIST(e,s) ((s).find(e)!=(s).end())

#define RESET(a) memset((a),0,sizeof(a))
#define SET(a) memset((a),-1,sizeof(a))
#define PB push_back
#define DEC(it,command) __typeof(command) it=command

const int INF=0x3f3f3f3f;

typedef long long Int;
typedef unsigned long long uInt;
#ifdef __MINGW32__
typedef double rn;
#else
typedef long double rn;
#endif

typedef pair<int,int> pii;

/*
#ifdef MYDEBUG
#include"debug.h"
#include"print.h"
#endif
*/
// }}}

int N,L;

void main2(){
	vector<string> from, to;
	cin>>N>>L;
	REP(i,N){
		string a;
		cin>>a;
		from.push_back(a);
	}
	REP(i,N){
		string b;
		cin>>b;
		to.push_back(b);
	}
	/*
	REP(i,N){
		cout<<from[i]<<" ";
	}
	cout<<endl;
	REP(i,N){
		cout<<to[i]<<" ";
	}
	cout<<endl;
	*/
	sort(ALL(to));
	//from[0] and to[i]
	int ans = INF;
	REP(i,N){
		string bt;
		int flip=0;
		REP(j,L){
			if(from[0][j]==to[i][j])bt+="0";
			else bt+="1",flip++;
		}
		vector<string> f;
		REP(j,N){
			string s;
			REP(k,L){
				if(from[j][k]==bt[k])s+="0";
				else s+="1";
			}
			f.push_back(s);
		}
		sort(ALL(f));
		bool valid=true;
		REP(i,to.size())if(to[i]!=f[i])valid=false;
		if(valid){
			ans=min(flip,ans);
//			cout<<"found: "<<bt<<endl;
		}
	}
	if(ans==INF){
		cout<<"NOT POSSIBLE"<<endl;
	}else{
		cout<<ans<<endl;
	}
}

// main function {{{
int main() {
	int T;cin>>T;
	REP(ct, T){
		cout<<"Case #"<<ct+1<<": ";
		main2();
	}
	return 0;
}
//}}}
