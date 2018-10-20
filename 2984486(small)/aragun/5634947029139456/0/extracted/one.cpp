/*  
    f1zz0_13
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctype.h>
#include <stack>
#include <queue>
#include <limits.h>
#include <fstream>
#include <map>
#include <set>

#define rep(i, a) for(int i = 0; i < a; i++)
#define fo(i, a, b) for(int i = a; i < b; i++)
#define defo(i, a, b) for(int i = a; i >= b; i--)
#define ll long long
#define pb  push_back
#define mp  make_pair
#define sz(a)   ((int)(a.size()))
#define x first
#define y second
#define SET(x, a) memset(x, a, sizeof(x));

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

inline bool isSet (int n, int pos) {
	return n & (1 << pos);
}

int main() {
	ifstream fin ("A-small-attempt0.in");
	ofstream fout ("a.txt");

 	int t, n, l;
 	fin >> t;
 	rep (z, t) {
 		fin >> n >> l;
 		vs outlet, device;
 		string foo;
 		rep(i, n) {
 			fin >> foo;
 			outlet.pb(foo);
 		}
 		rep(i, n) {
 			fin >> foo;
 			device.pb(foo);
 		}
 		sort (device.begin(), device.end());
 		int minS = 11;
 		rep (i, 1 << l) {
 			int sw = 0;
 			vs foo = outlet;
 			rep (j, l)
 				if (isSet(i, j)) {
 					sw++;
 					rep (k, n)
 						foo[k][j] = foo[k][j] == '1' ? '0' : '1';
 				}
 			sort (foo.begin(), foo.end());
 			int pos = 1;
 			rep (j, n)
 				if (device[j].compare(foo[j]))
 					pos = 0;
 			if (pos)
 				minS = min(minS, sw);
 		}
 		if (minS == 11)
 			fout << "Case #" << z+1 << ": NOT POSSIBLE\n";
 		else 
 			fout << "Case #" << z+1 << ": " << minS << "\n";
 	}
	return 0;
}