/*
	Author: Shivang Gupta
	GCJ_1A_2014

*/
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <deque>
#include <sstream>
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <cstring>
#include <climits>
#include <map>
#include <cassert>
#define mod 1000000007
#define PHI 1000000006
#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(i=(a);i<(n);++i)
#define FD(i,a,n) for(i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define VI vector <int>
#define VII vector < vector <int> >
#define S1(x) scanf("%llu",&x)
#define MAX 100009
#define LOGMAXN 20
#define EPS 0.000001
using namespace std;
 
int n;
vector <int> _a,_b;
vector < vector <int> > s;
vector <bool> dp;
vector <int> down;
int ddd[1009][3];
 
int fun (int index, int x)
{
if (x == 3) {
return 10000;
}
if (index == _a.size()) {
if (x == 1) {
return 10000;
}
return 0;
}
 
int &result = ddd[index][x];
if (result != -1) {
return result;
}
result = fun (index+1, x) + _b[index];
result = min (result, _a[index]+fun(index+1, x+1));
return result;
}
 
int cal (vector <int> s, vector <int> a)
{
_a = s;
_b = a;
if (s.size() == 0) {
return 0;
}
if (s.size() == 1) {
return a[0];
}
memset (ddd, -1, sizeof(ddd));
return fun (0, 0);
}
 
int f (int x, int p)
{
vector <int> _a;
vector <int> _b;
int i,sum=0;
F (i, 0, s[x].size()) {
int xx = s[x][i];
if (xx == p) {
continue;
}
int xxx = f (xx, x);
_a.pb (xxx);
_b.pb (down[xx]);
}
return cal (_a, _b);
}
 
int ff (int x, int p)
{
down[x] = 1;
int i,sum=0;
F (i, 0, s[x].size()) {
int xx = s[x][i];
if (xx == p) {
continue;
}
ff (xx, x);
down[x] += down[xx];
}
}
 
int main()
{
 
int t;
S (t);
int ii = 1;
while (t--) {
cout << "Case #" << ii++<< ": ";
 
cin >> n;
s.clear(); s.resize (n);
int sum = n;
for (int i = 0; i < n-1; i++) {
int x,y;
cin >> x >> y;
x--;
y--;
s[x].pb (y);
s[y].pb (x);
}
 
 
for (int j = 0; j < n; j++) {
dp.resize (n);
down.resize (n);
for (int ii = 0; ii < dp.size(); ii++) {
dp[ii] = false;
down[ii] = 0;
}
ff (j, j);
sum = min (sum, f(j, j));
}
cout << sum << endl;
}
return 0;
}