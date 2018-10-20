#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

const int INF=1000000;
int N;
vector< vector<int> > E;

int size(int i, int j) {
	//cout << "size " << i << " " << j << endl;
	int ret=1;
	fa(k,E[j]) if(*k != i) ret += size(j, *k);
	return ret;
}

int cost(int i, int j) {
	vector<int> costs;
	//cout << "cost " << i << " " << j << endl;
	int best=0;
	fa(k,E[j]) if(*k != i) best += size(j, *k);
	fa(k,E[j]) if(*k != i) costs.push_back( cost(j, *k) - size(j, *k) );
	sort(costs.begin(), costs.end());
	if(costs.size()>=2) {
		best = best + costs[0] + costs[1];
	}
	return best;
}

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
		cin >> N;
		E=vector<vector<int> >(N+1);
		fu(i,1,N) {
			int j,k; cin >> j >> k;
			E[k].push_back(j);
			E[j].push_back(k);
		}
		int best=INF;
		fu(i,1,N+1) {
			best = min(best, cost(0,i));
		}
		cout << best << endl;
	}
}
