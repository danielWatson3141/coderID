//label : math
//By myf
//#pragma comment(linker, "/STACK:16777216")  //C++
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <bitset>
#include <stack>
#include <complex>
#include <list>
#include <iomanip>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define REP(i, l, r) for(int i = (l) ; i < (r); i++)
#define MP make_pair
#define PB push_back
#define Cls(x) memset(x,0,sizeof x)
#define Print(n,x) for(int i=0;i<(n);i++) cout<<x<<" ";cout<<endl;
#define foreach(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++) //G++
#define F first
#define S second
#define X real()
#define Y imag()
#define Sqr(x) (x)*(x)
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef long long LL;
typedef complex<double> Point;
typedef Point Vec;
typedef pair<Point, Point> Line;
//typedef complex<double> Comp;

const int N = 1001;
const int T = 100000;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-12;

int n, p;
int v[N];
int pa[N][N], pb[N][N];

double ret;

int rand(int a, int b){
	return a + rand() % (b - a + 1);
}

int main(){
	srand(time(NULL));
	n = 1000;
	rep(i, T){
		rep(j, n){
			v[j] = j;
		}
		rep(j, n){
			p = rand(j, n - 1);
			swap(v[j], v[p]);
		}
		rep(j, n){
			pa[v[j]][j]++;
		}
	}
	rep(i, T){
		rep(j, n){
			v[j] = j;
		}
		rep(j, n){
			p = rand(0, n - 1);
			swap(v[j], v[p]);
		}
		rep(j, n){
			pb[v[j]][j]++;
		}
	}
	int test;
	scanf("%d", &test);
	rep(cas, test){
		scanf("%d", &n);
		double a, b, ans;
		a = b = ans = 1;
		rep(i, n){
			scanf("%d", &v[i]);
			ans *= pa[v[i]][i] * 1.0 / pb[v[i]][i];
			a *= pa[v[i]][i] * 1.0 / T;
			b *= pb[v[i]][i] * 1.0 / T;
		}
		printf("Case #%d: ", cas + 1);
		if (sign(ans - 1) >= 0) puts("GOOD");
		else puts("BAD");
	}
	return 0;
}
