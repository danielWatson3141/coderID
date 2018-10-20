//label : work
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

const int N = 233;
const int L = 233;
const int MD = 1000000007;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1E-6;

int n, len;
int a[N][L];
int b[N][L];
int pre[N];
int id[N];
bool filp[L];

bool cmp_b(int x, int y){
	rep(i, len){
		if (b[x][i] < b[y][i]) return true;
		if (b[x][i] > b[y][i]) return false;
	}
	return true;
}

bool cmp(int x, int y){
	rep(i, len){
		if ((a[x][i] ^ filp[i]) < (a[y][i] ^ filp[i])) return true;
		if ((a[x][i] ^ filp[i]) > (a[y][i] ^ filp[i])) return false;
	}
	return true;
}

bool check(){
	rep(i, n){
		id[i] = i;
	}
	sort(id, id + n, cmp);
	rep(i, n){
		rep(j, len){
			if ((a[id[i]][j] ^ filp[j]) != b[pre[i]][j]) return false;
		}
	}
	return true;
}

int main(){
	int T;
	scanf("%d", &T);
	rep(cas, T){
		scanf("%d%d", &n, &len);
		rep(i, n){
			rep(j, len){
				char ch;
				while((ch = getchar()) && ch != '0' && ch != '1');
				a[i][j] = ch - '0';
			}
		}
		rep(i, n){
			rep(j, len){
				char ch;
				while((ch = getchar()) && ch != '0' && ch != '1');
				b[i][j] = ch - '0';
			}
			pre[i] = i;
		}
		sort(pre, pre + n, cmp_b);
		int ans = INF;
		rep(i, n){
			rep(j, n){
				int cnt = 0;
				rep(k, len){
					filp[k] = (a[i][k] != b[j][k]);
					cnt += filp[k];
				}
				if (cnt < ans && check()) ans = cnt;
			}
		}
		printf("Case #%d: ", cas + 1);
		if (ans == INF){
			puts("NOT POSSIBLE");
		}
		else{
			printf("%d\n", ans);
		}
	}
	return 0;
}
