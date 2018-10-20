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

const tint INF=2000000000;


int main(){
	freopen("CJ1.out","w",stdout);
	int T;
	cin>>T;
	forn(caso,T){
		int res=10000;
		int n,l;cin>>n>>l;
		vector < vector<int> > tab;
		vector < vector<int> > lis;
		vector <int> aux (l);
		int z;
		forn(i,n){
			tab.pb(aux);
			cin>>z;
			forn(j,l){
				tab[i][j]=z%10;
				z/=10;
			}
		}
		forn(i,n){
			lis.pb(aux);
			cin>>z;
			forn(j,l){
				lis[i][j]=z%10;
				z/=10;
			}
		}
		vector <int> p = lis[n-1];
		lis.pop_back();
		sort(all(lis));
		vector < vector<int> > ctab;
		forn(i,n){
			ctab.clear();
			forn(j,n)if(i!=j)ctab.pb(tab[j]);
			vector <int> q=tab[i];
			int cont=0;
			forn(k,l){
				if(q[k]!=p[k]){
					cont++;
					fore(j,ctab)ctab[j][k]=1-ctab[j][k];
				}
			}
			sort(all(ctab));
			if(ctab==lis) res=min(cont,res);
		}
		cout<<"Case #"<<1+caso<<": ";
		if(res==10000) cout<<"NOT POSSIBLE";
		else cout<<res;
		cout<<endl;		
	}	
    return 0;
}
