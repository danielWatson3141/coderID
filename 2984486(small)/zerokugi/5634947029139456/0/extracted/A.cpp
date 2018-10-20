#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef pair<int, int> pii;
typedef long long int ll;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)

int T, n;

bool check(vector<int> flow, vector<int> &dev, int change){
	REP(i, flow.size()) flow[i] ^= change;
	sort(flow.begin(), flow.end());
	return flow == dev;
}

main(){
	cin >> T;
	REP(t, T){
		int N, L;
		string s;
		cin >> N >> L;
		vector<int> flow(N), dev(N), cand(N);
		REP(i, N){
			cin >> s;
			REP(j, s.size()) flow[i] = flow[i]*2 + (s[j] == '1');
		}
		REP(i, N){
			cin >> s;
			REP(j, s.size()) dev[i] = dev[i]*2 + (s[j] == '1');
			cand[i] = flow[0] ^ dev[i];
		}
		sort(dev.begin(), dev.end());
		sort(flow.begin(), flow.end());
		
		int ans = 100;
		REP(i, N) if(check(flow, dev, cand[i])) ans = min(ans, __builtin_popcount(cand[i]));
		
		printf("Case #%d: ", t+1);
		if(ans == 100) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}
