///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>
#include<assert.h>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

int n,l;
string s[155];
string t[155];

string x[155];

void fillTable(int k){
	forn(i,n)
		x[i] = s[i];
	forn(i,n){///lleno x[i]
		forn(j,l){///me fijo quien es x[i][j]
			x[i][j] = t[k][j] xor s[0][j] xor s[i][j];
		}
	}
/*cerr << k << endl;
forn(i,n){
	cerr << x[i] << endl;
} cerr << endl;*/
}

bool asignar(){
	///tengo la tabla armada y tengo que asignar
	vector<bool> done(n,false);
	forn(p,n){
		///trato de encontrarle un lugar a t[p]
		bool found = false;
		forn(i,n) if(!done[i]){
			///es x[i] un lugar posible?
			if(t[p] == x[i]){
				///si, es un lugar!
				done[i] = true;
				found = true;
//cerr << "t[" << p << "] => " << "x[" << i << "]" << endl;
				break;
			}
		}
		if(!found)/// no pude matchear t[p]
			return false;
	}
	return true;
}

int main(){
freopen("ALarge.in","r",stdin);
freopen("ALarge.out","w",stdout);
	int TC; cin >> TC;
	for(int tc = 1; tc <= TC; tc++){
		cin >> n >> l;
		forn(i,n)
			cin >> s[i];
		forn(i,n)
			cin >> t[i];
		int res = 1000000;
		forn(k,n){///veo si asignandole t[k] a s[0] puedo
			fillTable(k);///armo la tabla
			if(asignar()){
				///actualizo res
				int newRes = 0;
				forn(j,l)
					if(t[k][j] != s[0][j])
						newRes++;
				res = min(res,newRes);
			}
		}
		cout << "Case #" << tc << ": ";
		if(res == 1000000)
			cout << "NOT POSSIBLE" << endl;
		else
			cout << res << endl;
	}
    return 0;
}
