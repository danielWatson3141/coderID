#include <iostream>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define DBG 0
#define name "A-large"
#define DB(a) #a " == " << (a) << ";	"
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define lli long long int
#define ulli unsigned lli

namespace solution{
	const int NMAX = 40;

	//vector < vector < bitset<NMAX> > > m;
	vector < ulli > a,b;
	map <ulli, int> c;
	set <ulli> s;
	ulli x;
	int N;

	void read(){
		cin >> N; int l; cin >> l; cerr << endl;
		a.clear(), b.clear();//, m.clear(); 
		a.resize(N), b.resize(N);//, m.resize(N);
		
		bitset <NMAX> buf;
		FOR(i,0,N) cin >> buf, a[i] = buf.to_ullong();//, cerr << " " << a[i]; cerr << endl;
		FOR(i,0,N) cin >> buf, b[i] = buf.to_ullong();//, cerr << " " << b[i]; cerr << endl;
		//sort(a.begin(), a.end()), sort(b.begin(), b.end());
		c.clear(), s.clear();
	}

	int solve(){
		int best = 41;
		read();
		FOR(i,0,N) FOR(o,0,N) x = a[i]^b[o], ++c[x], s.insert(x);

		for (auto it = s.begin(); it != s.end(); ++it)
			if (c[*it] == N)
				if (bitset<NMAX>(*it).count() < best) best = bitset<NMAX>(*it).count();
		return (best == 41 ? -1 : best);
	}


}


int main(){
	if (DBG <= 2) freopen(name".in","r",stdin);
	if (DBG <= 1) freopen(name".out","w",stdout);

	int T;
	cin >> T;
	FOR(t,0,T){
		printf("Case #%d: ", t+1);
		int ans = solution::solve();
		if (ans == -1)
			printf("NOT POSSIBLE\n");
		else
			printf("%d\n", ans);
	}













esc:
#if DBG // == 0
	if (DBG <= 2) freopen("CON","r",stdin);
	if (DBG <= 1) freopen("CON","w",stdout);
	system("pause");
#endif
	return 0;
}
