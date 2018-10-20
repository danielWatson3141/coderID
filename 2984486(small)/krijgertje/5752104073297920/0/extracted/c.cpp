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

double f[1000][1000];

int perm[1000];

int n=1000;
double pme,pother;


double calc(int from,int to) {
	return pme*pow(pother,n-to-1)+pow(pother,from)*f[from][to];
//	if(from>to) return pow(pother,n-1)*pme+pme*pow(pother,n-to-1);
//	if(to>=from) return pme*pow(pother,n-to-1)+(n-to-1)*pow(pother,n-2)*pme*pme;
}

void getrandperm() {
	REP(i,n) perm[i]=i;
	REP(i,n) { int j=i+rand()%(n-i); swap(perm[i],perm[j]); }
}

void getskewperm() {
	REP(i,n) perm[i]=i;
	REP(i,n) { int j=rand()%n; swap(perm[i],perm[j]); }
}

void run(int casenr) {
	int n; scanf("%d",&n); REP(i,n) scanf("%d",&perm[i]);
	//if(casenr%2==0) getrandperm(); else getskewperm();
	double ret=1;
	REP(i,n) {
		double cur=calc(perm[i],i)*n;
		//printf("\t%lf\n",cur);
		ret*=cur;
	}
	fprintf(stderr,"%lf\n",ret);
	printf("Case #%d: %s\n",casenr,ret>1?"BAD":"GOOD");
}



void precalc() {
	pme=1.0/n,pother=1.0*(n-1)/n;
	for(int i=n-1;i>=0;--i) REP(j,n) {
		f[i][j]=0;
		if(i>j) f[i][j]+=pme*pow(pother,n-i-1);
		double mult=1;
		FOR(k,i+1,n) { f[i][j]+=pme*mult*f[k][j]; mult*=pother; }
	}
	//REP(i,n) REP(j,n) printf("%d->%d = %lf\n",i,j,calc(i,j));
}

int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run(i);
	return 0;
}
