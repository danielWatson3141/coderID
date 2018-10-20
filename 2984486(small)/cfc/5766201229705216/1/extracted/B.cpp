#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <string.h>
#include <cstring>
#define oo (int)1e9
#define fill( a , v ) memset( a , v , sizeof (a) )
#define bits( x ) __builtin_popcount( x )
#define gcd( a , b ) __gcd( a, b )
#define lcm( a , b ) (a/gcd( a, b ) ) * b
#define s(n)scanf( "%d" , &n )
#define add push_back
const int mxn = 1024 + 10;
typedef long long ll;
#define pii pair<double,double>
using namespace std;

int cs, T;
int N,L;
vector<int> a[mxn];

int vis[mxn][mxn];
int id;
int dp[mxn][mxn];

int solve(int pos,int parent) {


	int &v = vis[pos+1][parent+1];
	int &d = dp[pos+1][parent+1];
	if(v == id)return d;
	v = id;

	d = 0;

	int count = 1;
	int firstMax = -1;
	int secondMax = -1;
	for(int i=0;i<a[pos].size();i++) {

		if(parent != a[pos][i]) {
			int r = solve(a[pos][i], pos);
			if(firstMax == -1) {
				firstMax = r;
			}
			else if(secondMax == -1) {
				if(firstMax < r) {
					secondMax = firstMax;
					firstMax = r;
				}
				else
					secondMax = r;
			}
			else {
				if(firstMax < r) {
					secondMax = firstMax;
					firstMax = r;
				}
				else if (secondMax < r)
					secondMax = r;
			}
		}
	}

	if(firstMax != -1 && secondMax != -1) {
		count += firstMax + secondMax;
	}

	return d = count % 2 == 1 ? count : 0;

}

int main() {

	s(T);

	while(T--) {
		++id;
		for(int i=0;i<mxn;i++) a[i].clear();
		cin >> N;
		int A,B;
		for(int i=0;i<N-1;i++) {
			cin >> A >> B;
			A--;B--;
			a[A].add(B);
			a[B].add(A);
		}
		int res = oo;
		for(int i=0;i<N;i++) {
			int ans = N - solve(i, -1);
			res = min(res, ans);
		}
		printf("Case #%d: %d\n", ++cs, res);
	}
}