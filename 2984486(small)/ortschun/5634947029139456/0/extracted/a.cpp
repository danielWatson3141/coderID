#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
int N, L;
vector<string> p;
int main() {
	//freopen("a.in", "r", stdin); 
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small-attempt0.out", "w", stdout);
	//freopen("A-small-attempt1.in", "r", stdin); freopen("A-small-attempt1.out", "w", stdout);
	//freopen("A-small-attempt2.in", "r", stdin); freopen("A-small-attempt2.out", "w", stdout);
	//freopen("A-small-attempt3.in", "r", stdin); freopen("A-small-attempt3.out", "w", stdout);
	
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		p.clear();
		cin>>N>>L;
		vector<string> v;
		REP(i, N){
			string s; cin>>s;
			v.push_back(s);
		}
		REP(i, N){
			string s; cin>>s;
			p.push_back(s);
		}
		sort(ALL(p));
		int ret = INF;
		for(int mask = 0; mask < (1<<L); mask ++){
			vector<string> q = v;
			REP(j, L)if(mask & (1<<j)){
				for(int i = 0; i < N; i ++){
					if(v[i][j] == '0'){
						q[i][j] = '1';
					} else {
						q[i][j] = '0';
					}
				}
			}
			sort(ALL(q));
			if (p == q) {
				ret = min(ret, __builtin_popcount(mask));
			}
		}
		printf("Case #%d: ", t);
		if(ret == INF) {
			cout<<"NOT POSSIBLE"<<endl;
		} else {
			cout<<ret<<endl;
		}
		
	}
	return 0;
}
