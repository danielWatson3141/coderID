#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N, L;
string a[155], b[155];
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		printf("Case #%d: ", csn);
		cin >> N >> L;
		REP(i,0,N) cin >> a[i];
		sort(a, a+N);
		REP(i,0,N) cin >> b[i];

		int ans = 0;
		REP(j,0,L){
			sort(b, b+N);
			int ca = 0, cb = 0;
			REP(i,0,N) ca += a[i][j]=='1';
			REP(i,0,N) cb += b[i][j]=='1';
			if(ca==cb){
				if(!(N%2==0 && ca==N/2)){
					REP(i,0,N){
						if(a[i][j]!=b[i][j]){
							ans = -1;
							break;
						}
					}
				}else{
					REP(i,0,N){
						if(a[i][j]!=b[i][j]){
							ans ++;
							REP(i,0,N) b[i][j] = (1-(b[i][j]-'0'))+'0';
							sort(b, b+N);
							break;
						}
					}
					REP(i,0,N){
						if(a[i][j]!=b[i][j]){
							ans = -1;
							break;
						}
					}
				}
			}else{
				ans++;
				REP(i,0,N) b[i][j] = (1-(b[i][j]-'0'))+'0';
				sort(b, b+N);
				REP(i,0,N){
					if(a[i][j]!=b[i][j]){
						ans = -1;
						break;
					}
				}
			}
			if(ans==-1) break;
		}
		if(ans==-1) puts("NOT POSSIBLE");
		else printf("%d\n", ans);
	}
	return 0;
}