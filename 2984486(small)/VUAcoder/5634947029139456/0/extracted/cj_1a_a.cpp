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
int fun(int i,int j,vector<string>str1,vector<string>str2){

    vector<string>st1=str1;
    vector<string>st2=str2;
    FOR(k,m){
        if(str1[i][k]  != str2[j][k]){
            FOR(l,n){
                if(st2[l][k]=='0')st2[l][k]='1';
                else st2[l][k]='0';
            }
        }
    }
    sort(all(st1));sort(all(st2));
    if(st1!=st2)return INF;

    int c=0;
    FOR(k,m){
       if(str1[i][k]  != str2[j][k]){
            c++;
        }
    }
    return c;

}
int main()
{
	RFILE("input.txt");
	WFILE("op_cj_1a_2.txt");
	int t,cn=1;
	cin>>t;
	while(t--)
	{
        cin>>n>>m;
        vector<string>str1(n);
        vector<string>str2(n);
        FOR(i,n)cin>>str1[i];
        FOR(i,n)cin>>str2[i];
        int mn=INF;
        int i=0;
             FOR(j,n){
                int ret=fun(i,j,str1,str2);
                mn=min(ret,mn);
             }


        cout<<"Case #"<<cn++<<": ";
        if(mn==INF)cout<<"NOT POSSIBLE" ;
        else cout<<mn;
        cout<<endl;

    }


	return 0;
}

