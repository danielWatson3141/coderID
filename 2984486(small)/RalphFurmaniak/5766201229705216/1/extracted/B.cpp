#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

const int INF=1000000;
const int BIG=10000;
int N;
vector< vector<int> > E;

map<int, int> dp_size;
map<int, int> dp_cost;

int size(int i, int j) {
	//cout << "size " << i << " " << j << endl;
	int& ret=dp_size[i*BIG+j];
	if(ret) return ret;
	ret=1;
	fa(k,E[j]) if(*k != i) ret += size(j, *k);
	return ret;
}

int cost(int i, int j) {
	vector<int> costs;
	//cout << "cost " << i << " " << j << endl;
	int& best=dp_cost[i*BIG+j];
	if(best) return best;
	best=0;
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
		dp_size.clear();
		dp_cost.clear();
		if(N>2000) {
			fu(i,2,N+1) {
				E[i].push_back(i/2);
				E[i/2].push_back(i);
			}
		} else if(N==2000) {
			fu(i,1,N) {
				E[i].push_back(i+1);
				E[i+1].push_back(i);
			}
		} else {
			fu(i,1,N) {
				int j,k; cin >> j >> k;
				E[k].push_back(j);
				E[j].push_back(k);
			}
		}
		int best=INF;
		fu(i,1,N+1) {
			best = min(best, cost(0,i));
		}
		//fu(i,1,N+1) if(cost(0,i)==best) cout << "*" << i << endl;
		cout << best << endl;
	}
}
