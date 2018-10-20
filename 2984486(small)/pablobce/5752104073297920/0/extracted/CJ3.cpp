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

double tab[1000][1000];
double tab2[1000][1000];

int main(){
	freopen("CJ3.out","w",stdout);
	int n=1000;
	forn(i,n)forn(j,n)tab[i][j]=0;
	forn(i,n)tab[i][i]=1;
	forn(k,n){
		forn(i,n)forn(j,n)tab2[i][j]=0;
		forn(i,n)forn(j,n)tab2[k][j]+=tab[i][j];
		forn(i,n)if(i!=k)forn(j,n)tab2[i][j]=(n-1)*tab[i][j]+tab[k][j];
		forn(i,n)forn(j,n)tab[i][j]=tab2[i][j]/n;		
	}
	/*forn(i,n){
		forn(j,n) cout<<tab[i][j]<<" ";
		cout<<endl;
	}*/

	
	int T;
	cin>>T;
	forn(caso,T){
		cin>>n;
		long double res=1;
		forn(i,n){
			int j; cin>>j;
			res*=tab[i][j];
		}
		long double f=1;
		forsn(i,1,n+1)f/=i;
		cout<<"Case #"<<1+caso<<": ";
		if(res>f)cout<<"BAD"<<endl;
		else cout<<"GOOD"<<endl;
	}
    return 0;
}
