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

int n;
int fst[1000];
int nxt[2000];
int to[2000];

int size[2000];
int getsize(int id,int at) {
	if(size[id]!=-1) return size[id];
	int ret=1;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(id!=(x^1)) ret+=getsize(x,to[x]);
	return size[id]=ret;
}

int full[2000];
int getfull(int id,int at) {
	if(id!=-1&&full[id]!=-1) return full[id];
	int sumsize=0;
	int best=INT_MAX,best2=INT_MAX;
	for(int x=fst[at];x!=-1;x=nxt[x]) if(id!=(x^1)) {
		int cursize=getsize(x,to[x]);
		int curfull=getfull(x,to[x]);
		sumsize+=cursize;
		int curval=curfull-cursize;
		if(curval<best) best2=best,best=curval; else if(curval<best2) best2=curval;
	}
	int ret=best==INT_MAX||best2==INT_MAX?sumsize:sumsize+best+best2;
	if(id!=-1) full[id]=ret;
	return ret;
}

void run(int casenr) {
	scanf("%d",&n);
	memset(fst,-1,sizeof(fst));
	REP(i,n-1) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		to[2*i+0]=b; nxt[2*i+0]=fst[a]; fst[a]=2*i+0;
		to[2*i+1]=a; nxt[2*i+1]=fst[b]; fst[b]=2*i+1;
	}

	memset(size,-1,sizeof(size));
	memset(full,-1,sizeof(full));
	int ret=n-1;
	REP(i,n) {
		int cur=getfull(-1,i);
		//printf("\t%d = %d\n",i,cur);
		if(cur<ret) ret=cur;
	}
	printf("Case #%d: %d\n",casenr,ret);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
