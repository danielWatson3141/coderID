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

double prob[1000][2][1000];

int main(void) {
	int T;
	cin >> T;

	int N = 1000;

	int w;
	fu(l,0,N) {
		cerr << l << endl;
		w=0;
		fu(i,0,N) prob[l][w][i] = (i==l);
		fu(i,0,N) {
			prob[l][1-w][i]=0;
			fu(j,0,N) prob[l][1-w][i] += (prob[l][w][j]/N);
			fu(j,0,N) if(j!=i) prob[l][1-w][j] = prob[l][w][j] * (N-1.) / N + prob[l][w][i] / N;
			w=1-w;
			//fu(j,0,N) cout << prob[w][j] << " "; cout << endl;
		}
	}
	w=1-w;

	for(int ts=1; ts<=T; ts++) {
		int N;
		cin >> N;
		vector<int> v(N);
		fu(i,0,N) cin >> v[i];
		double score=1;
		fu(i,0,N) score *= prob[v[i]][w][i] * N;
		cerr << "Case #" << ts << ": " << score << endl;
		cout << "Case #" << ts << ": " << (score>1 ? "BAD" : "GOOD") << endl;
	}
}
