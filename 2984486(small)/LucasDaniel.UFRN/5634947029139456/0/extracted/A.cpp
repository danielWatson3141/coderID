#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>	// srand( time(NULL) )
#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<climits>

using namespace std;

// Typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair< int, pair<int, int> > iii;
typedef vector<iii> viii;
typedef vector< vector<int> > vvi;
typedef vector< vector<ii> > vvii;
typedef vector< vector<iii> > vviii;

// Macros
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define FORR(i, a) for(int i = 0; i < a; ++i)
#define FORE(i, a, b) for(int i = a; i >= b; --i)
#define all(v) v.begin(), v.end()
#define sz(A) int((A).size())
#define CLR(x, a) memset(x, a, sizeof(x))
#define pb push_back
#define mp make_pair
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define LSOne(S) (S & (-S)) // bit menos significativo
#define first(x) x.first	// lidam com triplas
#define second(x) x.second.first
#define third(x) x.second.second

// Constantes
const double PI = 2*asin(1.0);
const int INF = 1000000000;	// 9 zeros
const double EPS = 1e-10;

// Matematica basica
inline int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1; }
inline ll gcd(ll n1, ll n2) {return n2==0? abs(n1) : gcd(n2,n1%n2);}	// MUDAR PARA O PKU!
inline ll lcm(ll n1, ll n2) {return n1==0||n2==0? 0 : abs(n1*(n2/gcd(n1,n2)));}	// MUDAR PARA O PKU!

map<string, int> mp1;
string v1[155], v2[155];
int main() {
	int t, n, l, res;
	string s;
	scanf("%d", &t);
	FOR(w, 1, t+1) {
		printf("Case #%d: ", w);
		scanf("%d %d", &n, &l);
		res = l+1;
		FORR(i, n) {
			cin >> v1[i];
		}
		FORR(i, n) {
			cin >> v2[i];
		}
		for(ll i = 0LL; i < (1LL<<ll(l)); ++i) {
			mp1.clear();
			FORR(j, n) {
				string aux = v1[j];
				FORR(k, l) {
					if(i & (1LL<<ll(k))) {aux[k] = (aux[k] == '0' ? '1' : '0');}
				}
				//cerr << "gerou " << aux << endl;
				mp1[aux]++;
			}
			//cerr << "bla\n";
			bool ok = true;
			FORR(j, n) {
				if((mp1[v2[j]]--) <= 0) {ok = false; break;}
			}
			if(ok) res = min(res, __builtin_popcount(i));
		}
		if(res == l+1) printf("NOT POSSIBLE\n");
		else printf("%d\n", res);
	}
}
