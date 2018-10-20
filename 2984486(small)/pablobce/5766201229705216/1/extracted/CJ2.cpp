#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <cmath>
#include <set>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

#define forsn(i,s, n) for(int i=(int)s; i<(int)(n); i++)
#define forn(i, n) forsn(i,0,n)
#define fore(i,n) forn(i,n.size())
#define fori(i, n) for(typeof n.begin() i=n.begin(); i!=n.end();i++)
#define RAYA cout<<"-----------------"<<endl;
#define dbg(x) cout<<#x<<":"<<(x)<<endl;

typedef long long int tint;
typedef long double ldouble;
#define pii pair <int,int>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(n) n.begin(),n.end()
#define rall(n) n.rbegin(),n.rend()

const tint INF=2000000000;

bool u[1024];
vector < vector <int> > v;

int g(int papa, int k){
	int res=1;
	fore(i,v[k])if(papa!=v[k][i])res+=g(k, v[k][i]);
	return res;	
}

int f(int k){
	u[k]=false;
	int cont=0;
	fore(i,v[k])if(u[v[k][i]])cont++;
	if(cont==0) return 0;
	if(cont==1){
		int res=0;
		fore(i,v[k])if(u[v[k][i]])res+=g(k,v[k][i]);
		return res;
	}
	int total=0;
	vector <int> ps;
	fore(i,v[k])if(u[v[k][i]]){
		int m=g(k,v[k][i]);
		int sib=f(v[k][i]);
		int sv=m-sib;
		total+=m;
		ps.pb(sv);
	}
	sort(rall(ps));
	return total-ps[0]-ps[1];	
}

int main(){
	freopen("CJ2.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int n;cin>>n;
		v.clear();
		vector<int>aux;
		forn(i,n)v.pb(aux);
		forn(i,n-1){
			int a,b;cin>>a>>b;
			a--;b--;
			v[a].pb(b);
			v[b].pb(a);
		}
		int res=1000000;
		forn(i,n){
			forn(a,n)u[a]=true;
			res=min(res,f(i));
		}			
		cout<<"Case #"<<1+caso<<": "<<res<<endl;
	}
    return 0;
}
