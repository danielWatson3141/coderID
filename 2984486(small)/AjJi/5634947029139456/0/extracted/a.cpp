#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(int)(b);i++)
#define REP(i,a) for(int i=0;i<(int)(a);i++)
#define ALL(i) i.begin(),i.end()
#define rALL(i) i.rbegin(),i.rend()
#define PB push_back

typedef vector<int> vi;
typedef vector<vector<int> > vvi;

template<class T> string i2a(T x) {ostringstream oss; oss<<x; return oss.str();}

void printvec(vector<int> a)
{
 cout<<"vec:  ";
 REP(i,a.size()) cout<<a[i]<<"  ";
 cout<<endl;
}

vector<int> diff(string a, string b) {
	vector<int> d;
	REP(i, a.size()) if(a[i] != b[i]) d.PB(i);

	return d;
}

int common(vector< vector<int> > a) {
	vector<int> in = a[0];
	int best = 1000000;
	REP(i, in.size()) {
		int c = 1;
		for(int j = 1; j < (int)a.size(); j++) {
			for(int k = 0; k < (int)a[i].size(); k++) {
				if(in[i] == a[j][k]) {
					c++;
					break;
				}
			}
		}
		if(c == (int)a.size()) best = min(best, __builtin_popcount(in[i]));
	}
	return best;
}


int todec(string s) {
	int d = 0, p = 1;
	for(int i = s.size() - 1; i >= 0; i--) {
		d += (s[i]-'0') * p;
		p *= 2;
	}
	return d;
}
int main()
{

   freopen("A-small-attempt2.in", "r", stdin);
   freopen("A-small-attempt2.out", "w", stdout);

	int cases;
	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d",&cases);
	REP(k, cases) {
		printf("Case #%d: ", k + 1);
		getline(cin,s);
		int n, l;
		sscanf(s.c_str(),"%d %d", &n, &l);
		vector<int> flows, devices;
		getline(cin, s);
		stringstream st;
		st<<s;
		string tmp;
		while(st>>tmp) flows.PB(todec(tmp));
		getline(cin, s);
		stringstream st2;
		st2<<s;
		while(st2>>tmp) devices.PB(todec(tmp));
		int best = 10000000;

		vector< vector<int> > diffs;
		REP(i,flows.size()) {
			vector<int> diff;
			REP(j, devices.size()) {
				diff.PB(flows[i] ^ devices[j]);
			}
			diffs.PB(diff);
		}

		//REP(i, diffs.size()) printvec(diffs[i]);


		int cc = common(diffs);

		if(cc == 1000000) printf("NOT POSSIBLE\n");
		else printf("%d\n", cc);
	}
    return 0;
}
