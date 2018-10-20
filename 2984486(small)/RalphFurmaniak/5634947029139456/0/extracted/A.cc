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

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
		int N,L;
		cin >> N >> L;
		vector< string > plugs(N), devices(N);
		fu(i,0,N) {
			string s;
			cin >> s;
			plugs[i] = s;
		}
		fu(i,0,N) {
			string s;
			cin >> s;
			devices[i] = s;
		}
		sort(devices.begin(), devices.end());
		const int INF=1000000000;
		int best=INF;
		fu(i,0,N) {
			string swit(L,0);
			fu(j,0,L) swit[j] = (plugs[0][j] == devices[i][j] ? '0' : '1');
			int cur = count(swit.begin(),swit.end(),'1');
			vector<string > plugs2(N, string(L,0));
			fu(j,0,N) fu(k,0,L) plugs2[j][k] = (swit[k]=='1' ? '0'+'1'-plugs[j][k] : plugs[j][k]);
			sort(plugs2.begin(),plugs2.end());
			fu(i,0,N) if(devices[i] != plugs2[i]) cur=INF;
			best = min(best, cur);
		}
		if(best < INF) cout << best << endl;
		else cout << "NOT POSSIBLE" << endl;
        }
}
