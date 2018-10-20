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
#define MAXN 1005

int n = 1000, m= 50000;
int a[MAXN][MAXN];
int b[MAXN][MAXN];
int c[MAXN][MAXN];
double pa[MAXN][MAXN], pb[MAXN][MAXN], pc[MAXN][MAXN];

int x[MAXN];

void r1(){
	REP(i,1,n+1) x[i] = i;
	REP(i,1,n+1){
		int t = rand()%(n+1-i)+i;
		swap(x[i], x[t]);
	}
}
void r2(){
	REP(i,1,n+1) x[i] = i;
	REP(i,1,n+1){
		int t = rand()%n+1;
		swap(x[i], x[t]);
	}
}
int main(){
	REP(i,0,m){
		r1();
		REP(i,1,n+1) {
			a[i][x[i]]++;
			c[i][x[i]]++;
		}
		r2();
		REP(i,1,n+1) {
			b[i][x[i]]++;
			c[i][x[i]]++;
		}
	}
	REP(i,1,n+1){
		REP(j,1,n+1){
			pa[i][j] = (double)a[i][j]/m;
			pb[i][j] = (double)b[i][j]/m;
			pc[i][j] = (pa[i][j] + pb[i][j])*0.5;
			//printf("[%d] is %d: %.5f %.5f\n", i,j, (double)a[i][j]/m, (double)b[i][j]/m); 
		}
	}
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		printf("Case #%d: ", csn);
		int N;
		cin >> N;
		double P = 0.0;
		double Pa = 1.0, Pb = 1.0;
		double Pmax = 0, Pmin = 1.0;	
		REP(i,1,N+1){
			scanf("%d", x+i);
			x[i]++;
			Pa *= pa[i][x[i]];
			Pb *= pb[i][x[i]];
			if(Pa<1E-3 || Pb<1E-3){
				Pa *= 1000;
				Pb *= 1000;
			}
			double p = Pb/(Pa+Pb);
			Pmax = max(Pmax, p);
			Pmin = min(Pmin, p);

		}
		//cerr << Pa << " " << Pb << endl;
		P = Pb / (Pa+Pb);
		cerr << P << endl;
		//cerr << P << " " << Pmax << " " << Pmin << endl;
		if(P>=0.5) puts("BAD");
		else puts("GOOD");

	}
	return 0;
}