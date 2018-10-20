/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
	return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
	o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
	ostream &out; bool first;
	void start() { first = true; }
	debugger(ostream& out):out(out) {start();}
	void nl() { out << endl; start(); }
	// Taken from rudradevbasak
	template<class T> debugger& operator,(T& v) {
		if(first) first = false; else out << ", ";
		out << v; return *this;
	}
	template<class T> debugger& operator,(pair<T*,int> arr) { //array print
		out << "{";
                FOR(i, arr.second) { out << arr.first[i] << ", "; }
		out << "}";
		return *this;
	}
} dbg(cerr);
int n,m;
#define INF 10000
int dp[1111][1111];
vi v[1111];
int fun(int par,int node){
 //   cout<<par<<"--"<<node<<endl;
    if(dp[par][node]!=-1)return dp[par][node];
    int mx1=-1;
    int mx2=-1;
    FOR(i,sz(v[node])){
        int u=v[node][i];
        if(u!=par){
            if(fun(node,u)>mx1){
                mx2=mx1;
                mx1=fun(node,u);
            }
            else if(fun(node,u)>mx2){
                mx2=fun(node,u);
            }
        }
    }

    if(mx2>-1){
        dp[par][node]=mx1+mx2+1;
    }else dp[par][node]=1;
    return dp[par][node];

}
int main()
{
	RFILE("input.txt");
	WFILE("op_cj_1b_large.txt");
	int t,cn=1;
	cin>>t;
	while(t--)
	{
        cin>>n;
        FOR1(j,n){
            v[j].clear();
        }
        FOR(i,n-1){
            int X,Y;
            cin>>X>>Y;
            v[X].pb(Y);
            v[Y].pb(X);
        }

        ms(dp,-1);
        int mx=0;
        int i=0;
             FOR1(j,n){
                int ret=fun(i,j);
                mx=max(ret,mx);
              //  cout<<ret<<endl;
             }


        cout<<"Case #"<<cn++<<": ";

        cout<<n-mx;
        cout<<endl;

    }


	return 0;
}

