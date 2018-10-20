#include <algorithm>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

void good(vector<int>& v) {
	int n = v.size();
	REP(i,n) v[i] = i;
	REP(i,n) swap(v[i], v[i+rand()%(n-i)]);
}

void bad(vector<int>& v) {
	int n = v.size();
	REP(i,n) v[i] = i;
	REP(i,n) swap(v[i], v[rand()%n]);
}

int freq[1000][100];
int fsum = 0;

double assumeBad(const vector<int>& v) {
	int n = v.size();
	double p = 1;
	REP(i,n) {
		double pp = (double)freq[i][v[i]/10]*100 / fsum;
		p *= pp;
	}
	return p;
}

int main() {
	vector<int> v;
	REP(i,1000) v.push_back(i);

	REP(k,100000) {
		bad(v);
		REP(i,1000) ++freq[i][v[i]/10];
		++fsum;
	}

	int x;
	scanf("%d", &x);
	assert(x == 120);

	REP(t,120) {
		printf("Case #%d: ", t+1);
		v.clear();
		scanf("%d", &x);
		assert(x == 1000);
		REP(i,1000) {
			scanf("%d", &x);
			v.push_back(x);
		}
		double p = assumeBad(v);
		DEBUG(p);
		if (p >= 1) {
			printf("BAD\n");
		} else {
			printf("GOOD\n");
		}
	}

	return 0;
}
