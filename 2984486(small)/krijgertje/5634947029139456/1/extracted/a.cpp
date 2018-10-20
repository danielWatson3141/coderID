#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  

int n,len;
char haves[150][41];
char wants[150][41];
ll have[150];
ll want[150];
ll res[150];



void run(int casenr) {
	scanf("%d%d",&n,&len);
	REP(i,n) { REP(j,len) scanf(" %c",&haves[i][j]); haves[i][len]='\0'; }
	REP(i,n) { REP(j,len) scanf(" %c",&wants[i][j]); wants[i][len]='\0'; }
	REP(i,n) { have[i]=0; REP(j,len) if(haves[i][j]=='1') have[i]|=1LL<<j; }
	REP(i,n) { want[i]=0; REP(j,len) if(wants[i][j]=='1') want[i]|=1LL<<j; }
	sort(want,want+n);

	int ret=INT_MAX;
	REP(i,n) {
		ll change=have[0]^want[i];
		REP(j,n) res[j]=have[j]^change;
		sort(res,res+n);
		bool ok=true; REP(j,n) if(res[j]!=want[j]) ok=false; if(!ok) continue;
		int cur=0; REP(j,len) if(change&(1LL<<j)) ++cur; if(cur<ret) ret=cur;
	}
	if(ret==INT_MAX) printf("Case #%d: NOT POSSIBLE\n",casenr); else printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
